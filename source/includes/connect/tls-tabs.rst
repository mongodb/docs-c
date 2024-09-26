.. tabs::

   .. tab:: Connection String
      :tabid: connectionstring

      .. code-block:: c

         char *uri = "mongodb+srv://<db_username>:<db_password>@<hostname/port>/?replicaSet=myRepl&tls=true";
         client = mongoc_client_new (uri);

   .. tab:: MongoC URI Options
      :tabid: mongocurioptions

      .. code-block:: c

         mongoc_uri_t *uri = mongoc_uri_new ("mongodb://localhost:27017/");
         mongoc_uri_set_option_as_bool (uri, MONGOC_URI_TLS, true);

         mongoc_client_t *client = mongoc_client_new_from_uri (uri);