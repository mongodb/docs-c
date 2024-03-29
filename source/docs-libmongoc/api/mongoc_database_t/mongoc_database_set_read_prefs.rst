.. _mongoc_database_set_read_prefs

mongoc_database_set_read_prefs()
================================

Synopsis
--------

.. code-block:: c

  void
  mongoc_database_set_read_prefs (mongoc_database_t *database,
                                  const mongoc_read_prefs_t *read_prefs);

This function sets the default read preferences to use on operations performed with ``database``. Collections created with :ref:`mongoc_database_get_collection()` after this call will inherit these read preferences.

The global default is MONGOC_READ_PRIMARY: if the client is connected to a replica set it reads from the primary, otherwise it reads from the current MongoDB server.

Please see the MongoDB website for a description of `Read Preferences <https://www.mongodb.com/docs/manual/core/read-preference/>`_.

Parameters
----------

* ``database``: A :ref:`mongoc_database_t`.
* ``read_prefs``: A :ref:`mongoc_read_prefs_t`.

