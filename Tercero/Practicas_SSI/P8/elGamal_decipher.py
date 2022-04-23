""""
 @file elGamal_decipher.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of elGamal algorithm
 @version 0.1
 @date 2022-04-23
  
 @copyright Copyright (c) 2022
"""

def ElGamal_decipher(p_value, x_value, y_a_value, c_value):
    K_value = (pow(int(y_a_value), int(x_value)) % int(p_value))
    K_inv_value = pow((int(K_value)), -1)
    print(K_inv_value)
