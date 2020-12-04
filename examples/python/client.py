import MemoryManager as MM
from MemoryManager import ExampleData
import ctypes
import numpy as np
import time

state = MM.EIGEN_STATE.get()
data = state['data']
print('------------EIGEN DATA------------')
print('Values: ', data[0], data[1], data[2])

# array_length = 2
state = MM.STRUCT_STATE.get()
print state['data']
stru = state['data'].ctypes.data_as(ctypes.POINTER(ExampleData)).contents
# buff = np.core.multiarray.int_asbuffer(ctypes.addressof(stru.vector), 8*array_length)
# vec = np.frombuffer(buff, float)
# buff = np.core.multiarray.int_asbuffer(ctypes.addressof(stru.ptr), 8*3)
# ptr = np.frombuffer(buff, float)
print('------------STRUCT DATA------------')
print('x_value : ', stru.x_value, 'y_value : ', stru.y_value, 'count : ', stru.count,)# "z value :", stru.z_value)
# print('vector: ', vec[0], vec[1])
# print('ptr: ', ptr[0], ptr[1])

data = {}
stru.x_value = 10.0
buff = np.core.multiarray.int_asbuffer(ctypes.addressof(stru), 8)
# MM.STRUCT_STATE.set(buff)

# TODO: Need to find a way to have dynamic arrays other than Eigen
array_length = 3
state = MM.DYNAMIC_STATE.get()
ptr = state['data'].ctypes.data_as(ctypes.POINTER(ctypes.c_double)).contents
print ptr
buff = np.core.multiarray.int_asbuffer(ctypes.addressof(ptr), 8*array_length)
data = np.frombuffer(buff, dtype="float64")
print('------------DYNAMIC DATA------------')
print('Values: ', data[0], data[1], data[2])

array_length = 3
state = MM.VECTOR_STATE.get()
ptr = state['data'].ctypes.data_as(ctypes.POINTER(ctypes.c_double)).contents
buff = np.core.multiarray.int_asbuffer(ctypes.addressof(ptr), 8*array_length)
data = np.frombuffer(buff, dtype="float64")
print('------------VECTOR DATA------------')
print('Values: ', data[0], data[1], data[2])

# state = MM.DYNAMIC_EIGEN_STATE.get()
# ptr = state['data'].ctypes.data_as(ctypes.POINTER(ctypes.c_double*3)).contents
# buff = np.core.multiarray.int_asbuffer(ctypes.addressof(ptr), 8*array_length)
# print('------------EIGEN DATA------------')
# print('Values: ', data[0], data[1], data[2])


# data = {}
# data['data'] = np.array([1.0, 20, 22.22])
# MM.VECTOR_STATE.set(data)