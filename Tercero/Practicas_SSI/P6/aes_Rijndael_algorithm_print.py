""""
 @file aes_Rijndael_algorithm_print.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

def Result_Print(iteration, cipher_text_block, key):
    auxiliary_key = ''
    i = 0
    j = 0
    while i < len(key):
        while j < len(key[i]):
            auxiliary_key = auxiliary_key + key[i][j]
            j += 1
        j = 0
        i += 1
        
    auxiliary_cipher_text_block = ''
    i = 0
    j = 0
    while i < len(cipher_text_block):
        while j < len(cipher_text_block[i]):
            auxiliary_cipher_text_block = auxiliary_cipher_text_block + cipher_text_block[i][j]
            j += 1
        j = 0
        i += 1
    
    print(f'R{iteration} (Subclave = {auxiliary_key}) = {auxiliary_cipher_text_block}')    
    
    
# print()
#     print('Resultado final de addRoundKey: ')
    
#     print()
#     i = 0
#     j = 0
#     while i < len(result_matrix):
#         while j < len(result_matrix[i]):
#             print(result_matrix[i][j], end=' ')
#             j += 1
#         print()
#         j = 0
#         i += 1

# print()
#     print('Finalmente, la subclave generada es: ')
    
#     print()
#     i = 0
#     j = 0
#     while i < len(auxiliary_key):
#         while j < len(auxiliary_key[i]):
#             print(auxiliary_key[i][j], end=' ')
#             j += 1
#         print()
#         j = 0
#         i += 1