#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;

    mongoc_init ();

    client =
        mongoc_client_new ("<connection string URI>");
    collection =
        mongoc_client_get_collection (client, "sample_mflix", "movies");

    {
        // start-remove-index
        bson_error_t error;

        if (mongoc_collection_drop_index (collection, "_title_", &error)) {
            printf ("Successfully dropped index\n");
        } else {
            fprintf (stderr, "Failed to drop index: %s", error.message);
        }
        // end-remove-index
    }
    {
        // start-index-single
        bson_error_t error;
        bson_t *keys = BCON_NEW ("title", BCON_INT32 (1));
        mongoc_index_model_t *index_model = mongoc_index_model_new (keys, NULL);

        if (mongoc_collection_create_indexes_with_opts (collection, &index_model, 1, NULL, NULL, &error)) {
            printf ("Successfully created index\n");
        } else {
            fprintf (stderr, "Failed to create index: %s", error.message);
        }

        bson_destroy (keys);
        mongoc_index_model_destroy (index_model);
        // end-index-single
    }
    {
        // start-index-single-query
        const bson_t *doc;
        bson_t *filter = BCON_NEW ("title", "Batman");

        mongoc_cursor_t *results =
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);
        
        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-index-single-query
    }
    {
        // start-index-multikey
        bson_error_t error;
        bson_t *keys = BCON_NEW ("cast", BCON_INT32 (1));
        mongoc_index_model_t *index_model = mongoc_index_model_new (keys, NULL);

        if (mongoc_collection_create_indexes_with_opts (collection, &index_model, 1, NULL, NULL, &error)) {
            printf ("Successfully created index\n");
        } else {
            fprintf (stderr, "Failed to create index: %s", error.message);
        }

        bson_destroy (keys);
        mongoc_index_model_destroy (index_model);
        // end-index-multikey
    }
    {
        // start-index-multikey-query
        const bson_t *doc;
        bson_t *filter = BCON_NEW ("cast", BCON_UTF8 ("Viola Davis"));

        mongoc_cursor_t *results =
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);
        
        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-index-multikey-query
    }


    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}