{
  stdenv,
  gnumake,
  pkg-config,
  ...
}:

stdenv.mkDerivation {
  name = "nemu-am-env";
  # strictDeps = true;
  # 
  nativeBuildInput = [
    pkg-config
    # gnumake
  ];
}
