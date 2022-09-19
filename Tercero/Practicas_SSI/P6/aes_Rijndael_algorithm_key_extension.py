""""
 @file aes_Rijndael_algorithm_key_extension.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

from aes_Rijndael_algorithm_ByteSub import ByteSub

def Key_extension(key, interation):
    rcon_matrix = [['1','2','4','8','10','20','40','80','1b','36'],
                   ['0','0','0','0','0','0','0','0','0','0'],
                   ['0','0','0','0','0','0','0','0','0','0'],
                   ['0','0','0','0','0','0','0','0','0','0']]
    
    
    
    first_column = []
    second_column = []
    thirth_column = []
    fourth_column = []
    last_column = []
        
    # Obtain the last column
    i = 0
    j = 3
    while i < len(key):
        last_column.append(key[i][j])
        i += 1
    
    # RotWord
    auxiliary_column = []
    i = 0
    j = 3 # len(key) - 1
    while i < len(key):
        if (i == 0) and (j == (len(key) - 1)):
            auxiliary_value = key[i][j] # This is the last word
            last_column.remove(auxiliary_value)
            i += 1
            while i < len(key):
                previous_value = key[i][j]
                auxiliary_column.append(previous_value)
                last_column.remove(previous_value)
                i += 1
            i = 0
        if (i == (len(key) - 1)) and (j == (len(key) - 1)):
            auxiliary_column.append(auxiliary_value)
        i += 1
          
    last_column = auxiliary_column
        
    last_column = ByteSub(last_column, 1)
    
    # The xor operation at all the columns
    i = 0
    j = 0
    while i < len(key): #To obtain the first column
        first_column.append(key[i][j])
        i += 1
    
    # The iteration column of RCON
    i = 0
    j = interation - 1
    n_column_rcon = []
    while i < len(rcon_matrix):
        n_column_rcon.append(rcon_matrix[i][j])
        i += 1
    
    # XOR operation with the columns, the first XOR
    i = 0
    while i < len(first_column):
        first_column[i] = hex(int(last_column[i], 16) ^ int(first_column[i], 16) ^int(n_column_rcon[i], 16) & 0xFF)[2:].zfill(2)
        i += 1
    
    # Second XOR
    # Obtain the second column
    i = 0
    j = 1
    while i < len(key):
        second_column.append(key[i][j])
        i += 1
    
    # The XOR operation
    i = 0
    while i < len(second_column):
        second_column[i] = hex(int(first_column[i], 16) ^ int(second_column[i], 16) & 0xFF)[2:].zfill(2)
        i += 1
    
    # Third XOR
    # Obtain the thrid column
    i = 0
    j = 2
    while i < len(key):
        thirth_column.append(key[i][j])
        i += 1
        
    # The XOR operation
    i = 0
    while i < len(thirth_column):
        thirth_column[i] = hex(int(second_column[i], 16) ^ int(thirth_column[i], 16) & 0xFF)[2:].zfill(2)
        i += 1
    
    # Forth XOR
    # Obtain the fourth column
    i = 0
    j = 3
    while i < len(key):
        fourth_column.append(key[i][j])
        i += 1
    # The XOR operation
    i = 0
    while i < len(fourth_column):
        fourth_column[i] = hex(int(thirth_column[i], 16) ^ int(fourth_column[i], 16) & 0xFF)[2:].zfill(2)
        i += 1
    
    auxiliary_key = []
    auxiliary_row = []
    
    # To introduce the columns into the matrix
    i = 0
    while i < 4:
        auxiliary_row.append(first_column[i]) # CUIDADO CON LA PRIMERA FILA QUE ESTÁ MAL, PERO EL RESTO NO
        auxiliary_row.append(second_column[i])
        auxiliary_row.append(thirth_column[i])
        auxiliary_row.append(fourth_column[i])
        auxiliary_key.append(auxiliary_row)
        auxiliary_row = []
        i += 1
             
    return auxiliary_key
