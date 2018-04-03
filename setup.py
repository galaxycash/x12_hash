from distutils.core import setup, Extension

x12_hash_module = Extension('x12_hash',
                               sources = ['x12module.c',
                                          'x12.c',
										  'sha3/blake.c',
										  'sha3/bmw.c',
										  'sha3/groestl.c',
										  'sha3/jh.c',
										  'sha3/keccak.c',
										  'sha3/skein.c',
										  'sha3/cubehash.c',
										  'sha3/echo.c',
										  'sha3/luffa.c',
										  'sha3/simd.c',
                                          'sha3/hamsi.c',
                                          'sha3/hamsi_helper.c',
										  'sha3/shavite.c'],

                               include_dirs=['.', './sha3'])

setup (name = 'x12_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by x12',
       ext_modules = [x12_hash_module])
