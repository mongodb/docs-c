.. _mongoc_gridfs_get_files

mongoc_gridfs_get_files()
=========================

Synopsis
--------

.. code-block:: c

  mongoc_collection_t *
  mongoc_gridfs_get_files (mongoc_gridfs_t *gridfs);

Parameters
----------

* ``gridfs``: A :ref:`mongoc_gridfs_t`.

Description
-----------

Retrieves the :ref:`mongoc_collection_t` containing the file metadata for GridFS. This instance is owned by the :ref:`mongoc_gridfs_t` and should not be modified or freed.

Returns
-------

Returns a :ref:`mongoc_collection_t` that should not be modified or freed.

