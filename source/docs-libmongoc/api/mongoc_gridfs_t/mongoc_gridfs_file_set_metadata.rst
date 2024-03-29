.. _mongoc_gridfs_file_set_metadata

mongoc_gridfs_file_set_metadata()
=================================

Synopsis
--------

.. code-block:: c

  void
  mongoc_gridfs_file_set_metadata (mongoc_gridfs_file_t *file,
                                   const bson_t *metadata);

Parameters
----------

* ``file``: A :ref:`mongoc_gridfs_file_t`.
* ``bson``: A :ref:`bson_t` containing metadata for ``file``.

Description
-----------

Sets the metadata associated with ``file``.

You need to call :ref:`mongoc_gridfs_file_save()` to persist this change.

