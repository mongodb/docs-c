.. _mongoc_cursor_destroy

mongoc_cursor_destroy()
=======================

Synopsis
--------

.. code-block:: c

  void
  mongoc_cursor_destroy (mongoc_cursor_t *cursor);

Parameters
----------

* ``cursor``: A :ref:`mongoc_cursor_t`.

Description
-----------

Frees a :ref:`mongoc_cursor_t` and releases all associated resources. If a server-side cursor has been allocated, it will be released as well. Does nothing if ``cursor`` is NULL.
