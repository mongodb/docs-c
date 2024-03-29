.. _mongoc_optional_t

mongoc_optional_t
=================

A struct to store optional boolean values.

Synopsis
--------

Used to specify optional boolean flags, which may remain unset.

This is used within :ref:`mongoc_server_api_t` to track whether a flag was explicitly set.

Functions
---------

.. toctree::
  :titlesonly:
  :maxdepth: 1

  /mongoc_optional_t/mongoc_optional_copy
  /mongoc_optional_t/mongoc_optional_init
  /mongoc_optional_t/mongoc_optional_is_set
  /mongoc_optional_t/mongoc_optional_set_value
  /mongoc_optional_t/mongoc_optional_value
