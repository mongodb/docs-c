.. _mongoc_stream_file_new

mongoc_stream_file_new()
========================

Synopsis
--------

.. code-block:: c

  mongoc_stream_t *
  mongoc_stream_file_new (int fd) BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``fd``: A UNIX style file-descriptor.

Creates a new :ref:`mongoc_stream_file_t` using the file-descriptor provided.

Returns
-------

``NULL`` upon failure, otherwise a newly allocated :ref:`mongoc_stream_file_t` that should be freed with :ref:`mongoc_stream_destroy()` when no longer in use.

``errno`` is set upon failure.

