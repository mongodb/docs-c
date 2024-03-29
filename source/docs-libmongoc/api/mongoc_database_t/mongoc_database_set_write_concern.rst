.. _mongoc_database_set_write_concern

mongoc_database_set_write_concern()
===================================

Synopsis
--------

.. code-block:: c

  void
  mongoc_database_set_write_concern (mongoc_database_t *database,
                                     const mongoc_write_concern_t *write_concern);

This function sets the write concern to use on operations performed with ``database``. Collections created with :ref:`mongoc_database_get_collection()` after this call will inherit this write concern.

The default write concern is MONGOC_WRITE_CONCERN_W_DEFAULT: the driver blocks awaiting basic acknowledgement of write operations from MongoDB. This is the correct write concern for the great majority of applications.

Parameters
----------

* ``database``: A :ref:`mongoc_database_t`.
* ``write_concern``: A :ref:`mongoc_write_concern_t`.

