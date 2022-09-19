""""
 @file aes_Rijndael_algorithm_Menu.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of CBC cipher mode
 @version 0.1
 @date 2022-04-19
  
 @copyright Copyright (c) 2022
"""

from aes_Rijndael_algorithm_addRoundKey import addRoundKey
from aes_Rijndael_algorithm_ByteSub import ByteSub
from aes_Rijndael_algorithm_ShiftRow import ShiftRow
from aes_Rijndael_algorithm_MixColumn import MixColumn
from aes_Rijndael_algorithm_key_extension import Key_extension
from aes_Rijndael_algorithm_print import Result_Print

def CBC_on_AES(key, text_block, array_IV):
    # Separation of the hexadecimal string into matrix
    key_matrix = []
    text_block_matrix = []
    array_IV_matrix = []
    
    i = 0
    j = 0
    counter = 0
    auxiliary_string_key = ''
    auxiliary_string_matrix = ''
    auxiliary_string_array_IV = ''
    while i < 32: # This is the divition
        j = i
        while counter < 2:
            auxiliary_string_key = auxiliary_string_key + key[j]
            auxiliary_string_matrix = auxiliary_string_matrix + text_block[j]
            auxiliary_string_array_IV = auxiliary_string_array_IV + array_IV[j]
            counter += 1
            j += 1
        key_matrix.append(auxiliary_string_key)
        text_block_matrix.append(auxiliary_string_matrix)
        array_IV_matrix.append(auxiliary_string_array_IV)
        auxiliary_string_matrix = ''
        auxiliary_string_array_IV = ''
        auxiliary_string_key = ''
        counter = 0
        i += 2
        
    # Convert in a real matrix to rotate the rows
    key_matrix_auxiliary = []
    key_matrix_converted = []
    i = 0
    j = 0
    counter = 0
    while i < len(key_matrix):
        if (counter < 4):
            j = i
            while j < len(key_matrix):
                key_matrix_auxiliary.append(key_matrix[j])
                j += 4
            key_matrix_converted.append(key_matrix_auxiliary)
            key_matrix_auxiliary = []
        counter += 1
        i += 1
        
    # Convert in a real matrix to rotate the rows
    text_block_auxiliary = []
    text_block_converted = []
    i = 0
    j = 0
    counter = 0
    while i < len(text_block_matrix):
        if (counter < 4):
            j = i
            while j < len(text_block_matrix):
                text_block_auxiliary.append(text_block_matrix[j])
                j += 4
            text_block_converted.append(text_block_auxiliary)
            text_block_auxiliary = []
        counter += 1
        i += 1
        
    # Convert the IV array into a matrix
    array_IV_auxiliary = []
    array_IV_converted = []
    i = 0
    j = 0
    counter = 0
    while i < len(array_IV_matrix):
        if (counter < 4):
            j = i
            while j < len(array_IV_matrix):
                array_IV_auxiliary.append(array_IV_matrix[j])
                j += 4
            array_IV_converted.append(array_IV_auxiliary)
            array_IV_auxiliary = []
        counter += 1
        i += 1
       
    # XOR operation to make the CBC operation
    i = 0
    j = 0
    auxiliary_row = []
    result_auxiliary = 0
    result_matrix = []
    while i < len(array_IV_converted):
        while j < len(array_IV_converted[i]):
            result_auxiliary = hex(int(array_IV_converted[i][j], 16) ^ int(text_block_converted[i][j], 16) & 0xFF)[2:].zfill(2)
            auxiliary_row.append(result_auxiliary)
            j += 1
        result_matrix.append(auxiliary_row)
        auxiliary_row = []
        j = 0
        i += 1
        
    text_block_converted = []
    text_block_converted = result_matrix
       
    print()
    Result_Print(0, text_block_converted, key_matrix_converted)
    
    # This is the initial Round
    cipher_text_block = addRoundKey(key_matrix_converted, text_block_converted) # This is the first iteration
    # This is the standard Round
    i = 1
    while i <= 9:
        cipher_text_block = ByteSub(cipher_text_block, 0)
        cipher_text_block = ShiftRow(cipher_text_block)
        cipher_text_block = MixColumn(cipher_text_block)
        key_matrix_converted = Key_extension(key_matrix_converted, i)
        cipher_text_block = addRoundKey(key_matrix_converted, cipher_text_block)
        Result_Print(i, cipher_text_block, key_matrix_converted)
        i += 1
    
    # This is the las Round    
    cipher_text_block = ByteSub(cipher_text_block, 0)
    cipher_text_block = ShiftRow(cipher_text_block)
    key_matrix_converted = Key_extension(key_matrix_converted, 10)
    cipher_text_block = addRoundKey(key_matrix_converted, cipher_text_block)
    Result_Print(10, cipher_text_block, key_matrix_converted)
    
    auxiliary_cipher_text_block = ''
    i = 0
    j = 0
    while i < len(cipher_text_block):
        while j < len(cipher_text_block[i]):
            auxiliary_cipher_text_block = auxiliary_cipher_text_block + cipher_text_block[j][i]
            j += 1
        j = 0
        i += 1
     
    print()
    print(f'Bloque de texto cifrado: {auxiliary_cipher_text_block}')
    
    return auxiliary_cipher_text_block