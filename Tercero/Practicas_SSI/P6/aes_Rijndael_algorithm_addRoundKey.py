""""
 @file aes_Rijndael_algorithm_addRoundKey.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

def addRoundKey(key, text_block):
    # Separation of the hexadecimal string into matrix
    key_matrix = []
    text_block_matrix = []
    
    i = 0
    j = 0
    counter = 0
    auxiliary_string_key = ''
    auxiliary_string_matrix = ''
    while i < 32: # This is the divition
        j = i
        while counter < 2:
            auxiliary_string_key = auxiliary_string_key + key[j]
            auxiliary_string_matrix = auxiliary_string_matrix + text_block[j]
            counter += 1
            j += 1
        key_matrix.append(auxiliary_string_key)
        text_block_matrix.append(auxiliary_string_matrix)
        auxiliary_string_matrix = ''
        auxiliary_string_key = ''
        counter = 0
        i += 2
    
    print()
    print('Los valores separados por pares son: ')
    print(key_matrix)
    print(text_block_matrix)