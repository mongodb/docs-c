.. _mongoc_client_encryption_encrypt_expression

mongoc_client_encryption_encrypt_expression()
=============================================

Synopsis
--------

.. code-block:: c

   bool
   mongoc_client_encryption_encrypt_expression (
      mongoc_client_encryption_t *client_encryption,
      const bson_t *expr,
      mongoc_client_encryption_encrypt_opts_t *opts,
      bson_t *expr_out,
      bson_error_t *error);

.. important:: The {+range-is-experimental+} {+api-is-experimental+}
.. versionadded:: 1.24.0

Encrypts a Match Expression or Aggregate Expression to query a range index.

To query with a ``RangePreview`` encrypted payload, use a
:ref:`mongoc_client_t` configured with
:ref:`mongoc_auto_encryption_opts_t`. The
:ref:`mongoc_auto_encryption_opts_t` may be configured to bypass query
analysis with :ref:`mongoc_auto_encryption_opts_set_bypass_query_analysis`.
The :ref:`mongoc_auto_encryption_opts_t` must not be configured to bypass
automatic encryption with
:ref:`mongoc_auto_encryption_opts_set_bypass_auto_encryption`. 

To query with a ``RangePreview`` payload, ``expr`` must be one of the following forms: 

#. A Match Expression of the following form: 

   .. code-block:: javascript
   
      // $gt may also be $gte. $lt may also be $lte.
      // Can include one of $gt/$gte/$lt/$lte. It is not required to include both.
      {"$and": [{"<field>": {"$gt": "<value1>"}}, {"<field>": {"$lt": "<value2>" }}]}

#. An Aggregation Expression of this form: 

   .. code-block:: javascript
   
      // $gt may also be $gte. $lt may also be $lte
      // Can include one of $gt/$gte/$lt/$lte. It is not required to include both.
      {"$and": [{"$gt": ["<fieldpath>", "<value1>"]}, {"$lt": ["<fieldpath>", "<value2>"]}]

Parameters
----------

* ``client_encryption``: A :ref:`mongoc_client_encryption_t`
* ``expr``: The expression to encrypt.
* ``opts``: A :ref:`mongoc_client_encryption_encrypt_opts_t`.
* ``expr_out``: A :ref:`bson_t` for the resulting encrypted expression. ``expr_out`` is always initialized (even on failure). Caller must call :ref:`bson_destroy()` to free.
* ``error``: A :ref:`bson_error_t` set on failure.

Returns
-------

Returns ``true`` if successful. Returns ``false`` and sets ``error`` otherwise.

.. seealso::

  | :ref:`mongoc_client_encryption_encrypt_opts_t`

  | :ref:`mongoc_client_enable_auto_encryption()`

  | :ref:`mongoc_client_encryption_decrypt()`

