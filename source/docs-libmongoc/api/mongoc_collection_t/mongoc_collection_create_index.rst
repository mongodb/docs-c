.. _mongoc_collection_create_index

mongoc_collection_create_index()
================================

.. warning::
   .. deprecated:: 1.8.0

      This function is deprecated and should not be used in new code. See :doc:`manage-collection-indexes`.

Synopsis
--------

.. code-block:: c

  bool
  mongoc_collection_create_index (mongoc_collection_t *collection,
                                  const bson_t *keys,
                                  const mongoc_index_opt_t *opt,
                                  bson_error_t *error) BSON_GNUC_DEPRECATED;

Parameters
----------

* ``collection``: A :ref:`mongoc_collection_t`.
* ``keys``: A :ref:`bson_t`.
* ``opt``: A mongoc_index_opt_t.
* ``error``: An optional location for a :symbol:`bson_error_t <errors>` or ``NULL``.
