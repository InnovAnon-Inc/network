#ifndef _LIBNETWORK_H_
#define _LIBNETWORK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <network.h>

typedef __attribute__ ((nonnull (2, 3), warn_unused_result))
int (*networkcb_t) (socket_t, struct sockaddr_in *restrict,
   void *restrict) ;

int network (
   uint16_t port, int type, int protocol,
   networkcb_t cb,
   void *restrict cb_args)
__attribute__ ((leaf, nonnull (4), warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _LIBNETWORK_H_ */
