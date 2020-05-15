#ifndef _NETWORK_CLIENT_H_
#define _NETWORK_CLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <network.h>

typedef __attribute__ ((nonnull (2), warn_unused_result))
int (*clientcb_t) (socket_t, struct sockaddr_in *restrict,
   void *restrict) ;

typedef __attribute__ ((nonnull (2, 3), warn_unused_result))
int (*network_clientcb_t) (socket_t, struct sockaddr_in *restrict,
   char const addr[], void *restrict) ;

int network_client (
   uint16_t port, char const addr[], int type, int protocol,
   clientcb_t cb,
   void *restrict cb_args)
__attribute__ ((nonnull (2, 5), warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _NETWORK_CLIENT_H_ */
