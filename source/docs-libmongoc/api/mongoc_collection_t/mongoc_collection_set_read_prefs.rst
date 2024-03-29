.. _mongoc_collection_set_read_prefs

mongoc_collection_set_read_prefs()
==================================

Synopsis
--------

.. code-block:: c

  void
  mongoc_collection_set_read_prefs (mongoc_collection_t *collection,
                                    const mongoc_read_prefs_t *read_prefs);

Parameters
----------

* ``collection``: A :ref:`mongoc_collection_t`.
* ``read_prefs``: A :ref:`mongoc_read_prefs_t`.

Description
-----------

Sets the default read preferences to use for operations on ``collection`` not specifying a read preference.

The global default is MONGOC_READ_PRIMARY: if the client is connected to a replica set it reads from the primary, otherwise it reads from the current MongoDB server.

Please see the MongoDB website for a description of `Read Preferences <https://www.mongodb.com/docs/manual/core/read-preference/>`_.

