#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

    mongoc_database_t *database
		bson_t *ping, reply;
	  bson_error_t error;

		mongoc_init();

    // Start example code here

    // End example code here

		database = mongoc_client_get_database (client, "admin");
    
    ping = BCON_NEW ("ping", BCON_INT32 (1));
   
    if (!mongoc_client_command_simple (client, "admin", ping, NULL, &reply, &error)) {
	    fprintf (stderr, "%s\n", error.message);
      return EXIT_FAILURE;
    }
    printf ("Pinged your deployment. You successfully connected to MongoDB!\n");

    bson_destroy (&reply);
    bson_destroy (ping);
    mongoc_database_destroy (database);
    mongoc_client_destroy (client);
    mongoc_cleanup ();
}