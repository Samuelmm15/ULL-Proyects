""""
 @file elGamal_menu.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of elGamal algorithm
 @version 0.1
 @date 2022-04-23
  
 @copyright Copyright (c) 2022
"""

from elGamal_cipher import ElGamal_cipher
from elGamal_decipher import ElGamal_decipher
from elGamal_extended_Euclides import Extended_Euclides_Algorithm
from y_A_value import y_A_B_value

def Menu():
    print()
    print('<< BIENVENIDO A EL CIFRADO DE ELGAMAL >>')
    print()
    p_value = input('Introduzca el valor de p: ')
    a_value = input('Introduzca el valor de a: ')
    k_value = input('Introduzca el valor de k: ')
    x_value = input('Introduzca el valor de x: ')
    m_value = input('Introduzca el valor de m: ')
    
    print()
    print('Los valores inicialmente introducidos han sido: ')
    print(f'p= {p_value}, a= {a_value}, k= {k_value}, x= {x_value}, m= {m_value}')
    
    # Calculate the B User public value with x private value
    y_B_value = y_A_B_value(a_value, x_value, p_value)
    
    # Caluclate the common A key
    y_a_value = y_A_B_value(a_value, k_value, p_value)
    
    # This is the A user cipher text
    c_value = ElGamal_cipher(p_value, m_value, k_value ,y_B_value)
    M_value = ElGamal_decipher(p_value, x_value, y_a_value, c_value)
    
    # Calculate K_value to prints
    K_value = (pow(int(y_B_value), int(k_value)) % int(p_value)) # It is the same as the y_A K_value
    # Calculates the K_inv_Value to print the original value
    K_inv_Value = Extended_Euclides_Algorithm(int(p_value), int(K_value))
    # At the case of the inverse K value is negative
    if (K_inv_Value < 0):
        K_inv_Value = int(K_inv_Value) + int(p_value)
    
    print(f'yA= {y_a_value}, yB= {y_B_value}, K= {K_value}, K-1={K_inv_Value} ,C= {c_value}, M= {M_value}')
