.. _mongoc_client_encryption_opts_set_key_vault_namespace

mongoc_client_encryption_opts_set_keyvault_namespace()
======================================================

Synopsis
--------

.. code-block:: c

   void
   mongoc_client_encryption_opts_set_keyvault_namespace (
      mongoc_client_encryption_opts_t *opts, const char *db, const char *coll);

Set the database and collection name of the key vault. The key vault is the specially designated collection containing encrypted data keys for :doc:`in-use-encryption`.

Parameters
----------

* ``opts``: The :ref:`mongoc_client_encryption_opts_t`
* ``db``: The database name of the key vault collection.
* ``coll``: The collection name of the key vault collection.

.. seealso::

  | :ref:`mongoc_client_encryption_new()`

  | :doc:`in-use-encryption`

