.. _mongoc_gridfs_file_get_filename

mongoc_gridfs_file_get_filename()
=================================

Synopsis
--------

.. code-block:: c

  const char *
  mongoc_gridfs_file_get_filename (mongoc_gridfs_file_t *file);

Parameters
----------

* ``file``: A :ref:`mongoc_gridfs_file_t`.

Description
-----------

Fetches the filename for the given gridfs file.

Returns
-------

A string which should not be modified or freed.

