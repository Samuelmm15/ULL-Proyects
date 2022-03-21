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

from os import lseek
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
def gps_c_a_table(LFSR1, LFSR2, feedback_LFSR1, feedback_LFSR2, C_A_code):
    print(LFSR1, end='         ')
    print(feedback_LFSR1, end='           ')
    print(LFSR2, end='         ')
    print(feedback_LFSR2, end='                 ')
    print(C_A_code)

def gps_c_a_encryption(satellite_ID, exit_long):
    final_taps = []
    
    # Initialization
    LFSR1 = '1111111111'
    LFSR2 = '1111111111'
    final_taps = value_table(satellite_ID)
    
    print()
    print('De manera inicial se tiene: ')
    print(f'LFSR1: {LFSR1}')
    print(f'LFSR2: {LFSR2}')
    print(f'G2 taps: {final_taps}')
    
    i = 0
    first_position = 0
    second_position = 0
    LFSR1_operator = 0
    LFSR2_operator = 0
    feedback_LFSR1 = 0
    feedback_LFSR2 = 0
    C_A_secuence = []
    print()
    print('LFSR1', end='          ')
    print('realimentación', end='  ')
    print('LFSR2', end='          ')
    print('realimentación', end='   ')
    print('Secuencia C/A PRN1')
    feedback_LFSR1 = 0
    feedback_LFSR2 = 0
    auxiliary = 1
    gps_c_a_table(LFSR1, LFSR2, feedback_LFSR1, feedback_LFSR2, auxiliary)
    while i < (int(exit_long) - 1):
        LFSR1_tap1 = 3
        LFSR1_tap2 = 10
        LFSR2_tap1 = final_taps[0]
        LFSR2_tap2 = final_taps[1]
        # LFSR1 operation
        first_position = LFSR1[LFSR1_tap1 - 1]
        second_position = LFSR1[LFSR1_tap2 - 1]
        feedback_LFSR1 = bin(int(first_position, 2) ^ int(second_position, 2))[2:]
        # scrolling
        LFSR1 = feedback_LFSR1 + str(LFSR1)
        LFSR1 = bin((int(LFSR1, 2) >> 1))[2:].zfill(10)
        # LFSR2 operation
        first_position = LFSR2[LFSR2_tap1 - 1]
        second_position = LFSR2[LFSR2_tap2 - 1]
        first_xor = bin(int(LFSR2[9], 2) ^ int(LFSR2[8], 2) ^ int(LFSR2[7], 2) ^ int(LFSR2[5], 2))[2:]
        second_xor = bin(int(LFSR2[1], 2) ^ int(LFSR2[2], 2) ^ int(first_xor, 2))
        feedback_LFSR2 = bin(int(second_xor, 2))[2:]
        # scrolling
        LFSR2 = feedback_LFSR2 + str(LFSR2)
        LFSR2 = bin(int(LFSR2, 2) >> 1)[2:].zfill(10)
        # C/A Code
        LFSR1_operator = LFSR1[9]
        LFSR2_operator = feedback_LFSR2
        auxiliary = bin(int(LFSR1_operator, 2) ^ int(LFSR2_operator, 2))[2:]
        C_A_secuence.append(auxiliary)
        gps_c_a_table(LFSR1, LFSR2, feedback_LFSR1, feedback_LFSR2, auxiliary)
        i += 1
        


# Main function
if __name__ == '__main__':
    Menu()
