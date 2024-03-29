.. _mongoc_client_encryption_create_datakey

mongoc_client_encryption_create_datakey()
=========================================

Synopsis
--------

.. code-block:: c

   bool
   mongoc_client_encryption_create_datakey (
      mongoc_client_encryption_t *client_encryption,
      const char *kms_provider,
      const mongoc_client_encryption_datakey_opts_t *opts,
      bson_value_t *keyid,
      bson_error_t *error);

Creates a new key document in the key vault collection and sets ``keyid`` to the UUID of the newly created key if ``keyid`` is not NULL. The new key can be used to configure automatic encryption (see :ref:`mongoc_client_enable_auto_encryption()` and :ref:`mongoc_client_pool_enable_auto_encryption()`) or for explicit encryption (see :ref:`mongoc_client_encryption_encrypt()`).

The created key document is inserted into the key vault collection (identified via :ref:`mongoc_client_encryption_opts_set_keyvault_namespace()`) with majority write concern.

``keyid`` is always initialized (even on error). Caller must call :ref:`bson_value_destroy()` on ``keyid`` to free.

Parameters
----------

* ``client_encryption``: A :ref:`mongoc_client_encryption_t`.
* ``kms_provider``: A string identifying the Key Management Service (KMS) provider used to encrypt the datakey (e.g. "aws" or "local").
* ``opts``: A :ref:`mongoc_client_encryption_datakey_opts_t`
* ``keyid``: Optional. An uninitialized :ref:`bson_value_t` set to the UUID (BSON binary subtype 0x04) of the newly created key. Must be freed by :ref:`bson_value_destroy`.
* ``error``: Optional. A :ref:`bson_error_t`.

Returns
-------

Returns ``true`` if successful. Returns ``false`` and sets ``error`` otherwise.

.. seealso::

  | :ref:`mongoc_client_encryption_datakey_opts_t`
