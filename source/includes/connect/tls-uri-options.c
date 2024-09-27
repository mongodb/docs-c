#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main (void) {

  // start-connect
  // Initialize the MongoDB C Driver
  mongoc_init ();
  
  // Create a new client and set TLS option to true
  mongoc_uri_t *uri = mongoc_uri_new ("mongodb://localhost:27017");  
  mongoc_uri_set_option_as_bool (uri, MONGOC_URI_TLS, true);

  mongoc_client_t *client = mongoc_client_new_from_uri (uri);

  // { Do database work here }
  
  // Cleanup
  mongoc_client_destroy (client);
  mongoc_uri_destroy (uri);
  mongoc_cleanup ();
  // end-connect
}