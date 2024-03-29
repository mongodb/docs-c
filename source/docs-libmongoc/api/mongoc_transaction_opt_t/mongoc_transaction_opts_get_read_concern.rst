.. _mongoc_transaction_opts_get_read_concern

mongoc_transaction_opts_get_read_concern()
==========================================

Synopsis
--------

.. code-block:: c

  const mongoc_read_concern_t *
  mongoc_transaction_opts_get_read_concern (const mongoc_transaction_opt_t *opts);

Return the transaction options' :ref:`mongoc_read_concern_t`. See :ref:`mongoc_transaction_opts_set_read_concern()`.

Parameters
----------

* ``opts``: A :ref:`mongoc_transaction_opt_t`.

Returns
-------

A :ref:`mongoc_read_concern_t` that is valid only for the lifetime of ``opts``.

.. include:: includes/seealso/session.txt
