.. _mongoc_bulk_operation_update_one

mongoc_bulk_operation_update_one()
==================================

Synopsis
--------

.. code-block:: c

  void
  mongoc_bulk_operation_update_one (mongoc_bulk_operation_t *bulk,
                                    const bson_t *selector,
                                    const bson_t *document,
                                    bool upsert);

This function queues an update as part of a bulk operation. It will only modify a single document on the MongoDB server. This function does not execute the operation. To execute the entirety of the bulk operation call :ref:`mongoc_bulk_operation_execute()`.

This function is superseded by :ref:`mongoc_bulk_operation_update_one_with_opts()`.

Parameters
----------

* ``bulk``: A :ref:`mongoc_bulk_operation_t`.
* ``selector``: A :ref:`bson_t` that selects which document to remove.
* ``document``: A :ref:`bson_t` containing the update document.
* ``upsert``: ``true`` if an ``upsert`` should be performed.

.. warning::

  ``document`` *must only* contain fields whose key starts with ``$``. See the update document specification for more details.

.. seealso::

  | :ref:`mongoc_bulk_operation_update()`

  | :ref:`mongoc_bulk_operation_update_one_with_opts()`

