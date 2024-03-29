.. _mongoc_client_pool_new

mongoc_client_pool_new()
========================

Synopsis
--------

.. code-block:: c

  mongoc_client_pool_t *
  mongoc_client_pool_new (const mongoc_uri_t *uri) BSON_GNUC_WARN_UNUSED_RESULT;

This function creates a new :ref:`mongoc_client_pool_t` using the :ref:`mongoc_uri_t` provided.

Parameters
----------

* ``uri``: A :ref:`mongoc_uri_t`.

Returns
-------

A newly allocated :ref:`mongoc_client_pool_t` that should be freed with :ref:`mongoc_client_pool_destroy()` when no longer in use. On error, ``NULL`` is returned and an error may be logged.

.. seealso::

  | :ref:`mongoc_client_pool_new_with_error()`

