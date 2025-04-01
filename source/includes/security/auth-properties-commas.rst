.. important::

   You cannot pass values containing the comma (``,``) character to the ``authMechanismProperties`` 
   connection string option. To specify a value that contains a comma, use the
   `mongoc_uri_set_mechanism_properties() <{+api-libmongoc+}mongoc_uri_set_mechanism_properties.html>`__
   method to set the ``authMechanismProperties`` option.