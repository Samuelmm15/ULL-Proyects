""""
 @file gps_c-a.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of C/A GPS encryption
 @version 0.1
 @date 2022-03-16
  
 @copyright Copyright (c) 2022
"""

# Library declaration

# Function declaration
from typing import final


def Menu():
    print('<< BIENVENIDO A C/A GPS >>')
    print()
    
    satellite_ID = input('Introduzca el ID del satélite el cual quiere hacer uso: ')
    print()
    exit_long = input('Introduzca la longitud de la secuencia de salida: ')
    
    print()
    print(f'El ID del satélite seleccionado es {satellite_ID} y la longitud seleccionada de la secuencia de salida es {exit_long}')
    gps_c_a_encryption(satellite_ID, exit_long)
    
def value_table(satellite_ID):
    final_satellite_ID = list(range(2))
    if satellite_ID == '1':
        final_satellite_ID = [2, 6]
    elif satellite_ID == '2':
        final_satellite_ID = [3, 7]
    elif satellite_ID == '3':
        final_satellite_ID = [4, 8]
    elif satellite_ID == '4':
        final_satellite_ID = [5, 9]
    elif satellite_ID == '5':
        final_satellite_ID = [1, 9]
    elif satellite_ID == '6':
        final_satellite_ID = [2, 10]
    elif satellite_ID == '7':
        final_satellite_ID = [1, 8]
    elif satellite_ID == '8':
        final_satellite_ID = [2, 9]
    elif satellite_ID == '9':
        final_satellite_ID = [3, 10]
    elif satellite_ID == '10':
        final_satellite_ID = [2, 3]
    elif satellite_ID == '11':
        final_satellite_ID = [3, 4]
    elif satellite_ID == '12':
        final_satellite_ID = [5, 6]
    elif satellite_ID == '13':
        final_satellite_ID = [6, 7]
    elif satellite_ID == '14':
        final_satellite_ID = [7, 8]
    elif satellite_ID == '15':
        final_satellite_ID = [8, 9]
    elif satellite_ID == '16':
        final_satellite_ID = [9, 10]
    elif satellite_ID == '17':
        final_satellite_ID = [1, 4]
    elif satellite_ID == '18':
        final_satellite_ID = [2, 5]
    elif satellite_ID == '19':
        final_satellite_ID = [3, 6]
    elif satellite_ID == '20':
        final_satellite_ID = [4, 7]
    elif satellite_ID == '21':
        final_satellite_ID = [5, 8]
    elif satellite_ID == '22':
        final_satellite_ID = [6, 9]
    elif satellite_ID == '23':
        final_satellite_ID = [1, 3]
    elif satellite_ID == '24':
        final_satellite_ID = [4, 6]
    elif satellite_ID == '25':
        final_satellite_ID = [5, 7]
    elif satellite_ID == '26':
        final_satellite_ID = [6, 8]
    elif satellite_ID == '27':
        final_satellite_ID = [7, 9]
    elif satellite_ID == '28':
        final_satellite_ID = [8, 10]
    elif satellite_ID == '29':
        final_satellite_ID = [1, 6]
    elif satellite_ID == '30':
        final_satellite_ID = [2, 7]
    elif satellite_ID == '31':
        final_satellite_ID = [3, 8]
    elif satellite_ID == '32':
        final_satellite_ID = [4, 9]
    return final_satellite_ID
def gps_c_a_encryption(satellite_ID, exit_long):
    LFSR1_array = []
    LFSR2_array = []
    final_taps = []
    
    # Initialization
    i = 0
    while i < 10:
        LFSR1_array.append('1')
        LFSR2_array.append('1')
        i += 1
    final_taps = value_table(satellite_ID)
    
    print()
    print('De manera inicial se tiene: ')
    print(f'LFSR1: {LFSR1_array}')
    print(f'LFSR2: {LFSR2_array}')
    print(f'G2 taps: {final_taps}')
    


# Main function
if __name__ == '__main__':
    Menu()
