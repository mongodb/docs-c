#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *results;
    int64_t count;
    const bson_t *doc;
    bson_t *query, *command;
    bson_t reply;
    char *str;
    bson_error_t error;

    mongoc_init ();

    client =
        mongoc_client_new ("<connection string URI>");
    collection =
        mongoc_client_get_collection (client, "<database name>", "collection name");

    // Start example code here

    // End example code here

    bson_destroy (query);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}