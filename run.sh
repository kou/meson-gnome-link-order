#!/bin/bash

set -xue

prefix="${PWD}/install"
rm -rf "${prefix}"
pkg_config_path="${prefix}/lib/pkgconfig"
export PKG_CONFIG_PATH="${pkg_config_path}:${PKG_CONFIG_PATH}"

# First
cd lib-dep
cp -f meson-sample-dep{-before,}.c
cp -f meson-sample-dep{-before,}.h
rm -rf build
${MESON:-meson} build --prefix="${prefix}" --libdir=lib
ninja -C build -v all install
cd -

cd lib
cp -f meson-sample-before.c src/meson-sample.c
cp -f meson-sample-before.h src/meson-sample.h
rm -rf build
${MESON:-meson} build --prefix="${prefix}" --libdir=lib
ninja -C build -v all meson_sample-doc
ninja -C build -v install
cd -


# Second
cd lib-dep
cp -f meson-sample-dep{-after,}.c
cp -f meson-sample-dep{-after,}.h
rm -rf build
${MESON:-meson} build --prefix="${prefix}" --libdir=lib
ninja -C build -v all install
cd -

cd lib
cp -f meson-sample-after.c src/meson-sample.c
cp -f meson-sample-after.h src/meson-sample.h
rm -rf build
${MESON:-meson} build --prefix="${prefix}" --libdir=lib
ninja -C build -v all meson_sample-doc
ninja -C build -v install
ninja -C build -v test
cd -
