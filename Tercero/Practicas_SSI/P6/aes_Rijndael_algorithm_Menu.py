""""
 @file aes_Rijndael_algorithm_Menu.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

from aes_Rijndael_algorithm_addRoundKey import addRoundKey

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
    
    addRoundKey(key, text_block)
