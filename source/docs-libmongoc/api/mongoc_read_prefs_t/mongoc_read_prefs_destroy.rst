.. _mongoc_read_prefs_destroy

mongoc_read_prefs_destroy()
===========================

Synopsis
--------

.. code-block:: c

  void
  mongoc_read_prefs_destroy (mongoc_read_prefs_t *read_prefs);

Parameters
----------

* ``read_prefs``: A :ref:`mongoc_read_prefs_t`.

Description
-----------

Frees a read preference and all associated resources. Does nothing if ``read_prefs`` is NULL.
