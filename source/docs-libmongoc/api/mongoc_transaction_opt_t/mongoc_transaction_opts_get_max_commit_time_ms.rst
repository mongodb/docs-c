.. _mongoc_transaction_opts_get_max_commit_time_ms

mongoc_transaction_opts_get_max_commit_time_ms()
================================================

Synopsis
--------

.. code-block:: c

  int64_t
  mongoc_transaction_opts_get_max_commit_time_ms (const mongoc_transaction_opt_t *opts);

Return the transaction options' max commit time, in milliseconds. See :ref:`mongoc_transaction_opts_set_max_commit_time_ms()`.

Parameters
----------

* ``opts``: A :ref:`mongoc_transaction_opt_t`.

.. include:: includes/seealso/session.txt
