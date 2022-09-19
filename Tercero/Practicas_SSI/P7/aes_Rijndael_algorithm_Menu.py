""""
 @file aes_Rijndael_algorithm_Menu.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

from cbc_mode_cipher_block import CBC_on_AES

def Menu():
    print()
    print('<< BIENVENIDO A AES IMPLEMENTADO MEDIANTE EL ALGORITMO DE RIJDAEL >>')
    print()
    key = input('Introduzca la clave hexadecimal la cual quiere hacer uso: ')
    array = input('Introduzca el vector de inicialización para CBC : ')
    text_block1 = input('Introduzca el primer bloque hexadecimal de texto original el cual quiere hacer uso: ')
    text_block2 = input('Introduzca el segundo bloque hexadecimal de texto original el cual quiere hacer uso: ')
    
    if (len(key) != 32) or (len(text_block1) != 32) or (len(text_block2) != 32) or (len(array) != 32):
        print('<< VALORES INTRODUCIDO NO SOPORTADOS >>')
        print('La clave o el bloque de texto ha sido introducido de manera incorrecta.')
        print('Ambos deben de ser de 16 bytes.')
        print('<< Salida del programa >>')
        exit(1)
    
    print()
    print('Los valores introducidos inicialmente son: ')
    print(f'Clave: {key}')
    print(f'El vector de inicialización es {array}')
    print(f'Primer bloque de texto original: {text_block1}')
    print(f'Segundo bloque de texto original: {text_block2}')
    
    result = CBC_on_AES(key, text_block1, array)
    CBC_on_AES(key, text_block2, result)
    
