.. _mongoc_client_encryption_datakey_opts_destroy

mongoc_client_encryption_datakey_opts_destroy()
===============================================

Synopsis
--------

.. code-block:: c

  void
  mongoc_client_encryption_datakey_opts_destroy (mongoc_client_encryption_datakey_opts_t *opts);

Frees resources of a :ref:`mongoc_client_encryption_datakey_opts_t` created with :ref:`mongoc_client_encryption_datakey_opts_new()`. Does nothing if ``NULL`` is passed.

Parameters
----------

* ``opts``: A :ref:`mongoc_client_encryption_datakey_opts_t`.