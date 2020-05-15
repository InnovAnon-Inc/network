#if HAVE_CONFIG_H
#include <config.h>
#endif

/*#define _BSD_SOURCE*/
#define _DEFAULT_SOURCE

#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <restart.h>

#include <libnetwork.h>
#include <network-client.h>

typedef struct {
   char const (*restrict addr)[];
   clientcb_t cb;
   void *restrict args;
} networkcb_args_t;

__attribute__ ((nonnull (2, 3), warn_unused_result))
static int networkcb (socket_t s, struct sockaddr_in *restrict si_other,
   void *restrict args) {
   networkcb_args_t *restrict my_args = args;

   error_check (inet_aton (*(my_args->addr), &(si_other->sin_addr)) == 0) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
      r_close (s);
   #pragma GCC diagnostic pop
      return -2;
   }

   error_check (my_args->cb (s, si_other, my_args->args) != 0) {
   #pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
      r_close (s);
   #pragma GCC diagnostic pop
      return -3;
   }
   
   return 0;
}

__attribute__ ((nonnull (2, 5), warn_unused_result))
int network_client (
   uint16_t port, char const addr[], int type, int protocol,
   clientcb_t cb,
   void *restrict cb_args) {
   networkcb_args_t args;
   /* TODO why is this an incompatible pointer type? */
   args.addr = (char const (*)[]) &addr;
   args.cb   = cb;
   args.args = cb_args;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
   return network (port, type, protocol, networkcb, &args);
	#pragma GCC diagnostic pop
}
