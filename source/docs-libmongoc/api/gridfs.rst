======
GridFS
======

The C driver includes two APIs for GridFS.

The older API consists of :ref:`mongoc_gridfs_t` and its derivatives. It contains deprecated API, does not support read preferences, and is not recommended in new applications. It does not conform to the `MongoDB GridFS specification <https://github.com/mongodb/specifications/blob/master/source/gridfs/gridfs-spec.rst>`_.

The newer API consists of :ref:`mongoc_gridfs_bucket_t` and allows uploading/downloading through derived :ref:`mongoc_stream_t` objects. It conforms to the `MongoDB GridFS specification <https://github.com/mongodb/specifications/blob/master/source/gridfs/gridfs-spec.rst>`_.

There is not always a straightforward upgrade path from an application built with :ref:`mongoc_gridfs_t` to :ref:`mongoc_gridfs_bucket_t` (e.g. a :ref:`mongoc_gridfs_file_t` provides functions to seek but :ref:`mongoc_stream_t` does not). But users are encouraged to upgrade when possible.