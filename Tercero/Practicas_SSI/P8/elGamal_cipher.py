""""
 @file elGamal_cipher.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of elGamal algorithm
 @version 0.1
 @date 2022-04-23
  
 @copyright Copyright (c) 2022
"""

def ElGamal_cipher(p_value, m_value, k_value, y_B_value):
    K_value = (pow(int(y_B_value), int(k_value)) % int(p_value))
    result = ((int(K_value) * int(m_value)) % int(p_value));
    return result;
    