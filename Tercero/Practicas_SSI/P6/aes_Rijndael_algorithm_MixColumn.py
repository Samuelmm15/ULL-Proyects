""""
 @file aes_Rijndael_algorithm_MixColumn.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

from aes_Rijndael_algorithm_multiplication import AES_multplication

# Multiply all the column to a standar matrix

def MixColumn(cipher_text_block):
    mixColumn_matrix = [['02','03','01','01'],     
                        ['01','02','03','01'],
                        ['01','01','02','03'],
                        ['03','01','01','02']]
    
    # This is for mixcolumn matrix
    first_row = []
    i = 0
    j = 0
    while j < len(mixColumn_matrix[i]):
        first_row.append(mixColumn_matrix[i][j])
        j += 1
    
    
    second_row = []
    i = 1
    j = 0
    while j < len(mixColumn_matrix[i]):
        second_row.append(mixColumn_matrix[i][j])
        j += 1
    
    thirth_row = []
    i = 2
    j = 0
    while j < len(mixColumn_matrix[i]):
        thirth_row.append(mixColumn_matrix[i][j])
        j += 1
   
    fourth_row = []
    i = 3
    j = 0
    while j < len(mixColumn_matrix[i]):
        fourth_row.append(mixColumn_matrix[i][j])
        j += 1
    
    # This is for cipher text block matrix
    first_column = []
    first_column_result = []
    
    # Obtain the first column
    i = 0
    j = 0
    while i < len(cipher_text_block):
        first_column.append(cipher_text_block[i][j])
        i += 1
   
    first_operation = AES_multplication(first_row[0], first_column[0])
    first_operation = hex(int(first_operation,2) & 0xFF)[2:].zfill(2)
    second_operation = AES_multplication(first_row[1], first_column[1])
    second_operation = hex(int(second_operation,2) & 0xFF)[2:].zfill(2)
    first_column_result.append(hex(int(first_operation,16) ^ int(second_operation,16) ^ int(first_column[2],16) ^ int(first_column[3],16) & 0xFF)[2:].zfill(2))
    first_operation = AES_multplication(second_row[1], first_column[1])
    first_operation = hex(int(first_operation,2) & 0xFF)[2:].zfill(2)
    print(first_operation)
    second_operation = AES_multplication(second_row[2], first_column[2])
    second_operation = hex(int(second_operation,2) & 0xFF)[2:].zfill(2)
    print(second_operation)
    first_column_result.append(hex(int(first_column[0],16) ^ int(first_operation,16) ^ int(second_operation,16) ^ int(first_column[3],16) & 0xFF)[2:].zfill(2))
    first_operation = AES_multplication(thirth_row[2], first_column[2])
    first_operation = hex(int(first_operation,2) & 0xFF)[2:].zfill(2)
    second_operation = AES_multplication(thirth_row[3], first_column[3])
    second_operation = hex(int(second_operation,2) & 0xFF)[2:].zfill(2)
    first_column_result.append(hex(int(first_column[0],16) ^ int(first_column[1],16) ^ int(first_operation,16) ^ int(second_operation,16) & 0xFF)[2:].zfill(2))
    first_operation = AES_multplication(fourth_row[0], first_column[0])
    first_operation = hex(int(first_operation,2) & 0xFF)[2:].zfill(2)
    second_operation = AES_multplication(fourth_row[3], first_column[3])
    second_operation = hex(int(second_operation,2) & 0xFF)[2:].zfill(2)
    first_column_result.append(hex(int(first_operation,16) ^ int(first_column[1],16) ^ int(first_column[2],16) ^ int(second_operation,16) & 0xFF)[2:].zfill(2))
    
    print(first_column_result)
    
    second_column = []
    second_column_result = []
    # Obtain the second column
    i = 0
    j = 1
    while i < len(cipher_text_block):
        second_column.append(cipher_text_block[i][j])
        i += 1
    
    thirth_column = []
    thirth_column_result = [] 
    # Obtain the thirth column
    i = 0
    j = 2
    while i < len(cipher_text_block):
        thirth_column.append(cipher_text_block[i][j])
        i += 1
    
    fourth_column = []
    fourth_column_result = []
    # Obtain the fourth column
    i = 0
    j = 3
    while i < len(cipher_text_block):
        fourth_column.append(cipher_text_block[i][j])
        i += 1
    