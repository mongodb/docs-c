#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

  // start-connect

  // Intialize the MongoDB C Driver
  mongoc_init ();

  // Create a new client 
  mongoc_client_t *client = mongoc_client_new ("mongodb://host01:27017,host02:27017,host03:27017/?replicaSet=myreplset");
  if (!client) {
    goto cleanup;
  }

  // Send a ping to confirm a successful connection
  bson_t *ping = BCON_NEW ("ping", BCON_INT32 (1));
  bson_t reply = BSON_INITIALIZER;
  bson_error_t error;
  
  if (!mongoc_client_command_simple (client, "admin", ping, NULL, &reply, &error)) {
    fprintf(stderr, "error: %s\n", error.message);
    goto cleanup;
  }

  printf ("Pinged your deployment. You successfully connected to MongoDB!\n");
  
  cleanup:
    bson_destroy (&reply);
    bson_destroy (ping);

    mongoc_client_destroy (client);

    // Cleanup the C Driver
    mongoc_cleanup ();
  // end-connect
}
