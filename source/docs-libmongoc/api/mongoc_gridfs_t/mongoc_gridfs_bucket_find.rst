.. _mongoc_gridfs_bucket_find

mongoc_gridfs_bucket_find()
===========================

Synopsis
--------

.. code-block:: c

  mongoc_cursor_t *
  mongoc_gridfs_bucket_find (mongoc_gridfs_bucket_t *bucket,
                             const bson_t *filter,
                             const bson_t *opts) BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``bucket``: A :ref:`mongoc_gridfs_bucket_t`.
* ``filter``: A :ref:`bson_t` containing the query to execute.
* ``opts``: A :ref:`bson_t` for query options, supporting all options in :ref:`mongoc_collection_find_with_opts()` excluding ``sessionId``.

Description
-----------

Finds file documents from the bucket's ``files`` collection.

.. include:: includes/retryable-read.txt

Returns
-------
A newly allocated :ref:`mongoc_cursor_t` that must be freed with :ref:`mongoc_cursor_destroy()`.
