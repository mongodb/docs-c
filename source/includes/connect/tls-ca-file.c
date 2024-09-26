#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(void) {

  // start-connect
  // Intialize the MongoDB C Driver
  mongoc_init ();
  
  // Create a new client, set TLS option to true, set path to client certificate file
  mongoc_uri_t *uri = mongoc_uri_new ("mongodb://localhost:27017");  
  mongoc_uri_set_option_as_bool (uri, MONGOC_URI_TLS, true);
  mongoc_uri_set_option_as_utf8 (uri, MONGOC_URI_TLSCERTIFICATEKEYFILE, "/path/to/client-certificate.pem");  
  
  // { Do database work here }
  
  // Cleanup
  mongoc_client_destroy (client);
  mongoc_cleanup ();
  // end-connect
}