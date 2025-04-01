.. important::

   You cannot pass values containing the comma (``,``) character to the ``authMechanismProperties`` 
   connection string option. To specify a ``authMechanismProperties`` value that contains a comma,
   set the option by using the `mongoc_uri_set_mechanism_properties()
   <{+api-libmongoc+}/mongoc_uri_set_mechanism_properties.html>`__ method.