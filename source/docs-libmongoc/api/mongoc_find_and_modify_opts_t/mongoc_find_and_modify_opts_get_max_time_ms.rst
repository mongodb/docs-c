.. _mongoc_find_and_modify_opts_get_max_time_ms

mongoc_find_and_modify_opts_get_max_time_ms()
=============================================

Synopsis
--------

.. code-block:: c

  uint32_t
  mongoc_find_and_modify_opts_get_max_time_ms (
     const mongoc_find_and_modify_opts_t *opts);

Parameters
----------

* ``opts``: A :ref:`mongoc_find_and_modify_opts_t`.

Returns
-------

Returns the "maxTimeMS" value set with :ref:`mongoc_find_and_modify_opts_set_max_time_ms`.

