meson_sample_dep = dependency('meson-sample-dep')

gnome = import('gnome')

meson_sample_sources = ['meson-sample.c', 'meson-sample.h']
meson_sample_dependencies = [gobject, meson_sample_dep]
libmeson_sample = library(
  'meson_sample',
  sources : meson_sample_sources,
  dependencies : meson_sample_dependencies,
  install : true,
)
meson_sample = declare_dependency(link_with : libmeson_sample,
				  dependencies : meson_sample_dependencies)

gnome.generate_gir(
  libmeson_sample,
  sources : meson_sample_sources,
  nsversion : '1.0',
  namespace : 'Meson',
  symbol_prefix : 'meson',
  identifier_prefix : 'Meson',
  includes : ['GObject-2.0'],
  install : true,
  build_by_default : true,
)

test_env = environment()
lib_dir = join_paths(get_option('prefix'), get_option('libdir'))
test_env.prepend('GI_TYPELIB_PATH', join_paths(lib_dir, 'girepository-1.0'))
test_env.prepend('LD_LIBRARY_PATH', lib_dir)
test('gobject introspection', find_program('test.py'), env: test_env)

gnome.gtkdoc(
  'meson_sample',
  src_dir : join_paths(meson.source_root(), 'src'),
  main_xml : 'meson-sample-docs.xml',
  dependencies: [meson_sample],
  scan_args: [
    '--rebuild-types',
  ],
  install : true)
