# How to reproduce https://github.com/mesonbuild/meson/pull/5120

Run the following command lines:

```shell
git clone https://github.com/kou/meson-gnome-link-order.git
cd meson-gnome-link-order
./run.sh
```

Here is error log:

```text
...
[4/5] /bin/g-ir-scanner -pthread -I/usr/include/gobject-introspection-1.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include --no-libtool --namespace=Meson --nsversion=1.0 --warn-all --output src/Meson-1.0.gir -I/home/kou/work/python/meson-gnome-link-order/lib/src -I/home/kou/work/python/meson-gnome-link-order/lib/build/src --filelist=/home/kou/work/python/meson-gnome-link-order/lib/build/src/25a6634@@meson_sample@sha/Meson_1.0_gir_filelist --include=GObject-2.0 --symbol-prefix=meson --identifier-prefix=Meson --cflags-begin -DMESON_TEST -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/home/kou/work/python/meson-gnome-link-order/install/include --cflags-end -L/home/kou/work/python/meson-gnome-link-order/install/lib --library meson_sample -L/home/kou/work/python/meson-gnome-link-order/lib/build/src --extra-library=gobject-2.0 --extra-library=glib-2.0 -L/home/kou/work/python/meson-gnome-link-order/install/lib --extra-library=meson_sample_dep
FAILED: src/Meson-1.0.gir 
/bin/g-ir-scanner -pthread -I/usr/include/gobject-introspection-1.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include --no-libtool --namespace=Meson --nsversion=1.0 --warn-all --output src/Meson-1.0.gir -I/home/kou/work/python/meson-gnome-link-order/lib/src -I/home/kou/work/python/meson-gnome-link-order/lib/build/src --filelist=/home/kou/work/python/meson-gnome-link-order/lib/build/src/25a6634@@meson_sample@sha/Meson_1.0_gir_filelist --include=GObject-2.0 --symbol-prefix=meson --identifier-prefix=Meson --cflags-begin -DMESON_TEST -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/home/kou/work/python/meson-gnome-link-order/install/include --cflags-end -L/home/kou/work/python/meson-gnome-link-order/install/lib --library meson_sample -L/home/kou/work/python/meson-gnome-link-order/lib/build/src --extra-library=gobject-2.0 --extra-library=glib-2.0 -L/home/kou/work/python/meson-gnome-link-order/install/lib --extra-library=meson_sample_dep
g-ir-scanner: link: cc -o /home/kou/work/python/meson-gnome-link-order/lib/build/tmp-introspectsjd7m7_r/Meson-1.0 /home/kou/work/python/meson-gnome-link-order/lib/build/tmp-introspectsjd7m7_r/Meson-1.0.o -L. -Wl,-rpath,. -Wl,--no-as-needed -L/home/kou/work/python/meson-gnome-link-order/install/lib -Wl,-rpath,/home/kou/work/python/meson-gnome-link-order/install/lib -L/home/kou/work/python/meson-gnome-link-order/lib/build/src -Wl,-rpath,/home/kou/work/python/meson-gnome-link-order/lib/build/src -L/home/kou/work/python/meson-gnome-link-order/install/lib -Wl,-rpath,/home/kou/work/python/meson-gnome-link-order/install/lib -lmeson_sample -lgobject-2.0 -lglib-2.0 -lmeson_sample_dep -lgio-2.0 -lgobject-2.0 -Wl,--export-dynamic -lgmodule-2.0 -pthread -lglib-2.0
/bin/ld: /home/kou/work/python/meson-gnome-link-order/lib/build/tmp-introspectsjd7m7_r/Meson-1.0.o:/home/kou/work/python/meson-gnome-link-order/lib/build/tmp-introspectsjd7m7_r/Meson-1.0.c:618: undefined reference to `meson_sample_after_get_type'
/bin/ld: /home/kou/work/python/meson-gnome-link-order/install/lib/libmeson_sample.so: undefined reference to `meson_sample_dep_print_message_before'
collect2: error: ld returned 1 exit status
linking of temporary binary failed: Command '['cc', '-o', '/home/kou/work/python/meson-gnome-link-order/lib/build/tmp-introspectsjd7m7_r/Meson-1.0', '/home/kou/work/python/meson-gnome-link-order/lib/build/tmp-introspectsjd7m7_r/Meson-1.0.o', '-L.', '-Wl,-rpath,.', '-Wl,--no-as-needed', '-L/home/kou/work/python/meson-gnome-link-order/install/lib', '-Wl,-rpath,/home/kou/work/python/meson-gnome-link-order/install/lib', '-L/home/kou/work/python/meson-gnome-link-order/lib/build/src', '-Wl,-rpath,/home/kou/work/python/meson-gnome-link-order/lib/build/src', '-L/home/kou/work/python/meson-gnome-link-order/install/lib', '-Wl,-rpath,/home/kou/work/python/meson-gnome-link-order/install/lib', '-lmeson_sample', '-lgobject-2.0', '-lglib-2.0', '-lmeson_sample_dep', '-lgio-2.0', '-lgobject-2.0', '-Wl,--export-dynamic', '-lgmodule-2.0', '-pthread', '-lglib-2.0']' returned non-zero exit status 1.
ninja: build stopped: subcommand failed.
```

How to confirm https://github.com/mesonbuild/meson/pull/5120 resolves this case:

```shell
git clone https://github.com/mesonbuild/meson.git /tmp/meson
cd /tmp/meson
git fetch origin pull/5120/head:5120
git checkout 5120
cd -
MESON=/tmp/meson/meson.py ./run.sh
```
