.. _mongoc_client_session_get_opts

mongoc_client_session_get_opts()
================================

Synopsis
--------

.. code-block:: c

  const mongoc_session_opt_t *
  mongoc_client_session_get_opts (const mongoc_client_session_t *session);

Get a reference to the :ref:`mongoc_session_opt_t` with which this session was configured.

Parameters
----------

* ``session``: A :ref:`mongoc_client_session_t`.

Returns
-------

A :ref:`mongoc_session_opt_t` that is valid only for the lifetime of ``session``.

.. include:: includes/seealso/session.txt
