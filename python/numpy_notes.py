#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jun 20 15:57:06 2023

@author: vince
"""
import numpy as np
# Numpy Fundamentals

################### Array Creation #################################

#1. Conversion from other Python structures (i.e. lists and tuples)
a1D = np.array([1, 2, 3, 4])
a2D = np.array([[1, 2], [3, 4]])
a3D = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])
#2. Intrinsic NumPy array creation functions (e.g. arange, ones, zeros, etc.)
#1d array functions: np.arange and np.linspace
np.arange(10)
np.arange(2,10)
np.arange(2,10,2)

np.linspace(2,10,6)

#2d array functions: np.eye, np.diag and np.vander
#identity matrix
np.eye(3)
np.eye(3,5)
#diagnal matrix
np.diag(np.arange(1,4))
np.diag(np.eye(3))

#general ndarray  functions: np.ones, np.zeros and np.random
np.zeros([2,3])
np.zeros([2,3,3])

np.ones([2,3])
np.ones([2,3,3])

np.random.random([2,3])
np.random.random([2,3,3])

#index of ndarry
np.indices([2,3])

######################ndarray manipulation###################
#reshape
np.arange(12).reshape(3,4)
np.arange(12).reshape(3,4).T
np.ones([3,3]).ravel()

#stack
np.vstack([np.ones([2,3]), np.zeros([2,3])])
np.row_stack([np.ones([2,3]), np.zeros([2,3])])
np.concatenate([np.ones([2,3]), np.zeros([2,3])],axis=0)

np.hstack([np.ones([2,3]), np.zeros([2,3])])
np.column_stack([np.ones([2,3]), np.zeros([2,3])])
np.concatenate([np.ones([2,3]), np.zeros([2,3])],axis=1)

np.block([np.ones([2,3]), np.zeros([2,3])])
np.block([[np.ones([2,3])], [np.zeros([2,3])]])

#split

np.vsplit(np.arange(12).reshape(4,3),2)
np.hsplit(np.arange(12).reshape(3,4),2)

################### linear Algebra functions #################################

np.random.random([3,4])@np.random.random([4,3])
np.linalg.inv(np.arange(1,10).reshape([3,3]))
a=np.random.random([3,3])
np.linalg.inv(a)@a

np.linalg.det(np.arange(1,10).reshape([3,3]))
np.linalg.det(np.linalg.inv(a)@a)

np.linalg.norm(np.arange(1,10).reshape([3,3]))
np.linalg.matrix_rank(np.random.random([7,7]))

########## eigen value and eigen vectors
np.linalg.eigvals(np.random.random([3,3]))
np.linalg.eig(np.random.random([3,3]))

########## decomposition
np.linalg.qr(a)
np.linalg.svd(a)
np.linalg.cholesky(np.eye(3))







































































































