.. _mongoc_client_encryption_delete_key

mongoc_client_encryption_delete_key()
=====================================

Synopsis
--------

.. code-block:: c

   bool
   mongoc_client_encryption_delete_key (
      mongoc_client_encryption_t *client_encryption,
      const bson_value_t *keyid,
      bson_t *reply,
      bson_error_t *error);

Delete a key document in the key vault collection that has the given ``keyid``.

Parameters
----------

* ``client_encryption``: A :ref:`mongoc_client_encryption_t`.
* ``keyid``: The UUID (BSON binary subtype 0x04) of the key to delete.
* ``reply``: A ``bson_t-opt-storage-ptr`` to contain the results.
* ``error``: Optional. :ref:`bson_error_t`.

Returns
-------

Returns ``true`` if successful. Returns ``false`` and sets ``error`` otherwise.

.. seealso::

  | :ref:`mongoc_client_encryption_t`
  | :ref:`mongoc_client_encryption_create_datakey`
