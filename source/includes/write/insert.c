#include <stdio.h>
#include <stdlib.h>
#include <bson/bson.h>
#include <mongoc/mongoc.h>

int main(int argc, char *argv[]) {
    mongoc_init();

    const char *uri_str = getenv("MONGODB_URI");
    if (!uri_str) {
        fprintf(stderr, "Set the MONGODB_URI variable to your Atlas URI that connects to the sample dataset\n");
        return EXIT_FAILURE;
    }

    mongoc_uri_t *uri = mongoc_uri_new_with_error(uri_str, NULL);
    if (!uri) {
        fprintf(stderr, "Failed to parse MongoDB URI\n");
        return EXIT_FAILURE;
    }

    mongoc_client_t *client = mongoc_client_new_from_uri(uri);
    if (!client) {
        fprintf(stderr, "Failed to create MongoDB client\n");
        return EXIT_FAILURE;
    }

    mongoc_collection_t *collection = mongoc_client_get_collection(client, "sample_restaurants", "restaurants");

    // Inserts a document that stores a "name" value of "Mongo's Burgers" into the collection
    // start-insert-one
    bson_t *doc1 = BCON_NEW("name", BCON_UTF8("Mongo's Burgers"));
    bson_error_t error;

    if (!mongoc_collection_insert_one(collection, doc1, NULL, NULL, &error)) {
        fprintf(stderr, "Insert failed: %s\n", error.message);
    }
    bson_destroy(doc1);
    // end-insert-one

    // Inserts documents representing restaurants into the collection
    // start-insert-many
    bson_t *docs[2];
    docs[0] = BCON_NEW("name", BCON_UTF8("Mongo's Burgers"));
    docs[1] = BCON_NEW("name", BCON_UTF8("Mongo's Pizza"));

    bson_t opts;
    bson_init(&opts);
    bson_append_bool(&opts, "ordered", -1, false);

    if (!mongoc_collection_insert_many(collection, (const bson_t **)docs, 2, &opts, NULL, &error)) {
        fprintf(stderr, "Insert many failed: %s\n", error.message);
    }
    bson_destroy(docs[0]);
    bson_destroy(docs[1]);
    bson_destroy(&opts);
    // end-insert-many

    // Inserts multiple documents and instructs the insert operation to skip document-level validation
    // start-modify
    bson_t *docs2[3];
    docs2[0] = BCON_NEW("name", BCON_UTF8("Mongo's Burgers"));
    docs2[1] = BCON_NEW("name", BCON_UTF8("Mongo's Pizza"));
    docs2[2] = BCON_NEW("name", BCON_UTF8("Mongo's Tacos"));

    bson_t opts2;
    bson_init(&opts2);
    bson_append_bool(&opts2, "bypassDocumentValidation", -1, true);

    if (!mongoc_collection_insert_many(collection, (const bson_t **)docs2, 3, &opts2, NULL, &error)) {
        fprintf(stderr, "Insert many with bypass validation failed: %s\n", error.message);
    }
    bson_destroy(docs2[0]);
    bson_destroy(docs2[1]);
    bson_destroy(docs2[2]);
    bson_destroy(&opts2);
    // end-modify

    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_uri_destroy(uri);
    mongoc_cleanup();

    return EXIT_SUCCESS;
}