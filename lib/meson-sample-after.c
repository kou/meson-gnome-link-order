#include "meson-sample.h"
#include <meson-sample-dep.h>

struct _MesonSampleAfter
{
  GObject parent_instance;
};

G_DEFINE_TYPE (MesonSampleAfter,
               meson_sample_after,
               G_TYPE_OBJECT)

static void
meson_sample_after_class_init (MesonSampleAfterClass *klass)
{
}

static void
meson_sample_after_init (MesonSampleAfter *sample)
{
}


/**
 * meson_sample_after_new:
 *
 * Allocates a new #MesonSampleAfter.
 *
 * Returns: a #MesonSampleAfter.
 */
MesonSampleAfter *
meson_sample_after_new (void)
{
  return g_object_new (MESON_TYPE_SAMPLE_AFTER, NULL);
}

/**
 * meson_sample_after_print_message:
 * @sample: a #MesonSampleAfter.
 * @message: a message to be printed.
 *
 * Prints the message.
 */
void
meson_sample_after_print_message (MesonSampleAfter *after,
                                  const gchar *message)
{
  meson_sample_dep_print_message_after (message);
}
