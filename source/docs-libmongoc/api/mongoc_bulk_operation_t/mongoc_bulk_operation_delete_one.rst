.. _mongoc_bulk_operation_delete_one

mongoc_bulk_operation_delete_one()
==================================

.. warning::
   .. deprecated:: 0.96.0

      This function is deprecated and should not be used in new code.

      Please use :ref:`mongoc_bulk_operation_remove_one()` in new code.

Synopsis
--------

.. code-block:: c

  void
  mongoc_bulk_operation_delete_one (mongoc_bulk_operation_t *bulk,
                                    const bson_t *selector)
    BSON_GNUC_DEPRECATED_FOR (mongoc_bulk_operation_remove_one);

Delete a single document as part of a bulk operation. This only queues the operation. To execute it, call :ref:`mongoc_bulk_operation_execute()`.

Parameters
----------

* ``bulk``: A :ref:`mongoc_bulk_operation_t`.
* ``selector``: A :ref:`bson_t`.

Errors
------

Errors are propagated via :ref:`mongoc_bulk_operation_execute()`.

.. seealso::

  | :ref:`mongoc_bulk_operation_remove_one_with_opts()`

  | :ref:`mongoc_bulk_operation_remove_many_with_opts()`

