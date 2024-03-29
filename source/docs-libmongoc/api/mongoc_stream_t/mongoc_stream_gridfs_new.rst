.. _mongoc_stream_gridfs_new

mongoc_stream_gridfs_new()
==========================

Synopsis
--------

.. code-block:: c

  mongoc_stream_t *
  mongoc_stream_gridfs_new (mongoc_gridfs_file_t *file)
     BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``file``: A :ref:`mongoc_gridfs_file_t`.

This function shall create a new :ref:`mongoc_stream_t` to read from and write to a GridFS file. GridFS files are created with :ref:`mongoc_gridfs_create_file` or :ref:`mongoc_gridfs_create_file_from_stream`.

This function does not transfer ownership of ``file``. Therefore, ``file`` must remain valid for the lifetime of this stream.

Returns
-------

A newly allocated :ref:`mongoc_stream_t` if successful, otherwise ``NULL``.

Note, the returned stream ignores read and write timeouts passed to :ref:`mongoc_stream_readv`, :ref:`mongoc_stream_writev`, and so on. It uses the "socketTimeoutMS" and "connectTimeoutMS" values from the MongoDB URI.
