#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main (void) {

  // start-connect-to-atlas
  // Initialize the MongoDB C Driver
  mongoc_init ();

  // Create a new client and set tls option to true
  mongoc_client_t *client = mongoc_client_new ("mongodb+srv://<db_username>:<db_password>@<hostname/port>/?replicaSet=myRepl&tls=true");

  // { Do database work here }

  // Cleanup
  mongoc_client_destroy (client);
  mongoc_cleanup ();
  // end-connect-to-atlas
}
