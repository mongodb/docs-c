.. _mongoc_read_prefs_get_mode

mongoc_read_prefs_get_mode()
============================

Synopsis
--------

.. code-block:: c

  mongoc_read_mode_t
  mongoc_read_prefs_get_mode (const mongoc_read_prefs_t *read_prefs);

Parameters
----------

* ``read_prefs``: A :ref:`mongoc_read_prefs_t`.

Description
-----------

Fetches the :ref:`mongoc_read_mode_t` for the read preference.

Returns
-------

Returns the read preference mode.

