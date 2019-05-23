#pragma once

#if !defined (MESON_TEST)
#error "MESON_TEST not defined."
#endif

#include <glib-object.h>

G_BEGIN_DECLS

#define MESON_TYPE_SAMPLE_AFTER (meson_sample_after_get_type())
G_DECLARE_FINAL_TYPE (MesonSampleAfter,
                      meson_sample_after,
                      MESON,
                      SAMPLE_AFTER,
                      GObject)

MesonSampleAfter *meson_sample_after_new (void);
void meson_sample_after_print_message (MesonSampleAfter *sample,
                                       const gchar *message);

G_END_DECLS
