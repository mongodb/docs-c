.. _mongoc_stream_buffered_new

mongoc_stream_buffered_new()
============================

Synopsis
--------

.. code-block:: c

  mongoc_stream_t *
  mongoc_stream_buffered_new (mongoc_stream_t *base_stream,
                          size_t buffer_size) BSON_GNUC_WARN_UNUSED_RESULT;

Parameters
----------

* ``base_stream``: A :ref:`mongoc_stream_t` to buffer.
* ``buffer_size``: A size_t containing the desired buffer size.

This function shall create a new :ref:`mongoc_stream_t` that buffers bytes to and from the underlying ``base_stream``.

``buffer_size`` will be used as the initial buffer size. It may grow past this size.

Returns
-------

A newly allocated :ref:`mongoc_stream_buffered_t` on success, otherwise ``NULL``. This should be freed with :ref:`mongoc_stream_destroy()` when no longer in use.

