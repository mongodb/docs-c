.. _mongoc_read_prefs_get_hedge

mongoc_read_prefs_get_hedge()
=============================

Synopsis
--------

.. code-block:: c

  const bson_t *
  mongoc_read_prefs_get_hedge (const mongoc_read_prefs_t *read_prefs);

Parameters
----------

* ``read_prefs``: A :ref:`mongoc_read_prefs_t`.

Description
-----------

Fetches any read preference hedge document that has been registered.

Returns
-------

Returns a :ref:`bson_t` that should not be modified or freed.

