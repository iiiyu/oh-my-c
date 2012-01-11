from ctypes import *
import os
libtest = cdll.LoadLibrary(os.getcwd() + '/libtest.so')
print libtest.multiply(2,2)
