.. _mongoc_client_encryption_encrypt_range_opts_set_max

mongoc_client_encryption_encrypt_range_opts_set_max()
=====================================================

Synopsis
--------

.. code-block:: c

    void
    mongoc_client_encryption_encrypt_range_opts_set_max (
         mongoc_client_encryption_encrypt_range_opts_t *range_opts,
         const bson_value_t *max);

.. important:: The {+range-is-experimental+} {+api-is-experimental+}
.. versionadded:: 1.24.0

Sets the maximum value of the range for explicit encryption.
Only applies when the algorithm set by :ref:`mongoc_client_encryption_encrypt_opts_set_algorithm()` is "RangePreview".
It is an error to set maximum when algorithm is not "RangePreview".

The maximum must match the value set in the encryptedFields of the destination collection.
It is an error to set a different value.

For double and decimal128 fields, max/max/precision must all be set, or all be unset.

Parameters
----------

* ``range_opts``: A :ref:`mongoc_client_encryption_encrypt_range_opts_t`
* ``max``: The maximum bson value of the range.

.. seealso::

  | :ref:`mongoc_client_encryption_encrypt_range_opts_set_precision`
  | :ref:`mongoc_client_encryption_encrypt_range_opts_set_min`
  | :ref:`mongoc_client_encryption_encrypt_range_opts_t`
