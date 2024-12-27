{
  mkShell,
  gnumake,
  bison,
  flex,
  ncurses,
  readline,
  libllvm,
  pkg-config,
  python3,
  ...
}:

# all native dependencies
# nemu:
#   bison, flex, ncurses, gnumake -> native binary
# am:
#   pkg-config, gnumake -> riscv32-none
# openperf:
#   pkg-config, gnumake -> riscv32-none

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
    readline
    libllvm
    (python3.withPackages (
      ps: with ps; [
        tqdm
        pyyaml
      ]
    ))
  ];
}
