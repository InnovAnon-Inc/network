#if HAVE_CONFIG_H
#include <config.h>
#endif

#define inline __inline__

#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <restart.h>

#include <libnetwork.h>
#include <network-server.h>

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpadded"
typedef struct {
   servercb_t cb;
   void *restrict args;
   uint32_t addr;
} networkcb_args_t;
	#pragma GCC diagnostic pop

__attribute__ ((nonnull (2, 3), warn_unused_result))
static int networkcb (socket_t s, struct sockaddr_in *restrict si_me,
   void *restrict args) {
   networkcb_args_t *restrict my_args = args;

   si_me->sin_addr.s_addr = htonl (my_args->addr);
   
   TODO (type-punned pointers and strict-aliasing ?)
	#pragma GCC diagnostic push
   /*#pragma GCC diagnostic error "-Wstrict-aliasing=3"*/
	#pragma GCC diagnostic error "-Wstrict-aliasing"
   error_check (bind (s, (struct sockaddr *) si_me, (socklen_t) sizeof (*si_me)) == -1) {
	#pragma GCC diagnostic pop
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
      r_close (s);
	#pragma GCC diagnostic pop
      return -2;
   }
   
   error_check (my_args->cb (s, si_me, my_args->args) != 0) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
      r_close (s);
	#pragma GCC diagnostic pop
      return -3;
   }
   
   return 0;
}

__attribute__ ((nonnull (5), warn_unused_result))
int network_server (
   uint16_t port, uint32_t addr, int type, int protocol,
   servercb_t cb, void *restrict cb_args) {
   networkcb_args_t args;
   args.addr = addr;
   args.cb   = cb;
   args.args = cb_args;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
   return network (port, type, protocol, networkcb, &args);
	#pragma GCC diagnostic pop
}
