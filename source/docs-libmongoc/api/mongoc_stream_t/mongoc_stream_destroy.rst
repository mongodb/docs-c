.. _mongoc_stream_destroy

mongoc_stream_destroy()
=======================

Synopsis
--------

.. code-block:: c

  void
  mongoc_stream_destroy (mongoc_stream_t *stream);

Parameters
----------

* ``stream``: A :ref:`mongoc_stream_t`.

This function shall release all resources associated with a :ref:`mongoc_stream_t`, including freeing the structure. It is invalid to use ``stream`` after calling this function. Does nothing if ``stream`` is NULL.
