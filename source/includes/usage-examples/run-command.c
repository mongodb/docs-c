#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    char *str;
    bson_error_t error;

    mongoc_init ();

    client =
        mongoc_client_new ("<connection string URI>");
    collection = mongoc_client_get_collection (client, "<database name>", "collection name");

    {
        // start-execute-command
        bson_t *command, reply;
        bson_error_t error;
        bool retval;
    
        command = BCON_NEW ("hello", BCON_INT32 (1));
        retval = mongoc_client_command_simple (client, "admin", command, NULL, &reply, &error);
    
        if (!retval) {
            fprintf (stderr, "Failed to run command: %s\n", error.message);
        } else {
         char *str = bson_as_canonical_extended_json (&reply, NULL);
            printf ("%s\n", str);
            bson_free (str);
        }
    
        bson_destroy (command);
        bson_destroy (&reply);
        // end-execute-command
    }

    {
        // start-execute-command-with-options
        bson_t *command;
        bson_t *opts;
        bson_t reply;
        bson_error_t error;
        bool retval;

        command = BCON_NEW(
            "grantRolesToUser", BCON_UTF8("user011"),
            "roles", "[", BCON_UTF8("readWrite"), "]"
        );

        opts = BCON_NEW(
            "writeConcern", "{",
                "w", BCON_UTF8("majority"),
            "}"
        );

        retval = mongoc_client_command_with_opts(client, "admin", command, opts, &reply, &error);

        if (!retval) {
            fprintf(stderr, "Failed to run command: %s\n", error.message);
        } else {
            char *str = bson_as_canonical_extended_json(&reply, NULL);
            printf("Command Result: %s\n", str);
            bson_free(str);
        }

        bson_destroy(command);
        bson_destroy(opts);
        bson_destroy(&reply)
        // end-execute-command-with-options
    }

    {
        // start-run-command-example
        bson_t *cmd;
        bson_t *opts;
        mongoc_write_concern_t *write_concern;
        mongoc_read_prefs_t *read_prefs;
        mongoc_read_concern_t *read_concern;
        bson_t reply;
        bson_error_t error;
        char *json;

        cmd = BCON_NEW ("cloneCollectionAsCapped",
                BCON_UTF8 ("my_collection"),
                "toCollection",
                BCON_UTF8 ("my_capped_collection"),
                "size",
                BCON_INT64 (1024 * 1024));

        /* Includes write concern "majority" in command options */
        write_concern = mongoc_write_concern_new ();
        mongoc_write_concern_set_wmajority (write_concern, 10000 /* wtimeoutMS */);
        opts = bson_new ();
        mongoc_write_concern_append (write_concern, opts);

        if (mongoc_client_write_command_with_opts (client, "test", cmd, opts, &reply, &error)) {
            json = bson_as_canonical_extended_json (&reply, NULL);
            printf ("cloneCollectionAsCapped: %s\n", json);
            bson_free (json);
        } else {
            fprintf (stderr, "cloneCollectionAsCapped: %s\n", error.message);
        }

        bson_free (cmd);
        bson_free (opts);

        /* Defines distinct values of "x" in "my_collection" where "y" sorts after "one" */
        cmd = BCON_NEW ("distinct",
                BCON_UTF8 ("my_collection"),
                "key",
                BCON_UTF8 ("x"),
                "query",
                "{",
                "y",
                "{",
                "$gt",
                BCON_UTF8 ("one"),
                "}",
                "}");

        read_prefs = mongoc_read_prefs_new (MONGOC_READ_SECONDARY);

        /* Specifies "One" sorts after "one" to override default behavior */
        opts = BCON_NEW ("collation", "{", "locale", BCON_UTF8 ("en_US"), "caseFirst", BCON_UTF8 ("lower"), "}");

        /* Adds a read concern to "opts" */
        read_concern = mongoc_read_concern_new ();
        mongoc_read_concern_set_level (read_concern, MONGOC_READ_CONCERN_LEVEL_MAJORITY);
        mongoc_read_concern_append (read_concern, opts);

        if (mongoc_client_read_command_with_opts (client, "test", cmd, read_prefs, opts, &reply, &error)) {
            json = bson_as_canonical_extended_json (&reply, NULL);
            printf ("distinct: %s\n", json);
            bson_free (json);
        } else {
            fprintf (stderr, "distinct: %s\n", error.message);
        }

        bson_destroy (cmd);
        bson_destroy (opts);
        bson_destroy (&reply);
        mongoc_read_prefs_destroy (read_prefs);
        mongoc_read_concern_destroy (read_concern);
        mongoc_write_concern_destroy (write_concern);
        // end-run-command-example
    }

    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}