.. _mongoc_uri_get_hosts

mongoc_uri_get_hosts()
======================

Synopsis
--------

.. code-block:: c

  const mongoc_host_list_t *
  mongoc_uri_get_hosts (const mongoc_uri_t *uri);

Parameters
----------

* ``uri``: A :ref:`mongoc_uri_t`.

Description
-----------

Fetches a linked list of hosts that were defined in the URI (the comma-separated host section).

Returns
-------

A linked list of :ref:`mongoc_host_list_t` structures that should not be modified or freed. Returns ``NULL`` if this URI's scheme is "mongodb+srv://".
