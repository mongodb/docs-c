.. _mongoc_client_encryption_encrypt_opts_set_keyid

mongoc_client_encryption_encrypt_opts_set_keyid()
=================================================

Synopsis
--------

.. code-block:: c

   void
   mongoc_client_encryption_encrypt_opts_set_keyid (
      mongoc_client_encryption_encrypt_opts_t *opts, const bson_value_t *keyid);

Identifies the data key to use for encryption. This option is mutually exclusive with :ref:`mongoc_client_encryption_encrypt_opts_set_keyaltname()`. 

Parameters
----------

* ``opts``: A :ref:`mongoc_client_encryption_encrypt_opts_t`
* ``keyid``: The UUID (BSON binary subtype 0x04) corresponding to the ``_id`` of the data key.

.. seealso::

  | :ref:`mongoc_client_encryption_encrypt_opts_set_keyaltname`
