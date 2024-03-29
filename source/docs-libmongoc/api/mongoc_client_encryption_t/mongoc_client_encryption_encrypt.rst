.. _mongoc_client_encryption_encrypt

mongoc_client_encryption_encrypt()
==================================

Synopsis
--------

.. code-block:: c

   bool
   mongoc_client_encryption_encrypt (
      mongoc_client_encryption_t *client_encryption,
      const bson_value_t *value,
      mongoc_client_encryption_encrypt_opts_t *opts,
      bson_value_t *ciphertext,
      bson_error_t *error);

Performs explicit encryption.

``ciphertext`` is always initialized (even on failure). Caller must call :ref:`bson_value_destroy()` to free.

To insert or query with an "Indexed" or "RangePreview" encrypted payload, use a
:ref:`mongoc_client_t` configured with
:ref:`mongoc_auto_encryption_opts_t`. The
:ref:`mongoc_auto_encryption_opts_t` may be configured to bypass query
analysis with :ref:`mongoc_auto_encryption_opts_set_bypass_query_analysis`.
The :ref:`mongoc_auto_encryption_opts_t` must not be configured to bypass
automatic encryption with
:ref:`mongoc_auto_encryption_opts_set_bypass_auto_encryption`. **Note** that
the ``"RangePreview"`` payload type |qenc:is-experimental|. The {+range-is-experimental+} 

To insert with a ``RangePreview`` payload 
:ref:`mongoc_client_encryption_encrypt_range_opts_t` must be set in ``opts``.

To query with a ``RangePreview`` payload, use :ref:`mongoc_client_encryption_encrypt_expression()`

**NOTE** that the {+range-is-experimental+}

Parameters
----------

* ``client_encryption``: A :ref:`mongoc_client_encryption_t`
* ``value``: The value to encrypt.
* ``opts``: A :ref:`mongoc_client_encryption_encrypt_opts_t`.
* ``ciphertext``: A :ref:`bson_value_t` for the resulting ciphertext (a BSON binary with subtype 6).
* ``error``: A :ref:`bson_error_t` set on failure.

Returns
-------

Returns ``true`` if successful. Returns ``false`` and sets ``error`` otherwise.

.. seealso::

  | :ref:`mongoc_client_encryption_encrypt_opts_t`

  | :ref:`mongoc_client_enable_auto_encryption()`

  | :ref:`mongoc_client_encryption_decrypt()`

  | :ref:`mongoc_client_encryption_encrypt_expression()`
