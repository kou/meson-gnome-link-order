project('gnome-link-order-dep', 'c')

meson_sample_dep_sources = ['meson-sample-dep.c']
meson_sample_dep_headers = ['meson-sample-dep.h']
meson_sample_dep_lib = shared_library(
  'meson_sample_dep',
  sources : meson_sample_dep_sources + meson_sample_dep_headers,
  install : true,
)
install_headers(meson_sample_dep_headers)

pkgconfig = import('pkgconfig')
pkgconfig.generate(
  meson_sample_dep_lib,
  filebase : 'meson-sample-dep',
  name : 'Meson Sample dependency',
  version : '1.0',
)
