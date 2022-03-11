""""
 @file chacha20.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Chacha20 encryption
 @version 0.1
 @date 2022-03-10
  
 @copyright Copyright (c) 2022
"""

# Libraries declaration
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
    print(random_generator)
    
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

    print()
    print(nonce_result) # To comprobe the result
    
    return nonce_result
    
def ROTL(a_number, b_number):
    return (((int(a_number)) << (int(b_number))) | ((int(a_number)) >> (32 - (int(b_number)))))
    
def QR(a_number, b_number, c_number, d_number):
    QR_array = []
    QR_array.append(a_number + b_number)
    d_number = bin(int(d_number, 2) ^ int(a_number, 2))
    QR_array.append(d_number[2:])
    QR_array.append(ROTL(d_number[2:], 16))
    
    QR_array.append(c_number + d_number[2:])
    b_number = bin(int(b_number, 2) ^ int(c_number, 2))
    QR_array.append(b_number[2:])
    QR_array.append(ROTL(b_number[2:], 12))
    
    QR_array.append(a_number + b_number[2:])
    d_number = bin(int(d_number, 2) ^ int(a_number, 2))
    QR_array.append(d_number[2:])
    QR_array.append(ROTL(d_number[2:], 8))
    
    QR_array.append(c_number + d_number[2:])
    b_number = bin(int(b_number, 2) ^ int(c_number, 2))
    QR_array.append(b_number[2:])
    QR_array.append(ROTL(b_number[2:], 7))
    
    return QR_array
    
def Chacha20_Encryption(hexadecimal_key, hexadecimal_counter, hexadecimal_nonce):
    ROUNDS = 20 # This is the const of the number of rounds
    result = [];
    
    i = 0
    binary_key = format(int(hexadecimal_key[i]), "08b")
    while i < 23:
        if hexadecimal_key[i] != ':':
            binary_key = format(int(hexadecimal_key[i]), "08b")
            result.append(binary_key)
        
        i += 1

    print(result) # Necesary to comprobe
    print
    
    i = 0
    while i < ROUNDS:
        print(QR(result[0], result[4], result[8], result[12]))
        print()
        print(QR(result[1], result[5], result[9], result[13]))
        print()
        print(QR(result[2], result[6], result[11], result[15]))
        print()
        
        print(QR(result[0], result[5], result[10], result[15]))
        print()
        print(QR(result[1], result[6], result[11], result[12]))
        print()
        print(QR(result[2], result[7], result[8], result[13]))
        print()
        print(QR(result[3], result[4], result[9], result[14]))
        print()
        i += 2
          
    # EN ESTE PUNTO FALTA EL ÚLTIMO BUCLE FOR DEL ALGORITMO DE LOS APUNTES DE LA ASIGNATURA


# Main Function
if __name__ == '__main__':
    Menu()


# Generador de tokens aleatorios de cualquier tipo
# https://docs.python.org/es/3.10/library/secrets.html#secrets.token_bytes