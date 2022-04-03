""""
 @file aes_Rijndael_algorithm_MixColumn.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

# Multiply all the column to a standar matrix

def MixColumn(cipher_text_block):
    mixColumn_matrix = [['2','3','1','1'],     
                        ['1','2','3','1'],
                        ['1','1','2','3'],
                        ['3','1','1','2']]
    
    first_column = []
    first_column_result = []
    second_column = []
    second_column_result = []
    thirth_column = []
    thirth_column = []
    fourth_column = []
    fourth_column = []
    
    # Obtain the first column
    i = 0
    j = 0
    while i < len(cipher_text_block):
        first_column.append(cipher_text_block[i][j])
        i += 1

    first_column_result[0] = hex(int(hex(hex((int(mixColumn_matrix[0][0],16) * int(first_column[0],16))) ^ hex((int(mixColumn_matrix[0][1],16) * int(first_column[1],16))) ^ int(first_column[2],16) ^ int(first_column[3],16)),16) & 0xFF)[2:].zfill(2)
    first_column_result[1] = hex(int(hex(int(first_column[0],16) ^ hex((int(mixColumn_matrix[1][1],16) * int(first_column[1],16))) ^ hex((int(mixColumn_matrix[1][2],16) * int(first_column[2],16))) ^ int(first_column[3],16)),16) & 0xFF)[2:].zfill(2)
    first_column_result[2] = hex(int(hex(int(first_column[0],16) ^ int(first_column[1],16) ^ hex((int(mixColumn_matrix[2][2],16) * int(first_column[2],16))) ^ hex((int(mixColumn_matrix[2][3],16) * int(first_column[3],16)))),16) & 0xFF)[2:].zfill(2)
    first_column_result[3] = hex(int(hex((int(mixColumn_matrix[3][0],16) * int(first_column[0],16))) ^ int(first_column[1],16) ^ int(first_column[2],16) ^ hex(int(mixColumn_matrix[3][3],16) * int(first_column[3],16)),16) & 0xFF)[2:].zfill(2)
    
    print(first_column_result)
    # i = 0
    # j = 0
    # counter = 0
    # first_operator = 0
    # second_operator = 0
    # result = 0
    # while counter < 4:
    #     while i < len(cipher_text_block):
    #         first_operator = cipher_text_block[i][j]
    #         second_operator = hex(int(mixColumn_matrix[i][j]))[2:]
    #         result = hex((int(first_operator, 16) * int(second_operator, 16)) & 0xFF)[2:].zfill(2)
    #         cipher_text_block[i][j] = result
    #         i += 1
    #     j += 1
    #     i = 0
    #     counter += 1
    
    # print()
    # print('Resultado tras el producto de columnas: ')
    
    # i = 0
    # j = 0
    # while i < len(cipher_text_block):
    #     while j < len(cipher_text_block[i]):
    #         print(cipher_text_block[i][j], end=' ')
    #         j += 1
    #     print()
    #     j = 0
    #     i += 1
    
    # return cipher_text_block