.. _mongoc_database_get_read_prefs

mongoc_database_get_read_prefs()
================================

Synopsis
--------

.. code-block:: c

  const mongoc_read_prefs_t *
  mongoc_database_get_read_prefs (const mongoc_database_t *database);

Fetches the default read preferences to use with ``database``.

Parameters
----------

* ``database``: A :ref:`mongoc_database_t`.

Returns
-------

A :ref:`mongoc_write_concern_t` that should not be modified or freed.

