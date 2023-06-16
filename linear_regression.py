#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jun 16 14:24:19 2023

@author: vince
"""

import numpy as np

def linear_regression_coef(x,y,intercept=True):
    if intercept:
        x_np = np.column_stack((np.ones((x.shape[0])), x))
    else:
        x_np = x
    xTx = x_np.T @ x_np
    try:
        xTx_inv = np.linalg.inv(xTx)
    except np.linalg.LinAlgError:
        return [np.nan for _ in range(x_np.shape[1])]

    coef = xTx_inv @ x_np.T @ y
    return coef

def linear_regression_predict(x,y,intercept=True):
    if intercept:
        x_np = np.column_stack((np.ones((x.shape[0])), x))
    else:
        x_np = x
    coef=linear_regression_coef(x,y,intercept)
    return np.dot(x_np, coef)

def linear_regression_residual(x,y,intercept=True):
    return y-linear_regression_predict(x,y,intercept)