#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    char *str;

    mongoc_init();

    client = mongoc_client_new("<connection string>");
    collection = mongoc_client_get_collection(client, "sample_mflix", "movies");

    {
        // Specify the query filter
        bson_t *query = bson_new()
            BSON_APPEND_UTF8(query, "title", "The Shawshank Redemption");

        mongoc_cursor_t results = mongoc_collection_find_with_opts(collection, query, NULL, NULL);

        // Print the results
        while (mongoc_cursor_next(cursor, &doc))
        {
            str = bson_as_canonical_extended_json(doc, NULL);
            printf("%s\n", str);
            bson_free(str);
        }
    }

    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return EXIT_SUCCESS;
}