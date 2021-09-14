cmake_minimum_required(VERSION 3.9)

set(SRC_NAME example_plugin)
project(${SRC_NAME} VERSION 0.1.0 DESCRIPTION "GStreamer 101 plugin")

# Errors on warnings
set(C_WARNINGS "-Wall -Wstrict-prototypes -Wshadow -Werror -fPIC")

# Find the dependencies with Pkgconfig
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTLIBS REQUIRED
        glib-2.0>=2.56.0
        gstreamer-1.0
)

add_subdirectory(lib)
