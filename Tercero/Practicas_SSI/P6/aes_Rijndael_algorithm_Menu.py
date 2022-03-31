""""
 @file aes_Rijndael_algorithm_Menu.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

from aes_Rijndael_algorithm_addRoundKey import addRoundKey
from aes_Rijndael_algorithm_ByteSub import ByteSub

def Menu():
    print()
    print('<< BIENVENIDO A AES IMPLEMENTADO MEDIANTE EL ALGORITMO DE RIJDAEL >>')
    print()
    key = input('Introduzca la clave hexadecimal la cual quiere hacer uso: ')
    text_block = input('Introduzca el bloque de hexadecimal el cual quiere hacer uso: ')
    
    if (len(key) != 32) or (len(text_block) != 32):
        print('<< VALORES INTRODUCIDO NO SOPORTADOS >>')
        print('La clave o el bloque de texto ha sido introducido de manera incorrecta.')
        print('Ambos deben de ser de 16 bytes.')
        print('<< Salida del programa >>')
        exit(1)
    
    print()
    print('Los valores introducidos inicialmente son: ')
    print(f'Clave: {key}')
    print(f'Bloque de texto original: {text_block}')
    
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
    print('Las matrices iniciales son: ')
    
    i = 0
    j = 0
    counter = 0
    while i < len(key_matrix):
        j = i
        if counter < 4:
            while j < len(key_matrix):
                print(key_matrix[j], end=' ')
                j += 4
            print()
        counter += 1
        i += 1
    print()
    
    i = 0
    j = 0
    counter = 0
    while i < len(text_block_matrix):
        j = i
        if counter < 4:
            while j < len(text_block_matrix):
                print(text_block_matrix[j], end=' ')
                j += 4
            print()
        counter += 1
        i += 1
    
    # This is the initial Round
    cipher_text_block = addRoundKey(key_matrix, text_block_matrix)
    cipher_text_block = ByteSub(cipher_text_block)
    # This is the standard Round
    i = 0
    while i < 9:
        i += 1
