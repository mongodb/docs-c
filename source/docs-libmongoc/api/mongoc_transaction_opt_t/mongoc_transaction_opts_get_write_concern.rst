.. _mongoc_transaction_opts_get_write_concern

mongoc_transaction_opts_get_write_concern()
===========================================

Synopsis
--------

.. code-block:: c

  const mongoc_write_concern_t *
  mongoc_transaction_opts_get_write_concern (const mongoc_transaction_opt_t *opts);

Return the transaction options' :ref:`mongoc_write_concern_t`. See :ref:`mongoc_transaction_opts_set_write_concern()`.

Parameters
----------

* ``opts``: A :ref:`mongoc_transaction_opt_t`.

Returns
-------

A  :ref:`mongoc_write_concern_t` that is valid only for the lifetime of ``opts``.

.. include:: includes/seealso/session.txt
