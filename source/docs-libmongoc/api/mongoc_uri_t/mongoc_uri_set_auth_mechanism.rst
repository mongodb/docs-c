.. _mongoc_uri_set_auth_mechanism

mongoc_uri_set_auth_mechanism()
===============================

Synopsis
--------

.. code-block:: c

  bool
  mongoc_uri_set_auth_mechanism (mongoc_uri_t *uri, const char *value);

Parameters
----------

* ``uri``: A :ref:`mongoc_uri_t`.
* ``value``: The new "authMechanism" value.

Description
-----------

Sets the "authMechanism" URI option, such as "SCRAM-SHA-1" or "GSSAPI", after the URI has been parsed from a string.

Updates the option in-place if already set, otherwise appends it to the URI's :ref:`bson_t` of options.

Returns
-------

Returns false if the option cannot be set, for example if ``value`` is not valid UTF-8.

.. include:: includes/seealso/authmechanism.txt
