{ nixpkgs ? import <nixpkgs> {  } }:

let
    pkgs = [
        nixpkgs.cmake
    ];

in
    nixpkgs.stdenv.mkDerivation {
        name = "mdmfp2latex";
        buildInputs = pkgs;
    }
