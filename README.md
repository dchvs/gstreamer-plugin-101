# Description
This is a GStreamer 101 example plugin.

# Installation
```
mkdir build/ && cd build/
cmake  ..
make
make install
```

# Check the plugin installation
```
gst-inspect-1.0 example_plugin

Factory Details:
  Rank                     none (0)
  Long-name                Example plugin
  Klass                    Example/FirstExample
  Description              GStreamer example plugin
  Author                   Daniel Chaves <danichg94@gmail.com

Plugin Details:
  Name                     example_plugin
  Description              GStreamer example plugin
  Filename                 /usr/local/lib/libexample_plugin.so
  Version                  0.1.0
  License                  LGPL
  Source module            example_plugin
  Binary package           GStreamer
  Origin URL               http://gstreamer.net/

GObject
 +----GInitiallyUnowned
       +----GstObject
             +----GstElement
                   +----GstExamplePlugin
```
