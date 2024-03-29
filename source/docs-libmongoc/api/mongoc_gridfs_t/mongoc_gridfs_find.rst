.. _mongoc_gridfs_find

mongoc_gridfs_find()
====================

.. warning::
   .. deprecated:: 1.5.0

      This function is deprecated, use :ref:`mongoc_gridfs_find_with_opts` instead.

Synopsis
--------

.. code-block:: c

  mongoc_gridfs_file_list_t *
  mongoc_gridfs_find (mongoc_gridfs_t *gridfs,
                      const bson_t *query) BSON_GNUC_WARN_UNUSED_RESULT
     BSON_GNUC_DEPRECATED_FOR (mongoc_gridfs_find_with_opts);

Parameters
----------

* ``gridfs``: A :ref:`mongoc_gridfs_t`.
* ``query``: A :ref:`bson_t`.

Description
-----------

Finds all gridfs files matching ``query``. You can iterate the matched gridfs files with the resulting file list.

.. include:: includes/retryable-read.txt

Returns
-------

A newly allocated :ref:`mongoc_gridfs_file_list_t` that should be freed with :ref:`mongoc_gridfs_file_list_destroy()` when no longer in use.

