.. _mongoc_client_encryption_opts_set_keyvault_client

mongoc_client_encryption_opts_set_keyvault_client()
===================================================

Synopsis
--------

.. code-block:: c

   void
   mongoc_client_encryption_opts_set_keyvault_client (
      mongoc_client_encryption_opts_t *opts,
      mongoc_client_t *keyvault_client);

Set the :ref:`mongoc_client_t` to use during key creation and key lookup for encryption and decryption. This may be either a single-threaded or multi-threaded client (i.e. a client obtained from a :ref:`mongoc_client_pool_t`).

Parameters
----------

* ``opts``: A :ref:`mongoc_client_encryption_opts_t`.
* ``client``: A :ref:`mongoc_client_t` to use for key lookup and creation. This ``client`` MUST outlive any :ref:`mongoc_client_encryption_t` configured to use it with :ref:`mongoc_client_encryption_new()`.

.. seealso::

  | :ref:`mongoc_client_encryption_new()`

  | :doc:`in-use-encryption`

