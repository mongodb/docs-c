.. _mongoc_client_get_read_concern

mongoc_client_get_read_concern()
================================

Synopsis
--------

.. code-block:: c

  const mongoc_read_concern_t *
  mongoc_client_get_read_concern (const mongoc_client_t *client);

Retrieve the default read concern configured for the client instance. The result should not be modified or freed.

Parameters
----------

* ``client``: A :ref:`mongoc_client_t`.

Returns
-------

A :ref:`mongoc_read_concern_t`.

