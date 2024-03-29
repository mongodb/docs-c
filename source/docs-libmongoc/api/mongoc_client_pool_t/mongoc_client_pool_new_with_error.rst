.. _mongoc_client_pool_new_with_error

mongoc_client_pool_new_with_error()
===================================

Synopsis
--------

.. code-block:: c

  mongoc_client_pool_t *
  mongoc_client_pool_new_with_error (const mongoc_uri_t *uri,
                                     bson_error_t *error)
     BSON_GNUC_WARN_UNUSED_RESULT;

This function creates a new :ref:`mongoc_client_pool_t` using the :ref:`mongoc_uri_t` provided.

Parameters
----------

* ``uri``: A :ref:`mongoc_uri_t`.
* ``error``: An optional location for a :symbol:`bson_error_t <errors>` or ``NULL``.

Returns
-------

A newly allocated :ref:`mongoc_client_pool_t` that should be freed with :ref:`mongoc_client_pool_destroy()` when no longer in use. On error, ``NULL`` is returned and ``error`` will be populated with the error description.

