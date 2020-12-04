import ctypes
import posix_ipc
import mmap
import numpy as np

mem = posix_ipc.SharedMemory("TEST_DYNAMIC_DATA_mem")
mem_addr = mmap.mmap(mem.fd, mem.size)
d_type = ctypes.POINTER(ctypes.c_double*3)
d = d_type.from_buffer(mem_addr)
buff = np.core.multiarray.int_asbuffer(ctypes.addressof(d.contents), 8*3)
data = np.frombuffer(buff, dtype="float64")
print data