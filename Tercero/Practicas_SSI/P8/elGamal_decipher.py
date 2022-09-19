""""
 @file elGamal_decipher.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of elGamal algorithm
 @version 0.1
 @date 2022-04-23
  
 @copyright Copyright (c) 2022
"""

from elGamal_extended_Euclides import Extended_Euclides_Algorithm

def ElGamal_decipher(p_value, x_value, y_a_value, c_value):
    # Calculates the K_value
    K_value = (pow(int(y_a_value), int(x_value)) % int(p_value))
    
    # Euclides extended algorithm
    K_inv_Value = Extended_Euclides_Algorithm(int(p_value), int(K_value))
    
    # Decipher the message
    M_value = ((int(K_inv_Value) * int(c_value)) % int(p_value))
    
    return M_value
