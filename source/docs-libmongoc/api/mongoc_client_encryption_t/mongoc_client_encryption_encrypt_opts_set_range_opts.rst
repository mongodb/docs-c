.. _mongoc_client_encryption_encrypt_opts_set_range_opts

mongoc_client_encryption_encrypt_opts_set_range_opts()
======================================================

Synopsis
--------

.. code-block:: c

    void
    mongoc_client_encryption_encrypt_opts_set_range_opts (
          mongoc_client_encryption_encrypt_opts_t *opts,
          const mongoc_client_encryption_encrypt_range_opts_t *range_opts);

.. important:: The {+range-is-experimental+} {+api-is-experimental+}
.. versionadded:: 1.24.0

Sets the ``range_opts`` for explicit encryption.
Only applies when the algorithm set by :ref:`mongoc_client_encryption_encrypt_opts_set_algorithm()` is "RangePreview".
It is an error to set ``range_opts`` when algorithm is not "RangePreview".

Parameters
----------

* ``opts``: A :ref:`mongoc_client_encryption_encrypt_opts_t`
* ``range_opts``: A :ref:`mongoc_client_encryption_encrypt_range_opts_t`

.. seealso::

  | :ref:`mongoc_client_encryption_encrypt_range_opts_new`
