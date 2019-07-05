# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: manifest.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='manifest.proto',
  package='tetrad',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x0emanifest.proto\x12\x06tetrad\"\xe6\x01\n\x08Manifest\x12\x15\n\rversion_major\x18\x01 \x01(\x05\x12\x15\n\rversion_minor\x18\x02 \x01(\x05\x12.\n\x07headers\x18\x03 \x03(\x0b\x32\x1d.tetrad.Manifest.HeadersEntry\x1a/\n\nHeaderInfo\x12\r\n\x05mtime\x18\x01 \x01(\x01\x12\x12\n\ncomponents\x18\x02 \x03(\t\x1aK\n\x0cHeadersEntry\x12\x0b\n\x03key\x18\x01 \x01(\t\x12*\n\x05value\x18\x02 \x01(\x0b\x32\x1b.tetrad.Manifest.HeaderInfo:\x02\x38\x01\x62\x06proto3')
)




_MANIFEST_HEADERINFO = _descriptor.Descriptor(
  name='HeaderInfo',
  full_name='tetrad.Manifest.HeaderInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='mtime', full_name='tetrad.Manifest.HeaderInfo.mtime', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='components', full_name='tetrad.Manifest.HeaderInfo.components', index=1,
      number=2, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=133,
  serialized_end=180,
)

_MANIFEST_HEADERSENTRY = _descriptor.Descriptor(
  name='HeadersEntry',
  full_name='tetrad.Manifest.HeadersEntry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='key', full_name='tetrad.Manifest.HeadersEntry.key', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='value', full_name='tetrad.Manifest.HeadersEntry.value', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=_b('8\001'),
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=182,
  serialized_end=257,
)

_MANIFEST = _descriptor.Descriptor(
  name='Manifest',
  full_name='tetrad.Manifest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='version_major', full_name='tetrad.Manifest.version_major', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='version_minor', full_name='tetrad.Manifest.version_minor', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='headers', full_name='tetrad.Manifest.headers', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[_MANIFEST_HEADERINFO, _MANIFEST_HEADERSENTRY, ],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=27,
  serialized_end=257,
)

_MANIFEST_HEADERINFO.containing_type = _MANIFEST
_MANIFEST_HEADERSENTRY.fields_by_name['value'].message_type = _MANIFEST_HEADERINFO
_MANIFEST_HEADERSENTRY.containing_type = _MANIFEST
_MANIFEST.fields_by_name['headers'].message_type = _MANIFEST_HEADERSENTRY
DESCRIPTOR.message_types_by_name['Manifest'] = _MANIFEST
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Manifest = _reflection.GeneratedProtocolMessageType('Manifest', (_message.Message,), dict(

  HeaderInfo = _reflection.GeneratedProtocolMessageType('HeaderInfo', (_message.Message,), dict(
    DESCRIPTOR = _MANIFEST_HEADERINFO,
    __module__ = 'manifest_pb2'
    # @@protoc_insertion_point(class_scope:tetrad.Manifest.HeaderInfo)
    ))
  ,

  HeadersEntry = _reflection.GeneratedProtocolMessageType('HeadersEntry', (_message.Message,), dict(
    DESCRIPTOR = _MANIFEST_HEADERSENTRY,
    __module__ = 'manifest_pb2'
    # @@protoc_insertion_point(class_scope:tetrad.Manifest.HeadersEntry)
    ))
  ,
  DESCRIPTOR = _MANIFEST,
  __module__ = 'manifest_pb2'
  # @@protoc_insertion_point(class_scope:tetrad.Manifest)
  ))
_sym_db.RegisterMessage(Manifest)
_sym_db.RegisterMessage(Manifest.HeaderInfo)
_sym_db.RegisterMessage(Manifest.HeadersEntry)


_MANIFEST_HEADERSENTRY._options = None
# @@protoc_insertion_point(module_scope)