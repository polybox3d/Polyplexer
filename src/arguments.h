#ifndef ARG_H_
#define ARG_H_

#include <argp.h>
#include <stdlib.h>
#include <error.h>
#include <stdio.h>
#include <string.h>

#define ARG_SIZE 1024

/* Used by main to communicate with parse_opt. */
struct arguments
{
  char *arg1;                   /* arg1 */
  char **strings;               /* [string...] */
  char printer_sock[ARG_SIZE];
  char polybox_sock[ARG_SIZE];
  char serial[ARG_SIZE];
  int verbose;
};


error_t parse_opt (int key, char *arg, struct argp_state *state);
struct argp* get_argp();
void arguments_init( struct arguments* arg);

#endif
