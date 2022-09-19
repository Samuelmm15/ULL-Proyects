""""
@file RSA_menu.py
@author Samuel Martín Morales (alu0101359526@ull.edu.es)
@brief Fast exponentiation algorithm
@version 0.1
@date 2022-05-01

@copyright Copyright (c) 2022
"""

def Fast_Exponentiation(a_base, b_exponent, m_module):
    x_value = 1
    y_value = a_base % m_module
    while ((b_exponent > 0) & (y_value > 1)):
        if ((b_exponent % m_module) != 0):
            x_value = (x_value * y_value) % m_module
            b_exponent = b_exponent - 1
        else:
            y_value = (y_value * y_value) % m_module
            b_exponent = b_exponent / 2
    return x_value