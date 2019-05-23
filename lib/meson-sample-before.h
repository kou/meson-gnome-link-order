#pragma once

#if !defined (MESON_TEST)
#error "MESON_TEST not defined."
#endif

#include <glib-object.h>

G_BEGIN_DECLS

#define MESON_TYPE_SAMPLE_BEFORE (meson_sample_before_get_type())
G_DECLARE_FINAL_TYPE (MesonSampleBefore,
                      meson_sample_before,
                      MESON,
                      SAMPLE_BEFORE,
                      GObject)

MesonSampleBefore *meson_sample_before_new (void);
void meson_sample_before_print_message (MesonSampleBefore *sample,
                                        const gchar *message);

G_END_DECLS
