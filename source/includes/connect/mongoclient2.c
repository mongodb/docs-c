#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

	mongoc_client_t *client
  mongoc_database_t *database
  mongoc_server_api_t *api = NULL;
	bson_t *command, reply;
	bson_error_t error;
  char *uri
	bool retval;
  bool ok = true;

  // Intialize the MongoDB C Driver
	mongoc_init();

  //start-connect-to-atlas
  // Create a new client and connect to the server
  uri = "mongodb+srv://<db_username>:<db_password>@<hostname/port>/?<options>"
  client = mongoc_client_new (uri);
	database = mongoc_client_get_database (client, "admin");

  // Set the version of the Stable API on the client
  api = mongoc_server_api_new(MONGOC_SERVER_API_V1);
  ok = mongoc_client_set_server_api(client, api, &error);
    
  // Send a ping to confirm a successful connection
  command = BCON_NEW ("ping", BCON_INT32 (1));
  retval = mongoc_client_command_simple (client, "admin", command, NULL, &reply, &error);

  if (!retval) {
	  fprintf (stderr, "%s\n", error.message);
    return EXIT_FAILURE;
  }
  printf ("Pinged your deployment. You successfully connected to MongoDB!\n");
  //end-connect-to-atlas

  // Cleanup
  bson_destroy (&reply);
  bson_destroy (command);
  bson_free (uri);
  mongoc_database_destroy (database);
  mongoc_server_api_destroy(api);
  mongoc_client_destroy (client);
  mongoc_cleanup ();
}