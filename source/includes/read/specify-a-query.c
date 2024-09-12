#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
    // Inserts sample data for this guide into example collection
    // start-sample-data
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_init ();

    client =
        mongoc_client_new ("<connection string URI>");
    collection = mongoc_client_get_collection (client, "sample_fruit", "fruits");

    bson_t *doc1, *doc2, *doc3, *doc4;
    const bson_t *docs[4];

    doc1 = BCON_NEW (
        "_id", BCON_INT32 (1),
        "name", BCON_UTF8 ("apples"),
        "quantity", BCON_INT32 (5),
        "rating", BCON_INT32 (3),
        "color", BCON_UTF8 ("red"),
        "type", "[", BCON_UTF8 ("fuji"), BCON_UTF8 ("honeycrisp"), "]"
    );

    doc2 = BCON_NEW(
        "_id", BCON_INT32 (2),
        "name", BCON_UTF8 ("bananas"),
        "quantity", BCON_INT32 (7),
        "rating", BCON_INT32 (4),
        "color", BCON_UTF8 ("yellow"),
        "type", "[", BCON_UTF8 ("cavendish"), "]"
    );

    doc3 = BCON_NEW (
        "_id", BCON_INT32 (3),
        "name", BCON_UTF8 ("oranges"),
        "quantity", BCON_INT32 (6),
        "rating", BCON_INT32 (2),
        "type", "[", BCON_UTF8 ("naval"), BCON_UTF8 ("mandarin"), "]"
    );

    doc4 = BCON_NEW (
        "_id", BCON_INT32 (4),
        "name", BCON_UTF8 ("pineapple"),
        "quantity", BCON_INT32 (3),
        "rating", BCON_INT32 (5),
        "color", BCON_UTF8 ("yellow")
    );

    docs[0] = doc1;
    docs[1] = doc2;
    docs[2] = doc3;
    docs[3] = doc4;

    mongoc_collection_insert_many (collection, docs, 4, NULL, NULL, NULL);

    bson_destroy (doc1);
    bson_destroy (doc2);
    bson_destroy (doc3);
    bson_destroy (doc4);
    // end-sample-data

    {
        // start-find-exact
        const bson_t *doc;
        bson_t *filter = BCON_NEW ("color", BCON_UTF8 ("yellow"));

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);

        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-find-exact
    }

    {
        // start-find-comparison
        const bson_t *doc;
        bson_t *filter = BCON_NEW ("rating", "{", "$gt", BCON_INT32 (2), "}");

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);

        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-find-comparison
    }

    {
        // start-find-logical
        const bson_t *doc;
        bson_t *filter = BCON_NEW (
            "$or", "[",
                "{", "quantity", BCON_INT32(5), "}",
                "{", "color", BCON_UTF8("yellow"), "}",
            "]"
        );

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);

        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-find-logical
    }

    {
        // start-find-array
        const bson_t *doc;
        bson_t *filter = BCON_NEW ("type", "{", "$size", BCON_INT32 (2), "}");

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);

        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-find-array
    }

    {
        // start-find-element
        const bson_t *doc;
        bson_t *filter = BCON_NEW ("color", "{", "$exists", BCON_BOOL (true), "}");

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);

        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-find-element
    }

    {
        // start-find-evaluation
        const bson_t *doc;
        bson_t *filter = BCON_NEW("name", "{", "$regex", BCON_UTF8("p{2,}"), "}");

        mongoc_cursor_t *results = 
            mongoc_collection_find_with_opts (collection, filter, NULL, NULL);

        while (mongoc_cursor_next (results, &doc)) {
            char *str = bson_as_canonical_extended_json (doc, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }

        mongoc_cursor_destroy (results);
        bson_destroy (filter);
        // end-find-evaluation
    }

    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}