.. _mongoc_client_encryption_encrypt_opts_set_keyaltname

mongoc_client_encryption_encrypt_opts_set_keyaltname()
======================================================

Synopsis
--------

.. code-block:: c

   void
   mongoc_client_encryption_encrypt_opts_set_keyaltname (
      mongoc_client_encryption_encrypt_opts_t *opts, const char *keyaltname);

Identifies the data key to use for encryption. This option is mutually exclusive with :ref:`mongoc_client_encryption_encrypt_opts_set_keyid()`. 

Parameters
----------

* ``opts``: A :ref:`mongoc_client_encryption_encrypt_opts_t`
* ``keyaltname``: A string identifying a data key by alternate name.

.. seealso::

  | :ref:`mongoc_client_encryption_encrypt_opts_set_keyid`

  | :ref:`mongoc_client_encryption_datakey_opts_set_keyaltnames`

