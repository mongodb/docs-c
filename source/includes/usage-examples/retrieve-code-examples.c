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
    collection = mongoc_client_get_collection (client, "<database name>", "collection name");

    // start-find
    query = bson_new ();
    <query definition>
    results = mongoc_collection_find_with_opts (collection, query, NULL, NULL);

    while (mongoc_cursor_next (results, &doc)) {
        str = bson_as_canonical_extended_json (doc, NULL);
        printf ("%s\n", str);
        bson_free (str);
    }

    mongoc_cursor_destroy (results);
    // end-find

    // start-count-all
    count = mongoc_collection_count_documents (collection, bson_new (), NULL, NULL, NULL, &error);

    printf ("%" PRId64 "\n", count);
    // end-count-all

    // start-count-query
    query = bson_new ();
    <query definition>
    count = mongoc_collection_count_documents (collection, query, NULL, NULL, NULL, &error);

    printf ("%" PRId64 "\n", count);
    // end-count-query

    // start-estimated-count
    count = mongoc_collection_estimated_document_count (collection, NULL, NULL, NULL, &error);

    printf ("%" PRId64 "\n", count);
    // end-estimated-count

    // start-distinct
    command = BCON_NEW ("distinct",
                        BCON_UTF8 ("<collection name>"),
                        "key",
                        BCON_UTF8 ("<field name>"));
    
    if (!mongoc_collection_read_command_with_opts (collection, command, NULL, NULL, &reply, &error)) {
        fprintf (stderr, "An error occurred: %s\n", error.message);
    } else {
        str = bson_as_canonical_extended_json (&reply, NULL);
        printf ("%s\n", str);
        bson_free (str);
    }
    // end-distinct

    // start-watch
    bson_t *pipeline;
    mongoc_change_stream_t *change_stream;
    pipeline = <pipeline definition>;

    change_stream = mongoc_collection_watch (collection, pipeline, NULL);

    while (mongoc_change_stream_next (change_stream, &doc)) {
      str = bson_as_canonical_extended_json (doc, NULL);
      printf ("Change: %s\n", str);
      bson_free (str);
    }

    bson_destroy (pipeline);
    mongoc_change_stream_destroy (change_stream);
    // end-watch

    bson_destroy (query);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}