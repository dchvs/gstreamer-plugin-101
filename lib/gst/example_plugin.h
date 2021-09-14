#ifndef _EXAMPLE_PLUGIN_H_
#define _EXAMPLE_PLUGIN_H_

#ifndef PACKAGE
#define PACKAGE "example_plugin"
#endif

#include <gst/gst.h>

/* Element data */
typedef struct _GstExamplePlugin {
    GstElement element;
    GstPad *sinkpad, *srcpad;
    gboolean silent;
} GstExamplePlugin;

/* Element class */
typedef struct _GstExamplePluginClass {
    GstElementClass parent_class;
} GstExamplePluginClass;

G_BEGIN_DECLS

/* Element GType */
GType gst_example_plugin (void);

/* Define types for this element */
#define GST_TYPE_EXAMPLE_PLUGIN (gst_example_plugin_get_type())

#define GST_EXAMPLE_PLUGIN (obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_EXAMPLE_PLUGIN, GstExamplePlugin))
#define GST_IS_EXAMPLE_PLUGIN (obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_EXAMPLE_PLUGIN))

#define GST_EXAMPLE_PLUGIN_CLASS (klass) (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_EXAMPLE_PLUGIN, GstExamplePluginClass))
#define GST_IS_EXAMPLE_PLUGIN_CLASS (klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_EXAMPLE_PLUGIN))

G_END_DECLS

#endif /* _EXAMPLE_PLUGIN_H_ */
