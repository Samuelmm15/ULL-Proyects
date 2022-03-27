""""
 @file snow-3G-AES-multiplication.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Snow 3G and AES binary
 multiplication
 @version 0.1
 @date 2022-03-27
  
 @copyright Copyright (c) 2022
"""

# Library declaration

# Function declaration

from unittest import result


def Menu():
    print()
    print('Bienvenido a << SNOW 3G OR AES MULTIPLICATION >>')
    print()
    first_byte = input('Introduzca el primer byte a multiplicar: ')
    second_byte = input('Introduzca el segundo byte a multiplicar: ')
    selection = input('Introduzca el tipo de multiplicación la cual quiere hacer uso (SNOW 3G/AES): ')
    if selection == 'SNOW 3G':
        SNOW3G_multiplication(first_byte, second_byte)
    elif selection == 'AES':
        AES_multplication(first_byte, second_byte)
    elif ((selection != 'SNOW 3G') or (selection != 'AES')):
        print()
        print('<< Opción seleccionada no soportada. >>')
        exit(1);
        
def SNOW3G_multiplication(first_byte, second_byte):
    # Start
    print()
    print(f'El primer byte es: {first_byte}')
    print(f'El segundo byte es: {second_byte}')
    print('El algoritmo seleccionado es: SNOW 3G')
    print()
    
    # Initialization
    algorithm_byte = '10101001'
    result = ''
    result_aux = ''
    for i in first_byte:
        result = bin(int(i, 16))[2:].zfill(4)
        result_aux = result_aux + result
    first_byte = result_aux
    
    result = ''
    result_aux = ''
    for i in second_byte:
        result = bin(int(i, 16))[2:].zfill(4)
        result_aux = result_aux + result
    second_byte = result_aux
    
    # First exit
    print(f'El primer byte convertido es: {first_byte}')
    print(f'El segundo byte convertido es: {second_byte}')
    print(f'El byte del algoritmo es: {algorithm_byte}')
    
    # Multiplication algorithm
    
    
def AES_multplication(first_byte, second_byte):
    print()

# Main Function
if __name__ == '__main__':
    Menu()