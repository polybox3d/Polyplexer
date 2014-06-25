#include "arguments.h"
#include <argp.h>
#include <stdlib.h>
#include <error.h>

const char *argp_program_version = "PolyPlexer 0.8";
const char *argp_program_bug_address = "<skapinthefourb@gmail.com>";

/* Program documentation. */
static char doc[] =
  "PolyPlexer -- Programme de multiplexage de paquet serie. \
     options								\
     \v Exemples : \n \
     ./PolyPlexer --serial=/dev/ttyACM0 --printer_sock=/dev/ttyDEAMONPRINTER --polybox_sock=/dev/ttyDEAMONPOLY \n\n \
     Pour toute aide ou renseignement, cosnulter la documentation ou envoyer un mail.\n";

/* A description of the arguments we accept. */
static char args_doc[] = "--serial=/dev/ttyACM0 --printer_sock=/dev/ttyDEAMONPRINTER --polybox_sock=/dev/ttyDEAMONPOLY";


void arguments_init( struct arguments* arg)
{
  strcpy(arg->serial, "");
  strcpy(arg->printer_sock, "");
  strcpy(arg->polybox_sock, "");
  arg->verbose = 0;
}
/* The options we understand. */
struct argp_option options[] = {
  {"verbose",   'v', 0, 0,       "Activer le mode mode verbeux. Ecrire plus d'informations utiles sur les sorties standard et d'erreur.", 0 },
  {"serial",   's', "/dev/ACM0",0,       "Chemin d'acces au périphérique serie de la machine connectée.", 0 },
  {"printer_sock",   'p', "/dev/ttyDEAMONPRINTER", 0,       "Chemin d'acces vers le peripherique serie utilisé par le logiciel d'impression 3D.", 0 },
  {"polybox_sock",   'b', "/dev/ttyDEAMONPOLY", 0,       "Chemin d'acces vers le peripherique serie utilisé par le logiciel de gestion de la Polybox.", 0 },
   { 0 }
};

/* Our argp parser. */
struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };


struct argp* get_argp()
{
  return &argp;
}

/* Parse a single option. */
error_t parse_opt (int key, char *arg, struct argp_state *state)
{
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *arguments = state->input;
  
  switch (key)
    {
#if VERBOSE > 0
    case 'v':
      arguments->verbose = atoi( arg );
      break;
#endif
    case 's':
      strncpy(arguments->serial, arg, ARG_SIZE );
      break;
    case 'p':
      strncpy(arguments->printer_sock, arg, ARG_SIZE );
      break;
    case 'b':
      strncpy(arguments->polybox_sock, arg, ARG_SIZE );
      break;
	 /*case ARGP_KEY_END:
	   if (state->arg_num < 2)
		 // Not enough arguments. 
		 argp_usage (state);
		return ARGP_ERR_UNKNOWN;*/
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}
