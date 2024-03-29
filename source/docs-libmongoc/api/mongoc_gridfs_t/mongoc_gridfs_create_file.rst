.. _mongoc_gridfs_create_file

mongoc_gridfs_create_file()
===========================

Synopsis
--------

.. code-block:: c

  mongoc_gridfs_file_t *
  mongoc_gridfs_create_file (mongoc_gridfs_t *gridfs,
                             mongoc_gridfs_file_opt_t *opt)
     BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``gridfs``: A :ref:`mongoc_gridfs_t`.
* ``opt``: A :ref:`mongoc_gridfs_file_opt_t` to specify file options.

Description
-----------

This function shall create a new :ref:`mongoc_gridfs_file_t`.

Use :ref:`mongoc_gridfs_file_writev()` to write to the file.

Returns
-------

Returns a newly allocated :ref:`mongoc_gridfs_file_t` that should be freed with :ref:`mongoc_gridfs_file_destroy()`.

