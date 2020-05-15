AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
include_HEADERS = network.h
bin_PROGRAMS    =

dist_bin_SCRIPTS = libnetwork_config libnetwork_client_config libnetwork_server_config

lib_LTLIBRARIES += libnetwork.la
libnetwork_la_LIBADD = @LIBNETWORK_LIBADD@
include_HEADERS += libnetwork.h

lib_LTLIBRARIES += libnetwork-client.la
libnetwork_client_la_LIBADD = @LIBNETWORK_CLIENT_LIBADD@
include_HEADERS += network-client.h
EXTRA_libnetwork_client_la_DEPENDENCIES = libnetwork.la

lib_LTLIBRARIES += libnetwork-server.la
libnetwork_server_la_LIBADD = @LIBNETWORK_SERVER_LIBADD@
include_HEADERS += network-server.h
EXTRA_libnetwork_server_la_DEPENDENCIES = libnetwork.la

