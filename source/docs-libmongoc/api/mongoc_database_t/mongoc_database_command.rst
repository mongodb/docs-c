.. _mongoc_database_command

mongoc_database_command()
=========================

Synopsis
--------

.. code-block:: c

  mongoc_cursor_t *
  mongoc_database_command (mongoc_database_t *database,
                           mongoc_query_flags_t flags,
                           uint32_t skip,
                           uint32_t limit,
                           uint32_t batch_size,
                           const bson_t *command,
                           const bson_t *fields,
                           const mongoc_read_prefs_t *read_prefs)
     BSON_GNUC_WARN_UNUSED_RESULT;

This function is superseded by :ref:`mongoc_database_command_with_opts()`, :ref:`mongoc_database_read_command_with_opts()`, :ref:`mongoc_database_write_command_with_opts()`, and :ref:`mongoc_database_read_write_command_with_opts()`.

Description
-----------

This function creates a cursor which will execute the command when :ref:`mongoc_cursor_next` is called on it. The database's read preference, read concern, and write concern are not applied to the command, and :ref:`mongoc_cursor_next` will not check the server response for a write concern error or write concern timeout.

.. include:: includes/not-retryable-read.txt

Parameters
----------

* ``database``: A :ref:`mongoc_database_t`.
* ``flags``: A :ref:`mongoc_query_flags_t`.
* ``skip``: The number of documents to skip on the server.
* ``limit``: The maximum number of documents to return from the cursor.
* ``batch_size``: Attempt to batch results from the server in groups of ``batch_size`` documents.
* ``command``: A :ref:`bson_t` containing the command.
* ``fields``: An optional :ref:`bson_t` containing the fields to return. ``NULL`` for all fields.
* ``read_prefs``: An optional :ref:`mongoc_read_prefs_t`. Otherwise, the command uses mode ``MONGOC_READ_PRIMARY``.

Returns
-------

.. include:: includes/returns-cursor.txt

