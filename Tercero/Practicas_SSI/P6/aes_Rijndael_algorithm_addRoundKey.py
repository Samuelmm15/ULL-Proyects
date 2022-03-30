""""
 @file aes_Rijndael_algorithm_addRoundKey.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

# Se tiene que hacer la matriz de arriba a abajo y de izquierda a derecha

def addRoundKey(key_matrix, text_block_matrix):
    # AddRoundKey Operation
    i = 0
    result_auxiliary = 0
    result_matrix = []
    while i < len(key_matrix):
        result_auxiliary = hex(int(key_matrix[i], 16) ^ int(text_block_matrix[i], 16) & 0xFF)[2:].zfill(2)
        result_matrix.append(result_auxiliary)
        i += 1
        
    print()
    print('Resultado tras la primera iteracción: ')
    
    i = 0
    j = 0
    counter = 0
    while i < len(result_matrix):
        j = i
        if counter < 4:
            while j < len(result_matrix):
                print(result_matrix[j], end=' ')
                j += 4
            print()
        counter += 1
        i += 1
    
    return result_matrix