.. _mongoc_uri_set_read_concern

mongoc_uri_set_read_concern()
=============================

Synopsis
--------

.. code-block:: c

  void
  mongoc_uri_set_read_concern (mongoc_uri_t *uri,
                               const mongoc_read_concern_t *rc);

Parameters
----------

* ``uri``: A :ref:`mongoc_uri_t`.
* ``rc``: A :ref:`mongoc_read_concern_t`.

Description
-----------

Sets a MongoDB URI's read concern option, after the URI has been parsed from a string.

