.. _mongoc_client_session_get_transaction_state

mongoc_client_session_get_transaction_state()
=============================================

Synopsis
--------

.. code-block:: c

  mongoc_transaction_state_t
  mongoc_client_session_get_transaction_state (const mongoc_client_session_t *session);

Returns the current transaction state for this session.

Parameters
----------

* ``session``: A :ref:`mongoc_client_session_t`.

Return
------

Returns a :ref:`mongoc_transaction_state_t` that represents the current transaction state.
