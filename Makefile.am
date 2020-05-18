# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libnetwork.pc src/libnetwork-client.pc src/libnetwork-server.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libnetwork.pc.in src/libnetwork-client.pc.in src/libnetwork-server.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

