""""
@file RSA_menu.py
@author Samuel Martín Morales (alu0101359526@ull.edu.es)
@brief Implementation of RSA algorithm
@version 0.1
@date 2022-05-01

@copyright Copyright (c) 2022
"""

from RSA_prime_numbers import Prime_Number
from RSA_extended_Euclides import Extended_Euclides_Algorithm

def Menu():
    print('<< WELCOME TO RSA PUBLIC CIPHER>>')
    original_text = input('Enter the original text: ')
    p_value = int(input('Enter the p paramether value: '))
    q_value = int(input('Enter the q paramether value: '))
    d_value = int(input('Enter the d paramether value: '))
    
    print()
    print('The entered values are: ')
    print(f'Original text: {original_text}')
    print(f'p paramether: {p_value}')
    print(f'q paramether: {q_value}')
    print(f'd paramether: {d_value}')
    
    # Prime numbers comprobation
    counter_flag = 0
    print('<< Comprobe if p and q values are prime numbers >>')
    result = Prime_Number(p_value)
    if (result == True):
        print()
        print('P value is a prime number')
        counter_flag += 1
    else:
        print()
        print('P value is not prime number')
    
    result = Prime_Number(q_value)
    if (result == True):
        print()
        print('Q value is a prime number')
        counter_flag += 1
    else:
        print()
        print('Q value is not prime number')
        
    if (counter_flag == 2):
        print()
        print('p and q values are prime numbers')
    else:
        print()
        print('One of the p or q values is not a prime number')
        print('Enter other values')
        exit(1)
        
    # D value prime number comprobation  (n)=(p-1)(q-1)
    phi_value = (p_value - 1) * (q_value - 1)
    print()
    print(f'The phi value is {phi_value}')
    result = Prime_Number(d_value)
    if (result == True):
        print('D value is a prime number')
    else:
        print('D value is not prime number')
        
    # Public information n = p*q  e = inverse d_value module  (n)
    e_value = Extended_Euclides_Algorithm(phi_value, d_value)
    if (e_value < 0):
        e_value = e_value + d_value
    print()
    print(f'E value is {e_value}')
    n_value = (p_value * q_value)
    print()
    print(f'N value is {n_value}')
    
    # Calculates the text divition to cipher
    k_value = ((e_value * d_value) - 1) / phi_value
    print(k_value)
