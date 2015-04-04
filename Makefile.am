AM_CFLAGS = -Wundef \
        -Wstrict-prototypes \
        -Wno-trigraphs \
        -g -O0 \
        -fno-inline \
        -fno-short-enums \
        -fpic \
        -I${top_srcdir}/include

AM_CPPFLAGS = $(AM_CFLAGS)

ACLOCAL_AMFLAGS = -I m4

### Build libselinux library

libselinux_h_sources = include/selinux/selinux.h include/selinux/label.h include/selinux/context.h include/selinux/avc.h include/selinux/android.h

libselinux_c_sources := \
        src/callbacks.c \
        src/check_context.c \
        src/freecon.c \
        src/init.c \
        src/label.c \
        src/label_file.c \
        src/label_android_property.c

libselinux_la_SOURCES = $(libselinux_c_sources) $(libselinux_h_sources)
libselinux_la_LDFLAGS = $(PCRE_LIB)

### Export library
lib_LTLIBRARIES = libselinux.la

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libselinux.pc
EXTRA_DIST = $(pkgconfig_DATA)

library_includedir = $(pkgincludedir)/selinux
library_include_HEADERS = $(libselinux_h_sources)
