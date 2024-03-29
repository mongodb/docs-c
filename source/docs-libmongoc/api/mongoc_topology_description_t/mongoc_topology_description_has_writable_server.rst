.. _mongoc_topology_description_has_writable_server

mongoc_topology_description_has_writable_server()
=================================================

Synopsis
--------

.. code-block:: c

  bool
  mongoc_topology_description_has_writable_server (
     const mongoc_topology_description_t *td);

Determines if the topology has a writable server available, such as a primary,
mongos, or standalone. This function uses the driver's current knowledge of the
state of the MongoDB server or servers it is connected to; it does no I/O and it
does not block.


Parameters
----------

* ``td``: A :ref:`mongoc_topology_description_t`.

Returns
-------

True if there is a known writable server.

.. seealso::

  | :ref:`Introduction to Application Performance Monitoring <mongoc_application_performance_monitoring>`

