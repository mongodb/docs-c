.. _mongoc_client_encryption_rewrap_many_datakey_result_get_bulk_write_result

mongoc_client_encryption_rewrap_many_datakey_result_get_bulk_write_result()
===========================================================================

Synopsis
--------

.. code-block:: c

   const bson_t *
   mongoc_client_encryption_rewrap_many_datakey_result_get_bulk_write_result (
      mongoc_client_encryption_rewrap_many_datakey_result_t *result)
      BSON_GNUC_WARN_UNUSED_RESULT;

Get the bulk write result set by a successful call to :ref:`mongoc_client_encryption_rewrap_many_datakey()`.

Returns ``NULL`` if no bulk write operation was executed or if the bulk write operation was unacknowledged.

Parameters
----------

* ``result``: A :ref:`mongoc_client_encryption_rewrap_many_datakey_result_t`.

Returns
-------

A :ref:`bson_t` that must not be modified or freed if ``result`` is not ``NULL``. Otherwise, returns ``NULL``.

.. seealso::

  | :ref:`mongoc_client_encryption_rewrap_many_datakey()`
