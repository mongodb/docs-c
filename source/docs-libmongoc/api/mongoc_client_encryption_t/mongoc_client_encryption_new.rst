.. _mongoc_client_encryption_new

mongoc_client_encryption_new()
==============================

Synopsis
--------

.. code-block:: c

  mongoc_client_encryption_t *
  mongoc_client_encryption_new (mongoc_client_encryption_opts_t *opts,
                                bson_error_t *error) BSON_GNUC_WARN_UNUSED_RESULT;

Create a new :ref:`mongoc_client_encryption_t`.

Parameters
----------

* ``opts``: A :ref:`mongoc_client_encryption_opts_t`.
* ``error``: A :ref:`bson_error_t`.

Returns
-------

A new :ref:`mongoc_client_encryption_t` that must be freed with :ref:`mongoc_client_encryption_destroy()` if successful. Returns ``NULL`` and sets ``error`` otherwise.

.. seealso::

  | :ref:`mongoc_client_encryption_t`

  | :ref:`mongoc_client_encryption_opts_t`

