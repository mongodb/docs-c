.. _mongoc_server_api_get_version

mongoc_server_api_get_version()
===============================

Synopsis
--------

.. code-block:: c

  mongoc_server_api_version_t
  mongoc_server_api_get_version (const mongoc_server_api_t *api);

Fetch the declared API version as from a :ref:`mongoc_server_api_t`.

Parameters
----------

* ``api``: A :ref:`mongoc_server_api_t`.

Returns
-------

Returns a :ref:`mongoc_server_api_version_t` with the API version declare in the :ref:`mongoc_server_api_t`.
