#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

  // start-connect-to-atlas-w-uri
  mongoc_client_t *client
  mongoc_database_t *database
  char *uri

	mongoc_init();

  // Create a new client and connect to the server
  uri = "mongodb+srv://<db_username>:<db_password>@<hostname/port>/?<options>"
  client = mongoc_client_new (uri);
	database = mongoc_client_get_database (client, "admin");

  // Cleanup
  bson_free (uri);
  mongoc_database_destroy (database);
  mongoc_client_destroy (client);
  mongoc_cleanup ();
  // end-connect-to-atlas-w-uri
}