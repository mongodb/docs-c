.. _mongoc_client_start_session

mongoc_client_start_session()
=============================

Synopsis
--------

.. code-block:: c

  mongoc_client_session_t *
  mongoc_client_start_session (mongoc_client_t *client,
                               mongoc_session_opt_t *opts,
                               bson_error_t *error)

Create a session for a sequence of operations.

.. include:: includes/session-lifecycle.txt

Parameters
----------

* ``client``: A :ref:`mongoc_client_t`.
* ``opts``: An optional :ref:`mongoc_session_opt_t`.
* ``error``: A :ref:`bson:bson_error_t`.

Returns
-------

If successful, this function returns a newly allocated :ref:`mongoc_client_session_t` that should be freed with :ref:`mongoc_client_session_destroy()` when no longer in use. On error, returns NULL and sets ``error``.

Errors
------

This function can fail if the driver is not built with crypto support, if ``opts`` is misconfigured, or if the session is configured with options that the server does not support.

.. include:: includes/seealso/session.txt
