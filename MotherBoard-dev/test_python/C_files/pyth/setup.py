from distutils.core import setup, Extension

extension_mod = Extension("MotherBoard", ["_swigdemo_module.cc", "hello.c"])

setup(name = "MotherBoard", ext_modules=[extension_mod])
