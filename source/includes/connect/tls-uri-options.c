#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

  // start-connect
  // Intialize the MongoDB C Driver
  mongoc_init ();
  
  bson_error_t error;

  // Create a new client and set TLS option to true
  mongoc_uri_t *uri = mongoc_uri_new_with_error ("mongodb://localhost:27017", &error);  
  mongoc_uri_set_option_as_bool (uri, MONGOC_URI_TLS, true);
  if (!uri) {
	  fprintf (stderr, "failed to parse URI, error: %s\n", error.message);
	  goto cleanup;
  }

  mongoc_client_t *client = mongoc_client_new_from_uri (uri);

  // { Do database work here }
  
  cleanup:
    mongoc_client_destroy (client);
    mongoc_cleanup ();
  // end-connect
}