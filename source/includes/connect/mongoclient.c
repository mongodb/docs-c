#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main (void) {

  // start-connect-to-atlas-w-uri
  mongoc_init ();

  // Create a new client and connect to the server
  char *uri = "mongodb+srv://<db_username>:<db_password>@<hostname/port>/?<options>";
  mongoc_client_t *client = mongoc_client_new (uri);
  mongoc_database_t *database = mongoc_client_get_database (client, "admin");

  // Cleanup
  mongoc_database_destroy (database);
  mongoc_client_destroy (client);
  mongoc_cleanup ();
  // end-connect-to-atlas-w-uri
}