.. _mongoc_database_get_collection

mongoc_database_get_collection()
================================

Synopsis
--------

.. code-block:: c

  mongoc_collection_t *
  mongoc_database_get_collection (mongoc_database_t *database,
                                  const char *name) BSON_GNUC_WARN_UNUSED_RESULT;

Allocates a new :ref:`mongoc_collection_t` structure for the collection named ``name`` in ``database``.

Returns
-------

A newly allocated :ref:`mongoc_collection_t` that should be freed with :ref:`mongoc_collection_destroy()`.

