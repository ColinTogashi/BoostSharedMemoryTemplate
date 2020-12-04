#!usr/bin/env python
__author__ = "Colin Togashi"
__email__ = "colin.togashi@gmail.com"
__copyright__ = "Copyright 2019 RoMeLa"
__date__ = "May 15, 2019"

__version__ = "0.0.1"
__status__ = "Prototype"

'''
MemoryManager is a macro file to your favorite memory segments.

Pre-generate your shared memory segments before proceeding with using them in the rest of your scripts. 
'''

import numpy as np
import time

import pyshmxtreme.SHMSegment as shmx
import pdb
import ctypes


class ExampleData(ctypes.Structure):
    _fields_ = [
        ('x_value',  ctypes.c_double), 
        ('y_value',  ctypes.c_double), 
        ('count',    ctypes.c_int)]
        # ('vector',   ctypes.c_double*2),
        # ('ptr',      ctypes.POINTER(ctypes.c_double)),
        # ('z_value',  ctypes.c_double)]

class ExampleVector(ctypes.Structure):
    _fields_ = [
        ('ptr', ctypes.POINTER(ctypes.c_double*3))]

# ===== Create shared memory segments
EIGEN_STATE = shmx.SHMSegment(robot_name='TEST', seg_name='EIGEN_DATA', init=False)
EIGEN_STATE.add_blocks(name='data', data=np.zeros((3,1)))

STRUCT_STATE = shmx.SHMSegment(robot_name='TEST', seg_name='STRUCT_DATA', init=False)
STRUCT_STATE.add_blocks(name='data', data=np.array(ExampleData))

DYNAMIC_STATE = shmx.SHMSegment(robot_name='TEST', seg_name='DYNAMIC_DATA', init=False)
DYNAMIC_STATE.add_blocks(name='data', data=np.array(ctypes.POINTER(ctypes.c_double)))

VECTOR_STATE = shmx.SHMSegment(robot_name='TEST', seg_name='VECTOR_DATA', init=False)
VECTOR_STATE.add_blocks(name='data', data=np.array(ctypes.c_double*3))

# DYNAMIC_EIGEN_STATE = shmx.SHMSegment(robot_name='TEST', seg_name='DYNAMIC_EIGEN_DATA', init=False)
# DYNAMIC_EIGEN_STATE.add_blocks(name='data', data=np.array(ctypes.c_double*3))



def init():
    '''Init if main'''
    EIGEN_STATE.initialize = True
    STRUCT_STATE.initialize = True
    DYNAMIC_STATE.initialize = True
    VECTOR_STATE.initialize = True
    # DYNAMIC_EIGEN_STATE.initialize = True
    

def connect():
    '''Connect and create segment'''
    EIGEN_STATE.connect_segment()
    STRUCT_STATE.connect_segment()
    DYNAMIC_STATE.connect_segment()
    VECTOR_STATE.connect_segment()
    # DYNAMIC_EIGEN_STATE.connect_segment()

if __name__ == '__main__':
    init()
    connect()
else:
    connect()
