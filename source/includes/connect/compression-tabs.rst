.. tabs::

   .. tab:: Connection String
      :tabid: connectionstring

      .. code-block:: c

         mongoc_client_t *client = mongoc_client_new("mongodb://<db_username>:<db_password>@<hostname>/?compressors=snappy,zlib,zstd");

         // Do database work here

         mongoc_client_destroy (client);

   .. tab:: MongoC URI Options
      :tabid: mongocurioptions

      .. code-block:: c

         mongoc_uri_t *uri = mongoc_uri_new ("mongodb://localhost:27017");  
         mongoc_uri_set_compressors (uri, "snappy,zlib,zstd");

         mongoc_client_t *client = mongoc_client_new_from_uri (uri);

         // Do database work here

         mongoc_client_destroy (client);
         mongoc_uri_destroy (uri);