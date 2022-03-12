""""
 @file chacha20.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Chacha20 encryption
 @version 0.1
 @date 2022-03-10
  
 @copyright Copyright (c) 2022
"""

# Libraries declaration
from itertools import count
from msilib.schema import Binary
import re
import secrets

# Function declaration
def Menu():
    print("<< Bienvenido al programa de cifrado Chacha20 >>")
    print()
    
    hexadecimal_key = input("Introduzca la clave de cifrado: ")
    hexadecimal_counter = input("Introduzca el contador: ")
    hexadecimal_nonce = Aleatory_Nonce()
    
    Chacha20_Encryption(hexadecimal_key, hexadecimal_counter, hexadecimal_nonce)
    
def Aleatory_Nonce():
    number_of_bytes = 12 # This is the 96 bits or 12 bytes
    random_generator = secrets.token_hex(number_of_bytes) # This fuction generates aleatory tokens
    # print(random_generator) # To comprobe
    
    i = 0
    counter = 0
    nonce_result = ""
    while i != len(random_generator):
        if counter == 2:
            nonce_result = nonce_result + ":"
            nonce_result = nonce_result + random_generator[i]
            counter = 0
        else:
            nonce_result = nonce_result + random_generator[i]
        counter += 1
        i += 1

    # print()
    # print(nonce_result) # To comprobe the result
    
    return nonce_result
    
def ROTL(a_number, b_number): # esta mierda no funciona nada bien
    a_number = bin(int(a_number, 16))[2:]
    number_b = str(b_number)
    number_b = bin(int(number_b, 16))[2:]
    number_substract = str('32')
    number_substract = bin(int(number_substract, 16))[2:]
    auxiliary_array = list(range(4))
    auxiliary_array[0] = a_number
    auxiliary_array[1] = number_b
    auxiliary = bin(int(auxiliary_array[0], 2))
    auxiliary_array[2] = bin(int(auxiliary,2)<<b_number)[2:]
    auxiliary = bin(int(number_substract, 2) - int(auxiliary_array[1], 2))[2:]
    auxiliary_array[3] = bin(int(auxiliary_array[0], 2)> 32 - b_number)[2:]
    auxiliary_array[0] = bin(int(auxiliary_array[2], 2) | int(auxiliary_array[3], 2))[2:]
    auxiliary = hex(int(auxiliary_array[0], 2))[2:]
    print(auxiliary)
    return auxiliary
    
    
def QR(a_number, b_number, c_number, d_number, QR_array):
    QR_array[a_number] = hex(int(QR_array[a_number], 16) + int(QR_array[b_number], 16))[2:]
    QR_array[d_number] = hex(int(QR_array[d_number], 16) ^ int(QR_array[a_number], 16))[2:]
    QR_array[d_number] = ROTL(QR_array[d_number], 16)
    
    QR_array[c_number] = hex(int(QR_array[c_number], 16) + int(QR_array[d_number], 16))[2:]
    QR_array[b_number] = hex(int(QR_array[b_number], 16) ^ int(QR_array[c_number], 16))[2:]
    QR_array[b_number] = ROTL(QR_array[b_number], 12)
    
    QR_array[a_number] = hex(int(QR_array[a_number], 16) + int(QR_array[b_number], 16))[2:]
    QR_array[d_number] = hex(int(QR_array[d_number], 16) ^ int(QR_array[a_number], 16))[2:]
    QR_array[d_number] = ROTL(QR_array[d_number], 8)
    
    QR_array[c_number] = hex(int(QR_array[c_number], 16) + int(QR_array[d_number], 16))[2:]
    QR_array[b_number] = hex(int(QR_array[b_number], 16) ^ int(QR_array[c_number], 16))[2:]
    QR_array[b_number] = ROTL(QR_array[b_number], 7)
    
def Chacha20_Encryption(hexadecimal_key, hexadecimal_counter, hexadecimal_nonce):
    S_initial = list(range(16))
    
    # Constat initialization
    S_initial[0] = '61707865'
    S_initial[1] = '3320646e'
    S_initial[2] = '79622d32'
    S_initial[3] = '6b206574'
    
    # Key initialization
    hexadecimal_key = str(hexadecimal_key)
    hexadecimal_key = hexadecimal_key.replace(':', '')
    k = 4
    l = 0
    counter = 0
    aux_string = ''
    while k < 12:
        while counter != 8:
            aux_string = aux_string + hexadecimal_key[l]
            counter += 1
            l += 1
        S_initial[k] = aux_string
        # print(S_initial[k]) # To comprobe
        aux_string = ''
        k += 1
        counter = 0
    
    # Counter initialization
    hexadecimal_counter = str(hexadecimal_counter)
    hexadecimal_counter = hexadecimal_counter.replace(':', '')
    S_initial[12] = hexadecimal_counter
    
    # Nonce initilization
    hexadecimal_nonce = str(hexadecimal_nonce)
    hexadecimal_nonce = hexadecimal_nonce.replace(':', '')
    k = 13
    l = 0
    counter = 0
    aux_string = ''
    while k < 16:
        while counter != 8:
            aux_string = aux_string + hexadecimal_nonce[l]
            counter += 1
            l += 1
        S_initial[k] = aux_string
        aux_string = ''
        k += 1
        counter = 0
        
    print()
    print('ESTADO INICIAL= ')
    print(S_initial) # To comprobe
    
    ROUNDS = 20 # This is the const of the number of rounds
    S_result = [];
    
    # Binary transformation
    i = 0
    while i < 16:
        # auxiliary_S = bin(int(S_initial[i], 16))[2:].zfill(32) # with the 16, the hexadecimal number is converted into decimal, and the, the decimal number into binary
        S_result.append(S_initial[i]) # with zfill, the binary number is refill with zeros
        i += 1

    # print()
    # print(S_result) # Necesary to comprobe
    # print
    
    # Interactions to transform
    i = 0
    while i < ROUNDS:
        # Column Round
        QR(0, 4, 8, 12, S_result); # columna 0
        QR(1, 5, 9, 13, S_result); # columna 1
        QR(2, 6, 10, 14, S_result); # columna 2
        QR(3, 7, 11, 15, S_result); # columna 3
        # Diagonal Round 
        QR(0, 5, 10, 15, S_result); # diagonal 1
        QR(1, 6, 11, 12, S_result); # diagonal 2
        QR(2, 7, 8, 13, S_result); # diagonal 3
        QR(3, 4, 9, 14, S_result); # diagonal 4
        i += 2
    
    print('ESTADO FINAL TRAS LAS 20 INTERACCIONES: ')
    print(S_result)
          
    # EN ESTE PUNTO FALTA EL ÚLTIMO BUCLE FOR DEL ALGORITMO DE LOS APUNTES DE LA ASIGNATURA


# Main Function
if __name__ == '__main__':
    Menu()


# Generador de tokens aleatorios de cualquier tipo
# https://docs.python.org/es/3.10/library/secrets.html#secrets.token_bytes
# Conversor de hexadecimal a binario
# https://www.delftstack.com/es/howto/python/python-hex-to-int/
# Binary numbers
# https://www.techiedelight.com/how-to-convert-an-integer-to-a-binary-string-in-python/#:~:text=format()%20function,the%20string%20presentation%20type%20b%20.