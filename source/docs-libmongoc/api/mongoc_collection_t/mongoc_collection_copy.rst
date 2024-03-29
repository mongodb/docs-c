.. _mongoc_collection_copy

mongoc_collection_copy()
========================

Synopsis
--------

.. code-block:: c

  mongoc_collection_t *
  mongoc_collection_copy (mongoc_collection_t *collection)
     BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``collection``: A :ref:`mongoc_collection_t`.

Description
-----------

Performs a deep copy of the ``collection`` struct and its configuration. Useful if you intend to call :ref:`mongoc_collection_set_write_concern`, :ref:`mongoc_collection_set_read_prefs`, or :ref:`mongoc_collection_set_read_concern`, and want to preserve an unaltered copy of the struct.

This function does *not* copy the contents of the collection on the MongoDB server.

Returns
-------

A newly allocated :ref:`mongoc_collection_t` that should be freed with :ref:`mongoc_collection_destroy()` when no longer in use.

