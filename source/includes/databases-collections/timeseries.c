#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // start-create-time-series
    bson_error_t error;

    // Initialize the MongoDB C Driver
    mongoc_init();

    // Create a new client instance
    mongoc_client_t *client = mongoc_client_new("<connection string>");

    // Get a handle on the database
    mongoc_database_t *database = mongoc_client_get_database(client, "fall_weather");

    // Create options for the time series collection
    bson_t *opts = BCON_NEW(
        "timeseries", "{",
        "timeField", BCON_UTF8("timestamp"),
        "}");

    // Create the time series collection
    mongoc_database_create_collection(database, "october2024", opts, &error);
    // end-create-time-series

    // start-list-collections
    const bson_t *doc;

    // List collections in the database
    mongoc_cursor_t *cursor = mongoc_database_find_collections_with_opts(database, NULL);

    while (mongoc_cursor_next(cursor, &doc))
    {
        char *str = bson_as_canonical_extended_json(doc, NULL);
        printf("%s\n", str);
        bson_free(str);
    }

    // Check for cursor errors
    if (mongoc_cursor_error(cursor, &error))
    {
        fprintf(stderr, "Cursor error: %s\n", error.message);
    }
    // end-list-collections

    // start-insert-document
    const bson_t *insert_doc;
    insert_doc = BCON_NEW(
        "temperature", BCON_DOUBLE(70.0),
        "location", "{", "city", BCON_UTF8("New York"), "}",
        "timestamp", BCON_DATE_TIME(1633046400000));

    mongoc_collection_insert_one(collection, insert_doc, NULL, NULL, &error))
    // end-insert-document

    bson_destroy(opts);
    mongoc_cursor_destroy(cursor);
    mongoc_database_destroy(database);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return EXIT_SUCCESS;
}