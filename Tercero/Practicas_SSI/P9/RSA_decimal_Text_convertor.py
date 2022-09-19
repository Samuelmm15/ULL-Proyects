""""
@file RSA_decimal_Text_convertor.py
@author Samuel Martín Morales (alu0101359526@ull.edu.es)
@brief Converts a text character into decimal number
@version 0.1
@date 2022-05-01

@copyright Copyright (c) 2022
"""

from RSA_Alphabet_DataBase import Alphabet_DataBase

def Decimal_Text_Convertor(introduced_text, j_1_value):
    i = 0
    j = j_1_value - 1
    k = 0
    decimal_number_result = []
    auxiliary_result = 0
    while (i != len(introduced_text)):
        auxiliary_string = introduced_text[i]
        while (j >= 0):
            if (j != 0):
                auxiliary_result = auxiliary_result + (Alphabet_DataBase(auxiliary_string[k]) * pow(26, j))
            else:
                auxiliary_result = auxiliary_result + Alphabet_DataBase(auxiliary_string[k])
            k += 1
            j -= 1
        decimal_number_result.append(auxiliary_result)
        auxiliary_result = 0
        k = 0
        j = j_1_value - 1
        i += 1
    
    print('Decimal block are: ')
    print(decimal_number_result)
    return decimal_number_result