.. _mongoc_database_copy

mongoc_database_copy()
======================

Synopsis
--------

.. code-block:: c

  mongoc_database_t *
  mongoc_database_copy (mongoc_database_t *database) BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``database``: A :ref:`mongoc_database_t`.

Description
-----------

Performs a deep copy of the ``database`` struct and its configuration. Useful if you intend to call :ref:`mongoc_database_set_write_concern`, :ref:`mongoc_database_set_read_prefs`, or :ref:`mongoc_database_set_read_concern`, and want to preserve an unaltered copy of the struct.

Returns
-------

A newly allocated :ref:`mongoc_database_t` that should be freed with :ref:`mongoc_database_destroy()` when no longer in use.

