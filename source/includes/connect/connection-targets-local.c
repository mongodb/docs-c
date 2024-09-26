#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

  // start-connect

  // Initialize the MongoDB C Driver
  mongoc_init ();

  bson_t *ping = BCON_NEW ("ping", BCON_INT32 (1));
  bson_t reply = BSON_INITIALIZER;
  bson_error_t error;
  mongoc_client_t *client = NULL;

  // Create a new client 
  mongoc_uri_t *uri = mongoc_uri_new_with_error ("mongodb://localhost:27017", &error);  
  if (!uri) {
	  fprintf (stderr, "failed to parse URI, error: %s\n", error.message);
	  goto cleanup;
  }

  client = mongoc_client_new_from_uri (uri);
  if (!client) {
    goto cleanup;
  }

  // Send a ping to confirm a successful connection
  if (!mongoc_client_command_simple (client, "admin", ping, NULL, &reply, &error)) {
    fprintf(stderr, "error: %s\n", error.message);
    goto cleanup;
  }
  printf ("Pinged your deployment. You successfully connected to MongoDB!\n");
  
  cleanup:
    bson_destroy (&reply);
    bson_destroy (ping);
    mongoc_client_destroy (client);
    mongoc_uri_destroy (uri);

    // Cleanup the C Driver
    mongoc_cleanup ();
  // end-connect
}