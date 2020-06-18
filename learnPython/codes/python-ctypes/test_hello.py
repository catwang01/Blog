import ctypes

lib = ctypes.cdll.LoadLibrary('hello.so')
lib.printHello()
