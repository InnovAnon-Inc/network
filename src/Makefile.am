AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
include_HEADERS = network.h
bin_PROGRAMS    =

lib_LTLIBRARIES += libnetwork.la
libnetwork_la_CPPFLAGS = $(GLITTER_CFLAGS) $(RESTART_CFLAGS)
libnetwork_la_LIBADD   = $(GLITTER_LIBS)   $(RESTART_LIBS)
include_HEADERS += libnetwork.h

lib_LTLIBRARIES += libnetwork_client.la
libnetwork_client_la_CPPFLAGS =           $(GLITTER_CFLAGS) $(RESTART_CFLAGS)
libnetwork_client_la_LIBADD   = -lnetwork $(GLITTER_LIBS)   $(RESTART_LIBS)
include_HEADERS += network-client.h
EXTRA_libnetwork_client_la_DEPENDENCIES = libnetwork.la

lib_LTLIBRARIES += libnetwork_server.la
libnetwork_server_la_CPPFLAGS =           $(GLITTER_CFLAGS) $(RESTART_CFLAGS)
libnetwork_server_la_LIBADD   = -lnetwork $(GLITTER_LIBS)   $(RESTART_LIBS)
include_HEADERS += network-server.h
EXTRA_libnetwork_server_la_DEPENDENCIES = libnetwork.la

