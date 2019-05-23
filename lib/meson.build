project('gnome-link-order', 'c')

gobject = dependency('gobject-2.0', required: false)
if not gobject.found()
  error('MESON_SKIP_TEST gobject not found.')
endif

python3 = import('python3')
py3 = python3.find_python()
if run_command(py3, '-c', 'import gi;').returncode() != 0
    error('MESON_SKIP_TEST python3-gi not found')
endif

gtkdoc = find_program('gtkdoc-scan', required: false)
if not gtkdoc.found()
  error('MESON_SKIP_TEST gtkdoc not found.')
endif

cc = meson.get_compiler('c')

add_global_arguments('-DMESON_TEST', language : 'c')
if cc.get_id() == 'intel'
  # Ignore invalid GCC pragma warnings from glib
  # https://bugzilla.gnome.org/show_bug.cgi?id=776562
  add_global_arguments('-wd2282', language : 'c')
endif

subdir('src')
