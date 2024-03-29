.. _mongoc_transaction_opts_get_read_prefs

mongoc_transaction_opts_get_read_prefs()
========================================

Synopsis
--------

.. code-block:: c

  const mongoc_read_prefs_t *
  mongoc_transaction_opts_get_read_prefs (const mongoc_transaction_opt_t *opts);

Return the transaction options' :ref:`mongoc_read_prefs_t`. See :ref:`mongoc_transaction_opts_set_read_prefs()`.

Parameters
----------

* ``opts``: A :ref:`mongoc_transaction_opt_t`.

Returns
-------

A :ref:`mongoc_read_prefs_t` that is valid only for the lifetime of ``opts``. 

.. include:: includes/seealso/session.txt
