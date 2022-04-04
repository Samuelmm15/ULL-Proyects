""""
 @file aes_Rijndael_algorithm_addRoundKey.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

def addRoundKey(key_matrix, text_block_matrix):
    # AddRoundKey Operation
    i = 0
    j = 0
    auxiliary_row = []
    result_auxiliary = 0
    result_matrix = []
    while i < len(key_matrix):
        while j < len(key_matrix[i]):
            result_auxiliary = hex(int(key_matrix[i][j], 16) ^ int(text_block_matrix[i][j], 16) & 0xFF)[2:].zfill(2)
            auxiliary_row.append(result_auxiliary)
            j += 1
        result_matrix.append(auxiliary_row)
        auxiliary_row = []
        j = 0
        i += 1

    print(result_matrix)
        
    return result_matrix

# ESTO ESTÁ CORRECTO
