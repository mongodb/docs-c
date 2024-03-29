.. _mongoc_read_concern_is_default

mongoc_read_concern_is_default()
================================

Synopsis
--------

.. code-block:: c

  bool
  mongoc_read_concern_is_default (mongoc_read_concern_t *read_concern);

Parameters
----------

* ``read_concern``: A pointer to a :ref:`mongoc_read_concern_t`.

Description
-----------

Returns true if ``read_concern`` has not been modified from the default. For example, if no "readConcern" option is set in the MongoDB URI and you have not called :ref:`mongoc_client_set_read_concern()`, then :ref:`mongoc_read_concern_is_default()` is true for the read concern returned by :ref:`mongoc_client_get_read_concern()`.
