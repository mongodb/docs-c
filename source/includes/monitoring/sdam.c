#include <stdio.h>
#include <bson/bson.h>
#include <mongoc/mongoc.h>

typedef struct {
   int server_opening_events;
} stats_t;


static void
server_opening (const mongoc_apm_server_opening_t *event)
{
   stats_t *context;

   context = (stats_t *) mongoc_apm_server_opening_get_context (event);
   context->server_opening_events++;

   printf ("Server opening: %s\n", mongoc_apm_server_opening_get_host (event)->host_and_port);
}

int
main (void)
{
   mongoc_client_t *client;
   mongoc_apm_callbacks_t *cbs
   stats_t stats = {0};
   mongoc_init ();

   client = mongoc_client_new ("<connection string URI>");

   cbs = mongoc_apm_callbacks_new ();
   mongoc_apm_set_server_opening_cb (cbs, server_opening);
   mongoc_client_set_apm_callbacks (client, cbs, (void *) &stats);

   // Perform database operations

   mongoc_client_destroy (client);
   mongoc_apm_callbacks_destroy (cbs);

   mongoc_cleanup ();

   return EXIT_SUCCESS;
}