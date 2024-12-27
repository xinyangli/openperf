{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs =
    { self, nixpkgs, ... }:
    let
      # Local and cross package sets:
      # pkgs: local, used for native
      # rv32CrossPkgs: local -> rv32CrossPkgs
      # rv32LLVMCrossPkgs: local -> rv32CrossPkgs, but use llvm instead of gnu
      pkgs = import nixpkgs { system = "x86_64-linux"; };
      patchGccStdenv =
        pkgs: stdenv:
        pkgs.overrideCC stdenv (
          pkgs.wrapCC (
            stdenv.cc.cc.overrideAttrs (final: prev: { patches = prev.patches ++ [ ./fix-gcc-ice.patch ]; })
          )
        );
      crossSystem = {
        config = "riscv32-none-none-elf";
        gcc = {
          arch = "rv32im_zicsr";
        };
      };
      localSystem = "x86_64-linux";
      rv32CrossPkgs = import nixpkgs {
        inherit localSystem crossSystem;
        allowUnsupportedSystem = true;
      };
      rv32LLVMCrossPkgs = import nixpkgs {
        inherit localSystem;
        crossSystem = crossSystem // {
          useLLVM = true;
        };
      };

      # all native dependencies
      # nemu:
      #   bison, flex, ncurses, gnumake -> native binary
      # am:
      #   pkg-config, gnumake -> riscv32-none
      # openperf:
      #   pkg-config, gnumake -> riscv32-none
      nemu-env =
        {
          mkShell,
          gnumake,
          bison,
          flex,
          ncurses,
          readline,
          libllvm,
          pkg-config,
          SDL2,
          ...
        }:
        mkShell {
          strictDeps = true;
          nativeBuildInputs = [
            pkg-config
            gnumake
            bison
            flex
            ncurses
          ];
          buildInputs = [
            SDL2
            readline
            libllvm
          ];
        };
      am-nemu-env =
        {
          mkShell,
          gnumake,
          pkg-config,
          python3,
          ...
        }:
        mkShell {
          name = "nemu-am-env";

          nativeBuildInputs = [
            (python3.pythonOnBuildForHost.withPackages (
              ps: with ps; [
                tqdm
                pyyaml
              ]
            ))
            pkg-config
            gnumake
          ];
        };
    in
    {
      devShells.x86_64-linux = {
        riscv32-nemu = rv32CrossPkgs.callPackage am-nemu-env { };
        riscv32-nemu-clang = rv32LLVMCrossPkgs.callPackage am-nemu-env { };
        nemu = pkgs.callPackage nemu-env { };

        native =
          pkgs.mkShell.override
            {
              stdenv = patchGccStdenv pkgs pkgs.stdenv;
            }
            {
              name = "openperf";
              nativeBuildInputs = [
                pkgs.pkg-config
              ];
              buildInputs = with pkgs; [
                SDL2
                gnumake
                (python3.withPackages (ps: with ps; [ tqdm pyyaml ] ))
              ];
            };
      };
      passthru = {
        inherit rv32CrossPkgs rv32LLVMCrossPkgs;
      };
    };
}
