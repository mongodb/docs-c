.. _mongoc_session_opts_get_snapshot

mongoc_session_opts_get_snapshot()
==================================

Synopsis
--------

.. code-block:: c

  bool
  mongoc_session_opts_get_snapshot (const mongoc_session_opt_t *opts);

Return true if this session is configured for snapshot reads, false by default. See :ref:`mongoc_session_opts_set_snapshot()`.

Parameters
----------

* ``opts``: A :ref:`mongoc_session_opt_t`.

.. include:: includes/seealso/session.txt