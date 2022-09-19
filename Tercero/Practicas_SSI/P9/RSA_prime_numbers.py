""""
@file RSA_menu.py
@author Samuel Martín Morales (alu0101359526@ull.edu.es)
@brief Prime Numbers Comprobation
@version 0.1
@date 2022-05-01

@copyright Copyright (c) 2022
"""

from operator import truediv
import random
from RSA_fast_exponentiation import Fast_Exponentiation

def Prime_Number(p_value):
    # Comprobe if p_value is not divisible by (2,3,4,5,11)
    i = 0
    counter = 0
    finish_flag = False
    prime_flag = False
    result_flag = False
    if ((p_value == 2) | (p_value == 3) | (p_value == 5) | (p_value == 7) | (p_value == 11)):
        return True
    elif ((p_value % 2 != 0) & (p_value % 3 != 0) & (p_value % 5 != 0) & (p_value % 7 != 0) & (p_value % 11 != 0)):
        # print('Is not divisible')
        while finish_flag != True:
            a_random_value = random.randint(2, (p_value - 1))
            auxiliary_a = Fast_Exponentiation(a_random_value, ((p_value - 1) / 2), p_value)
            if (auxiliary_a == (1 % p_value)):
                counter += 1
            elif (auxiliary_a != (-1 % p_value)):
                # print('P value is compoud')
                finish_flag = True
            else:
                # print('P value is prime number')
                result_flag = True
                finish_flag = True
                prime_flag = True
            i += 1
    if (i == counter):
        print('P value is compoud')
    if (prime_flag == False):
        # print('P value is not a prime number')
        result_flag = False
    return result_flag