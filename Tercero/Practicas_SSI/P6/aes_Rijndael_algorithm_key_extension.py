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
    forth_column = []
    auxiliary_key = []
    i = 0
    j = len(key) - 1
    # To exchange the last column
    while i < len(key):
        if (i == 0) and (j == (len(key) - 1)):
            auxiliary_value = key[i][j]
            key[i].remove(auxiliary_value)
            i += 1
            while i < len(key):
                previous_value = key[i][j]
                key[i-1].append(previous_value)
                key[i].remove(previous_value)
                i += 1
            i = 0
        if (i == (len(key) - 1)) and (j == (len(key) - 1)):
            key[i].append(auxiliary_value)
        i += 1
          
    # Realize subBytes with the last column
    i = 0
    j = len(key) - 1
    while i < len(key):  # To obtain the last column to realize the subbytes operation
        forth_column.append(key[i][j])
        i += 1
        
    forth_column = ByteSub(forth_column, 1)
    
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
        first_column[i] = hex(int(forth_column[i], 16) ^ int(first_column[i], 16) ^int(n_column_rcon[i], 16) & 0xFF)[2:].zfill(2)
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
    # Obtain the forth column
    i = 0
    j = 3
    forth_column.clear()
    while i < len(key):
        forth_column.append(key[i][j])
        i += 1
        
    
    # The XOR operation
    i = 0
    while i < len(forth_column):
        forth_column[i] = hex(int(thirth_column[i], 16) ^ int(forth_column[i], 16) & 0xFF)[2:].zfill(2)
        i += 1
    
    auxiliary_key.append(first_column)
    auxiliary_key.append(second_column)
    auxiliary_key.append(thirth_column)
    auxiliary_key.append(forth_column)
    
    print()
    print('Finalmente, la subclave generada es: ')
    
    print()
    i = 0
    j = 0
    while i < len(auxiliary_key):
        while j < len(auxiliary_key[i]):
            print(auxiliary_key[i][j], end=' ')
            j += 1
        print()
        j = 0
        i += 1
    
    