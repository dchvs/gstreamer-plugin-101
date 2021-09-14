#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "example_plugin.h"

/* Element metadata */
static const gchar gst_example_plugin_name[] = "example_plugin";
static const gchar gst_example_plugin_longname[] = "Example plugin";
static const gchar gst_example_plugin_classification[] = "Example/FirstExample";
static const gchar gst_example_plugin_description[] = "GStreamer example plugin";
static const gchar gst_example_plugin_author[] = "Daniel Chaves <danichg94@gmail.com";
static const gchar gst_example_plugin_license[] = "LGPL";
static const gchar gst_example_plugin_package[] = "GStreamer";
static const gchar gst_example_plugin_origin[] = "http://gstreamer.net/";
static const gchar gst_example_plugin_version[] = "0.1.0";

/* Element pads */
#define GST_EXAMPLE_PLUGIN_SINK_PAD GST_STATIC_PAD_TEMPLATE("sink", GST_PAD_SINK, GST_PAD_ALWAYS, GST_STATIC_CAPS("ANY"))
#define GST_EXAMPLE_PLUGIN_SRC_PAD GST_STATIC_PAD_TEMPLATE("src", GST_PAD_SRC, GST_PAD_ALWAYS, GST_STATIC_CAPS("ANY"))

static GstStaticPadTemplate sink_pad_template = GST_EXAMPLE_PLUGIN_SINK_PAD;
static GstStaticPadTemplate src_pad_template = GST_EXAMPLE_PLUGIN_SRC_PAD;


G_DEFINE_TYPE (GstExamplePlugin, gst_example_plugin, GST_TYPE_ELEMENT)

static void gst_example_plugin_class_init(GstExamplePluginClass *klass) {
    GstElementClass *element_class = NULL;
    GstPadTemplate *src_pad = NULL;
    GstPadTemplate *sink_pad = NULL;

    element_class = GST_ELEMENT_CLASS (klass);

    src_pad = gst_static_pad_template_get(&src_pad_template);
    gst_element_class_add_pad_template (element_class, src_pad);

    sink_pad = gst_static_pad_template_get(&sink_pad_template);
    gst_element_class_add_pad_template (element_class, sink_pad);

    gst_element_class_set_static_metadata(element_class, gst_example_plugin_longname, gst_example_plugin_classification, gst_example_plugin_description, gst_example_plugin_author);
}

static gboolean example_plugin_init (GstPlugin *plugin) {
    return gst_element_register (plugin, gst_example_plugin_name, GST_RANK_NONE, GST_TYPE_EXAMPLE_PLUGIN);
}

static void gst_example_plugin_init (GstExamplePlugin *this) {
    return;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR, GST_VERSION_MINOR, example_plugin, gst_example_plugin_description, example_plugin_init, gst_example_plugin_version, gst_example_plugin_license, gst_example_plugin_package, gst_example_plugin_origin)
