.. _mongoc_transaction_opts_new

mongoc_transaction_opts_new()
=============================

Synopsis
--------

.. code-block:: c

  mongoc_transaction_opt_t *
  mongoc_transaction_opts_new (void);

Create a :ref:`mongoc_transaction_opt_t` to configure multi-document transactions.

Returns
-------

A new :ref:`mongoc_transaction_opt_t` that must be freed with :ref:`mongoc_transaction_opts_destroy()`.

.. include:: includes/seealso/session.txt
