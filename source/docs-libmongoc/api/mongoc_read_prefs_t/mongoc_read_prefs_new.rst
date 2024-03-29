.. _mongoc_read_prefs_new

mongoc_read_prefs_new()
=======================

Synopsis
--------

.. code-block:: c

  mongoc_read_prefs_t *
  mongoc_read_prefs_new (mongoc_read_mode_t read_mode)
     BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``read_mode``: A :ref:`mongoc_read_mode_t`.

Description
-----------

Creates a new :ref:`mongoc_read_prefs_t` using the mode specified.

Returns
-------

Returns a newly allocated :ref:`mongoc_read_prefs_t` that should be freed with :ref:`mongoc_read_prefs_destroy()`.

