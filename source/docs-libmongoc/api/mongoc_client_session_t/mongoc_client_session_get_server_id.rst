.. _mongoc_client_session_get_server_id

mongoc_client_session_get_server_id()
=====================================

Synopsis
--------

.. code-block:: c

  uint32_t
  mongoc_client_session_get_server_id (const mongoc_client_session_t *session);

Get the "server ID" of the ``mongos`` this :ref:`mongoc_client_session_t` is pinned to.

Parameters
----------

* ``session``: A :ref:`mongoc_client_session_t`.

Returns
-------

A server ID or ``0`` if this :ref:`mongoc_client_session_t` is not pinned.

.. include:: includes/seealso/session.txt

