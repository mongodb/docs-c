.. _mongoc_transaction_opt_t

mongoc_transaction_opt_t
========================

.. code-block:: c

  #include <mongoc/mongoc.h>

  typedef struct _mongoc_transaction_opt_t mongoc_transaction_opt_t;

Synopsis
--------

Options for starting a multi-document transaction.

When a session is first created with :ref:`mongoc_client_start_session`, it inherits from the client the read concern, write concern, and read preference with which to start transactions. Each of these fields can be overridden independently. Create a :ref:`mongoc_transaction_opt_t` with :ref:`mongoc_transaction_opts_new`, and pass a non-NULL option to any of the :ref:`mongoc_transaction_opt_t` setter functions:

* :ref:`mongoc_transaction_opts_set_read_concern`
* :ref:`mongoc_transaction_opts_set_write_concern`
* :ref:`mongoc_transaction_opts_set_read_prefs`

Pass the resulting transaction options to :ref:`mongoc_client_session_start_transaction`. Each field set in the transaction options overrides the inherited client configuration.

Example
-------

.. literalinclude:: ../examples/example-transaction.c
   :language: c
   :caption: example-transaction.c

Functions
---------

.. toctree::
  :titlesonly:
  :maxdepth: 1

  /mongoc_transaction_opt_t/mongoc_transaction_opts_new
  /mongoc_transaction_opt_t/mongoc_transaction_opts_get_read_concern
  /mongoc_transaction_opt_t/mongoc_transaction_opts_set_read_concern
  /mongoc_transaction_opt_t/mongoc_transaction_opts_get_write_concern
  /mongoc_transaction_opt_t/mongoc_transaction_opts_set_write_concern
  /mongoc_transaction_opt_t/mongoc_transaction_opts_get_read_prefs
  /mongoc_transaction_opt_t/mongoc_transaction_opts_set_read_prefs
  /mongoc_transaction_opt_t/mongoc_transaction_opts_get_max_commit_time_ms
  /mongoc_transaction_opt_t/mongoc_transaction_opts_set_max_commit_time_ms
  /mongoc_transaction_opt_t/mongoc_transaction_opts_clone
  /mongoc_transaction_opt_t/mongoc_transaction_opts_destroy
