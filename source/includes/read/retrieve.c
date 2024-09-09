#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    bson_error_t error;

    mongoc_init ();

    client =
        mongoc_client_new ("<connection string URI>");
    collection = mongoc_client_get_collection (client, "sample_restaurants", "restaurants");

    {
        // start-find
        bson_t *filter = BCON_NEW ("cuisine", BCON_UTF8 ("Spanish"));

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);
        // end-find
        
        // start-find-iterate
        char *str;
        const bson_t *doc;

        while (mongoc_cursor_next (results, &doc)) {
            str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-find-iterate
    }

    {
        // start-find-all
        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, bson_new (), NULL, NULL);
        mongoc_cursor_destroy (results);
        // end-find-all
    }

    {
        // start-modified-find
        bson_t *filter = BCON_NEW ("cuisine", BCON_UTF8 ("Spanish"));
        bson_t *opts = BCON_NEW ("limit", BCON_INT32 (10), "maxTimeMS", BCON_INT32 (10000));

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, bson_new (), opts, NULL);

        mongoc_cursor_destroy (results);
        // end-modified-find
    }

    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}