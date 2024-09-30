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
        mongoc_client_get_collection (client, "sample_restaurants", "restaurants");

    {
        // start-transaction
        bson_error_t error;
        mongoc_client_session_t *session = mongoc_client_start_session (client, NULL, &error);
        if (!session) {
            fprintf (stderr, "Could not start session: %s\n", error.message);
            return EXIT_FAILURE;
        }

        // Start the transaction
        if (!mongoc_client_session_start_transaction (session, NULL, &error)) {
            fprintf (stderr, "Could not start transaction: %s\n", error.message);
            return EXIT_FAILURE;
        }

        // Create documents to insert
        size_t num_docs = 2;
        bson_t *docs[num_docs];
        docs[0] = BCON_NEW ("name", BCON_UTF8 ("Mongo's Burgers"));
        docs[1] = BCON_NEW ("name", BCON_UTF8 ("Mongo's Pizza"));

        // Append the session to the insert options
        bson_t *insert_opts = bson_new ();
        if (!mongoc_client_session_append (session, insert_opts, &error)) {
            fprintf (stderr, "Could not append session to opts: %s\n", error.message);
            return EXIT_FAILURE;
        }

        // Insert the documents
        if (!mongoc_collection_insert_many (collection, (const bson_t **) docs, num_docs, insert_opts, NULL, &error)) {
            fprintf (stderr, "Insert many operation failed: %s\n", error.message);
            mongoc_client_session_abort_transaction (session, &error);
            return EXIT_FAILURE;
        }

        // Commit the transaction
        if (!mongoc_client_session_commit_transaction (session, NULL, &error)) {
            fprintf (stderr, "Failed to commit transaction: %s\n", error.message);
            return EXIT_FAILURE;
        }

        // Cleanup
        for (size_t i = 0; i < num_docs; i++) {
            bson_destroy (docs[i]);
        }
        mongoc_client_session_destroy (session);
        bson_destroy (insert_opts);
        // end-transaction
    }

    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}