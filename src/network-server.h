#ifndef _NETWORK_SERVER_H_
#define _NETWORK_SERVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <network.h>

typedef __attribute__ ((nonnull (2), warn_unused_result))
int (*servercb_t) (socket_t, struct sockaddr_in *restrict cli, void *restrict) ;

typedef __attribute__ ((nonnull (2), warn_unused_result))
int (*network_servercb_t) (socket_t, struct sockaddr_in *restrict,
   uint32_t addr, void *restrict) ;

int network_server (
   uint16_t port, uint32_t addr, int type, int protocol,
   servercb_t cb, void *restrict cb_args)
__attribute__ ((nonnull (5), warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _NETWORK_SERVER_H_ */
