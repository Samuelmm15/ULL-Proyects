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
    y_B_value = (pow(int(a_value), int(x_value)) % int(p_value))
    
    # Caluclate the common key
    y_a_value = (pow(int(a_value), int(k_value)) % int(p_value))
    
    # Calculate K_value
    K_value = (pow(int(y_B_value), int(k_value)) % int(p_value))
    
    # This is the A user cipher text
    c_value = ElGamal_cipher(p_value, m_value, k_value ,y_B_value)
    M_value = ElGamal_decipher(p_value, x_value, y_a_value, c_value)
    
    print(f'yA= {y_a_value}, yB= {y_B_value}, K= {K_value}, C= {c_value}, M= {M_value}')
