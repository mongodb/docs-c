.. _mongoc_collection_set_read_concern

mongoc_collection_set_read_concern()
====================================

Synopsis
--------

.. code-block:: c

  void
  mongoc_collection_set_read_concern (mongoc_collection_t *collection,
                                      const mongoc_read_concern_t *read_concern);

Parameters
----------

* ``collection``: A :ref:`mongoc_collection_t`.
* ``read_concern``: A :ref:`mongoc_read_concern_t`.

Description
-----------

Sets the read concern to use for operations on ``collection``.

The default read concern is empty: No readConcern is sent to the server unless explicitly configured.

