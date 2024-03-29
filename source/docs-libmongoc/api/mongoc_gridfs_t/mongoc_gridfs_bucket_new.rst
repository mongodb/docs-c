.. _mongoc_gridfs_bucket_new

mongoc_gridfs_bucket_new()
==========================

Synopsis
--------

.. code-block:: c

  mongoc_gridfs_bucket_t *
  mongoc_gridfs_bucket_new (mongoc_database_t *db,
                            const bson_t *opts,
                            const mongoc_read_prefs_t *read_prefs,
                            bson_error_t* error) BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``db``: A :ref:`mongoc_database_t`.
* ``opts``: A :ref:`bson_t` or ``NULL``
* ``read_prefs``: A :ref:`mongoc_read_prefs_t` used for read operations or ``NULL`` to inherit read preferences from ``db``.
* ``error``: A :ref:`bson_error_t` or ``NULL``.

.. include:: includes/gridfs-bucket-opts.txt

Description
-----------

Creates a new :ref:`mongoc_gridfs_bucket_t`. Use this handle to perform GridFS operations.

Returns
-------

A newly allocated :ref:`mongoc_gridfs_bucket_t` that should be freed with :ref:`mongoc_gridfs_bucket_destroy()` or ``NULL`` on failure.
