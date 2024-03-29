.. _mongoc_session_opts_destroy

mongoc_session_opts_destroy()
=============================

Synopsis
--------

.. code-block:: c

  void
  mongoc_session_opts_destroy (mongoc_session_opt_t *opts);

Free a :ref:`mongoc_session_opt_t`. Does nothing if ``opts`` is NULL.

Parameters
----------

* ``opts``: A :ref:`mongoc_session_opt_t`.

Example
-------

See the example code for :ref:`mongoc_session_opts_set_causal_consistency`.

.. include:: includes/seealso/session.txt
