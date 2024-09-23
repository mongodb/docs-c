#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

		mongoc_client_t *client
    mongoc_database_t *database
		bson_t *command, reply;
	  bson_error_t error;
    char *uri
	  bool retval;

		mongoc_init();

    // start-connect-to-atlas-w-uri
    // Create a new client and connect to the server
    uri = "mongodb+srv://<db_username>:<db_password>@<hostname/port>/?<options>"
    client = mongoc_client_new (uri);
		database = mongoc_client_get_database (client, "admin");
    
    // Send a ping to confirm a successful connection
    command = BCON_NEW ("ping", BCON_INT32 (1));
    retval = mongoc_client_command_simple (client, "admin", command, NULL, &reply, &error);
    // end-connect-to-atlas-w-uri

    if (!retval) {
	    fprintf (stderr, "%s\n", error.message);
      return EXIT_FAILURE;
    }
    printf ("Pinged your deployment. You successfully connected to MongoDB!\n");

    // Cleanup
    bson_destroy (&reply);
    bson_destroy (command);
    bson_free (uri);
    mongoc_database_destroy (database);
    mongoc_client_destroy (client);
    mongoc_cleanup ();
}