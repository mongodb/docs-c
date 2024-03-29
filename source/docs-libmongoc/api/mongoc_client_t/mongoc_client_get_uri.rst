.. _mongoc_client_get_uri

mongoc_client_get_uri()
=======================

Synopsis
--------

.. code-block:: c

  const mongoc_uri_t *
  mongoc_client_get_uri (const mongoc_client_t *client);

Fetches the :ref:`mongoc_uri_t` used to create the client.

Parameters
----------

* ``client``: A :ref:`mongoc_client_t`.

Returns
-------

A :ref:`mongoc_uri_t` that should not be modified or freed.

