.. _mongoc_auto_encryption_opts_set_key_vault_client_pool

mongoc_auto_encryption_opts_set_keyvault_client_pool()
======================================================

Synopsis
--------

.. code-block:: c

   void
   mongoc_auto_encryption_opts_set_keyvault_client_pool (
      mongoc_auto_encryption_opts_t *opts, mongoc_client_pool_t *pool);

Set an optional separate :ref:`mongoc_client_pool_t` to use during key lookup for automatic encryption and decryption. Only applies to automatic encryption on a :ref:`mongoc_client_pool_t`. It is invalid to set this for automatic encryption on a single-threaded :ref:`mongoc_client_t`.

Parameters
----------

* ``opts``: A :ref:`mongoc_auto_encryption_opts_t`.
* ``pool``: A :ref:`mongoc_client_pool_t` to use for key queries. This client pool should *not* have automatic encryption enabled, as it will only execute ``find`` commands against the key vault collection to retrieve keys for automatic encryption and decryption. This ``pool`` MUST outlive any :ref:`mongoc_client_pool_t` which has been enabled to use it through :ref:`mongoc_client_pool_enable_auto_encryption()`.

.. seealso::

  | :ref:`mongoc_client_pool_enable_auto_encryption()`

  | :ref:`mongoc_auto_encryption_opts_set_keyvault_client()`

  | :doc:`in-use-encryption`

