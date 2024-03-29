.. _mongoc_collection_destroy

mongoc_collection_destroy()
===========================

Synopsis
--------

.. code-block:: c

  void
  mongoc_collection_destroy (mongoc_collection_t *collection);

Parameters
----------

* ``collection``: A :ref:`mongoc_collection_t`.

Description
-----------

This function shall destroy a :ref:`mongoc_collection_t` and its associated resources. Does nothing if ``collection`` is NULL.

.. warning::

  Always destroy a :ref:`mongoc_cursor_t` created from a collection before destroying the collection.

