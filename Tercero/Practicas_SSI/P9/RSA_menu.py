""""
@file RSA_menu.py
@author Samuel Martín Morales (alu0101359526@ull.edu.es)
@brief Implementation of RSA algorithm
@version 0.1
@date 2022-05-01

@copyright Copyright (c) 2022
"""

import math
from RSA_prime_numbers import Prime_Number
from RSA_extended_Euclides import Extended_Euclides_Algorithm
from RSA_decimal_Text_convertor import Decimal_Text_Convertor
from RSA_fast_exponentiation import Fast_Exponentiation

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
        exit(1) # COMPROBE THIS POINT
        
    # Public information n = p*q  e = inverse d_value module  (n)
    e_value = Extended_Euclides_Algorithm(phi_value, d_value)
    if (e_value < 0):
        e_value = e_value + phi_value
    print()
    print(f'E value is {e_value}')
    n_value = (p_value * q_value)
    print()
    print(f'N value is {n_value}')
    
    # Calculates the text divition to cipher j-1 = whole part (logb n)
    j_1_value = math.log(n_value, 26)
    decimal_part = j_1_value % 1
    whole_part = j_1_value - decimal_part
    j_1_value = int(whole_part)
    print()
    print(f'Finally, the text divition is {j_1_value} characters')
    
    # Converts the text into decimal numbers
    divided_string = []
    auxiliary_string = ''
    i = 0
    counter = 0
    original_text = original_text.replace(" ", "") # To delete the blancks
    while(i != len(original_text)):
        if (counter < j_1_value):
            auxiliary_string = auxiliary_string + original_text[i]
            counter += 1
        else:
            counter = 0
            divided_string.append(auxiliary_string)
            auxiliary_string = ''
            auxiliary_string = auxiliary_string + original_text[i]
            counter += 1
        i += 1
    divided_string.append(auxiliary_string)
    print(divided_string)
    
    decimal_block_text = Decimal_Text_Convertor(divided_string, j_1_value)
    
    # Cipher the decimal numbers
    i = 0
    final_result = []
    while (i != len(decimal_block_text)):
        auxiliary_decimal = decimal_block_text[i]
        auxiliary_decimal = Fast_Exponentiation(auxiliary_decimal, e_value, n_value)
        final_result.append(auxiliary_decimal)
        auxiliary_decimal = 0
        i += 1
    print(final_result)
