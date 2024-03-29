.. _mongoc_gridfs_bucket_open_download_stream

mongoc_gridfs_bucket_open_download_stream()
===========================================

Synopsis
--------

.. code-block:: c

  mongoc_stream_t *
  mongoc_gridfs_bucket_open_download_stream (mongoc_gridfs_bucket_t *bucket,
                                             const bson_value_t *file_id,
                                             bson_error_t *error)
     BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``bucket``: A :ref:`mongoc_gridfs_bucket_t`.
* ``file_id``: A :ref:`bson_value_t` of the id of the file to download.
* ``error``: A :ref:`bson_error_t` to receive any error or ``NULL``.

Description
-----------

Opens a stream for reading a file from GridFS.

Returns
-------

A :ref:`mongoc_stream_t` that can be read from or ``NULL`` on failure. Errors on this stream can be retrieved with :ref:`mongoc_gridfs_bucket_stream_error()`.

.. seealso::

  | :ref:`mongoc_gridfs_bucket_stream_error()`

