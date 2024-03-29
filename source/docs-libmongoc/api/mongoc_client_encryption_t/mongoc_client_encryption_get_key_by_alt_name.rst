.. _mongoc_client_encryption_get_key_by_alt_name

mongoc_client_encryption_get_key_by_alt_name()
==============================================

Synopsis
--------

.. code-block:: c

   bool
   mongoc_client_encryption_get_key_by_alt_name (
      mongoc_client_encryption_t *client_encryption,
      const char *keyaltname,
      bson_value_t *key_doc,
      bson_error_t *error);

Get a key document in the key vault collection that has the given ``keyaltname``.

Parameters
----------

* ``client_encryption``: A :ref:`mongoc_client_encryption_t`.
* ``keyaltname``: The key alternate name of the key to get.
* ``key_doc``: Optional. An uninitialized :ref:`bson_t` set to the resulting key document, or an empty document if the key does not exist. Must be freed by :ref:`bson_value_destroy`.
* ``error``: Optional. :ref:`bson_error_t`.

Returns
-------

Returns ``true`` if successful. Returns ``false`` and sets ``error`` otherwise.

.. seealso::

  | :ref:`mongoc_client_encryption_t`
