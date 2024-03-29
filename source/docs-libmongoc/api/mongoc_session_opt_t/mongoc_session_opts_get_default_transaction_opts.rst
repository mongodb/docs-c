.. _mongoc_session_opts_get_default_transaction_opts

mongoc_session_opts_get_default_transaction_opts()
==================================================

Synopsis
--------

.. code-block:: c

  const mongoc_transaction_opt_t *
  mongoc_session_opts_get_default_transaction_opts (const mongoc_session_opt_t *opts);

The default options for transactions started with this session. See :ref:`mongoc_session_opts_set_default_transaction_opts()`.

Parameters
----------

* ``opts``: A :ref:`mongoc_session_opt_t`.

Returns
-------

A :ref:`mongoc_transaction_opt_t` that is valid only for the lifetime of ``opts``.

.. include:: includes/seealso/session.txt
