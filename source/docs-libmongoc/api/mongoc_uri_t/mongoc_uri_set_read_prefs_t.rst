.. _mongoc_uri_set_read_prefs_t

mongoc_uri_set_read_prefs_t()
=============================

Synopsis
--------

.. code-block:: c

  void
  mongoc_uri_set_read_prefs_t (mongoc_uri_t *uri,
                               const mongoc_read_prefs_t *prefs);

Parameters
----------

* ``uri``: A :ref:`mongoc_uri_t`.
* ``rc``: A :ref:`mongoc_read_prefs_t`.

Description
-----------

Sets a MongoDB URI's read preferences, after the URI has been parsed from a string.

