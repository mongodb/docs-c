.. _mongoc_client_pool_set_apm_callbacks

mongoc_client_pool_set_apm_callbacks()
======================================

Synopsis
--------

.. code-block:: c

  bool
  mongoc_client_pool_set_apm_callbacks (mongoc_client_pool_t *pool,
                                        mongoc_apm_callbacks_t *callbacks,
                                        void *context);

Register a set of callbacks to receive Application Performance Monitoring events.

The ``callbacks`` are copied by the pool and may be destroyed at any time after.  If a ``context`` is passed, it is the application's responsibility to ensure ``context`` remains valid for the lifetime of the pool.

Parameters
----------

* ``pool``: A :ref:`mongoc_client_pool_t`.
* ``callbacks``: A :ref:`mongoc_apm_callbacks_t`.
* ``context``: Optional pointer to include with each event notification.

Returns
-------

Returns true on success. If any arguments are invalid, returns false and logs an error.

.. include:: includes/mongoc_client_pool_call_once.txt

.. seealso::

  | :ref:`Introduction to Application Performance Monitoring <mongoc_application_performance_monitoring>`

