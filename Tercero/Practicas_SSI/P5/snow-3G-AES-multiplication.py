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
        
def Table_print(result):
    print(f'{result}', end='     ')

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
    
    # Table inicilization
    i = 0
    print()
    while i < 8:
        print(f'{i}', end='            ');
        i += 1
    print()
    
    # Multiplication algorithm
    k = 1
    l = 0
    result = []
    auxiliary_result = 0
    # First iteration
    table = first_byte
    Table_print(table)
    if second_byte[7] == '1':
        result.append(table)
    # Scrolling
    table = bin(int(table, 2) << 1)[2:].zfill(8)
    if len(table) > 8:
        table = bin(int(table, 2))[3:]
    if second_byte[6] == '1':
        result.append(table)
    Table_print(table)
    l = 5
    while k < 7:
        if table[0] == '1': # Table iteration
            table = bin((int(table, 2) << 1))[2:].zfill(8)
            auxiliary = ''
            j = 1
            while j < len(table): # To obtain the first operator
                auxiliary = auxiliary + table[j]
                j += 1
            table = auxiliary
            auxiliary_result = bin(int(table, 2) ^ int(algorithm_byte, 2))[2:].zfill(8)
            table = auxiliary_result
            Table_print(table)
        else:
            table = bin(int(table, 2) << 1)[2:].zfill(8)
            Table_print(table)
        if second_byte[l] == '1':
            result.append(table)
        l -= 1
        k += 1
        
    print()
    m = 1
    final_result = result[0]
    while m < len(result):
        final_result = bin(int(final_result, 2) ^ int(result[m], 2))[2:]
        m += 1
    print()
    print(f'El resultado final de la multiplicación es: {final_result}')
    print()
    
def AES_multplication(first_byte, second_byte):
    # Start
    print()
    print(f'El primer byte es: {first_byte}')
    print(f'El segundo byte es: {second_byte}')
    print('El algoritmo seleccionado es: AES')
    print()
    
    # Initialization
    algorithm_byte = '00011011'
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
    
    # Table inicilization
    i = 0
    print()
    while i < 8:
        print(f'{i}', end='            ');
        i += 1
    print()
    
    # Multiplication algorithm
    k = 1
    l = 0
    result = []
    auxiliary_result = 0
    # First iteration
    table = first_byte
    Table_print(table)
    if second_byte[7] == '1':
        result.append(table)
    # Scrolling
    if table[0] == '1': # Table iteration
        table = bin((int(table, 2) << 1))[2:].zfill(8)
        auxiliary = ''
        j = 1
        while j < len(table): # To obtain the first operator
            auxiliary = auxiliary + table[j]
            j += 1
        table = auxiliary
        auxiliary_result = bin(int(table, 2) ^ int(algorithm_byte, 2))[2:].zfill(8)
        table = auxiliary_result
    else:
        table = bin(int(table, 2) << 1)[2:].zfill(8)
    if second_byte[6] == '1':
        result.append(table)
    Table_print(table) # Second iteration
    l = 5
    while k < 7:
        if table[0] == '1': # Table iteration
            table = bin((int(table, 2) << 1))[2:].zfill(8)
            auxiliary = ''
            j = 1
            while j < len(table): # To obtain the first operator
                auxiliary = auxiliary + table[j]
                j += 1
            table = auxiliary
            auxiliary_result = bin(int(table, 2) ^ int(algorithm_byte, 2))[2:].zfill(8)
            table = auxiliary_result
            Table_print(table)
        else:
            table = bin(int(table, 2) << 1)[2:].zfill(8)
            Table_print(table)
        if second_byte[l] == '1':
            result.append(table)
        l -= 1
        k += 1
        
    print()
    m = 1
    final_result = result[0]
    print()
    while m < len(result):
        final_result = bin(int(final_result, 2) ^ int(result[m], 2))[2:].zfill(8)
        m += 1
    print()
    print(f'El resultado final de la multiplicación es: {final_result}')
    print()

# Main Function
if __name__ == '__main__':
    Menu()