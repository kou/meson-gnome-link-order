#include "meson-sample.h"
#include <meson-sample-dep.h>

struct _MesonSampleBefore
{
  GObject parent_instance;
};

G_DEFINE_TYPE (MesonSampleBefore,
               meson_sample_before,
               G_TYPE_OBJECT)

static void
meson_sample_before_class_init (MesonSampleBeforeClass *klass)
{
}

static void
meson_sample_before_init (MesonSampleBefore *sample)
{
}


/**
 * meson_sample_before_new:
 *
 * Allocates a new #MesonSampleBefore.
 *
 * Returns: a #MesonSampleBefore.
 */
MesonSampleBefore *
meson_sample_before_new (void)
{
  return g_object_new (MESON_TYPE_SAMPLE_BEFORE, NULL);
}

/**
 * meson_sample_before_print_message:
 * @sample: a #MesonSampleBefore.
 * @message: a message to be printed.
 *
 * Prints the message.
 */
void
meson_sample_print_message_before (MesonSampleBefore *before,
                                   const gchar *message)
{
  meson_sample_dep_print_message_before (message);
}
