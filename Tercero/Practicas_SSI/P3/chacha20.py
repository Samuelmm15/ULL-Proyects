""""
 @file chacha20.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Chacha20 encryption
 @version 0.1
 @date 2022-03-10
  
 @copyright Copyright (c) 2022
"""

# Libraries declaration

# Function declaration
from itertools import count

# def asint32(i):
#     return i & 0xFFFFFFFF

def Menu():
    print("<< Bienvenido al programa de cifrado Chacha20 >>")
    print()
    
    hexadecimal_key = input("Introduzca la clave de cifrado: ")
    hexadecimal_counter = input("Introduzca el contador: ")
    hexadecimal_nonce = Aleatory_Nonce()
    
    Chacha20_Encryption(hexadecimal_key, hexadecimal_counter, hexadecimal_nonce)
    
def Aleatory_Nonce():
    # number_of_bytes = 12 # This is the 96 bits or 12 bytes
    # random_generator = secrets.token_hex(number_of_bytes) # This fuction generates aleatory tokens
    # # print(random_generator) # To comprobe
    
    # i = 0
    # counter = 0
    # nonce_result = ""
    # while i != len(random_generator):
    #     if counter == 2:
    #         nonce_result = nonce_result + ":"
    #         nonce_result = nonce_result + random_generator[i]
    #         counter = 0
    #     else:
    #         nonce_result = nonce_result + random_generator[i]
    #     counter += 1
    #     i += 1
    nonce_result = '00:00:00:09:00:00:00:4a:00:00:00:00'
    # print()
    # print(nonce_result) # To comprobe the result
    
    return nonce_result
    
def ROTL(a_number, b_number): # esta mierda no funciona nada bien
    a_number = int(a_number, 16)
    auxiliary = (((a_number) << (b_number)) | ((a_number) >> (32 - (b_number))))
    auxiliary = str(auxiliary)
    auxiliary = hex(int(auxiliary))[2:]
    return auxiliary
    # auxiliary_array = list(range(4))
    # auxiliary_array[0] = int(a_number, 16)
    # auxiliary_array[1] = b_number
    # auxiliary_array[2] = auxiliary_array[0] << auxiliary_array[1]
    # auxiliary_array[3] = auxiliary_array[0] >> (32 - auxiliary_array[1])
    # auxiliary_array[0] = auxiliary_array[2] | auxiliary_array[3]
    # auxiliary_array[0] = hex(int(auxiliary_array[0]))[2:]
    # return auxiliary_array[0]
    
    
def QR(a_number, b_number, c_number, d_number, QR_array):
        # rotate = lambda v, c_number: asint32((asint32(v << c_number)) | (asint32(v >> (32 - c_number))))
        # QR_array[a_number] = asint32(QR_array[a_number] + QR_array[b_number])
        # QR_array[d_number] = asint32(rotate(QR_array[d_number] ^ QR_array[a_number], 16))
        # QR_array[c_number] = asint32(QR_array[c_number] + QR_array[d_number])
        # QR_array[b_number] = asint32(rotate(QR_array[b_number] ^ QR_array[c_number], 12))
        # QR_array[a_number] = asint32(QR_array[a_number] + QR_array[b_number])
        # QR_array[d_number] = asint32(rotate(QR_array[d_number] ^ QR_array[a_number], 8))
        # QR_array[c_number] = asint32(QR_array[c_number] + QR_array[d_number])
        # QR_array[b_number] = asint32(rotate(QR_array[b_number] ^ QR_array[c_number], 7))
    QR_array[a_number] = hex(int(QR_array[a_number], 16) + int(QR_array[b_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[a_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[a_number] = auxiliary_while
    QR_array[d_number] = hex(int(QR_array[d_number], 16) ^ int(QR_array[a_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[d_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[d_number] = auxiliary_while
    QR_array[d_number] = ROTL(QR_array[d_number], 16)[2:].zfill(8)
    auxiliary = str(QR_array[d_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[d_number] = auxiliary_while
    QR_array[c_number] = hex(int(QR_array[c_number], 16) + int(QR_array[d_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[c_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[c_number] = auxiliary_while
    QR_array[b_number] = hex(int(QR_array[b_number], 16) ^ int(QR_array[c_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[b_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[b_number] = auxiliary_while
    QR_array[b_number] = ROTL(QR_array[b_number], 12)[2:].zfill(8)
    auxiliary = str(QR_array[b_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[b_number] = auxiliary_while
    QR_array[a_number] = hex(int(QR_array[a_number], 16) + int(QR_array[b_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[a_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[a_number] = auxiliary_while
    QR_array[d_number] = hex(int(QR_array[d_number], 16) ^ int(QR_array[a_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[d_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[d_number] = auxiliary_while
    QR_array[d_number] = ROTL(QR_array[d_number], 8)[2:].zfill(8)
    auxiliary = str(QR_array[d_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[d_number] = auxiliary_while
    QR_array[c_number] = hex(int(QR_array[c_number], 16) + int(QR_array[d_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[c_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[c_number] = auxiliary_while
    QR_array[b_number] = hex(int(QR_array[b_number], 16) ^ int(QR_array[c_number], 16))[2:].zfill(8)
    auxiliary = str(QR_array[b_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[b_number] = auxiliary_while
    QR_array[b_number] = ROTL(QR_array[b_number], 7)[2:].zfill(8)
    auxiliary = str(QR_array[b_number])
    auxiliary_while = ''
    i = len(auxiliary) - 1
    counter = 0
    while i >= 0:
        if (counter < 8):
            auxiliary_while = auxiliary_while + auxiliary[i]
            counter += 1
        i -= 1
    QR_array[b_number] = auxiliary_while
    
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
        
    # Little Endian convertion
    i = 4
    while i < 16:
        auxiliary = bytearray.fromhex(S_initial[i])
        auxiliary.reverse()
        auxiliary = ''.join(format(x, '02x') for x in auxiliary)
        S_initial[i] = auxiliary
        i += 1
    
    print()
    print('ESTADO INICIAL= ')
    counter = 0 
    for line in S_initial:
        print(line, end=" ") # Neccesary to modificate the end, and prints, the matrix at the correct form
        counter += 1
        if counter == 4:
            print()
            counter = 0
        
    
    
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
    
    print()
    print('ESTADO FINAL TRAS LAS 20 INTERACCIONES: ')
    counter = 0 
    for line in S_result:
        print(line, end=" ") # Neccesary to modificate the end, and prints, the matrix at the correct form
        counter += 1
        if counter == 4:
            print()
            counter = 0
          
    i = 0
    k = 0
    l = 0
    auxiliary_while = ''
    while i < 16 :
        auxiliary = hex(int(S_initial[i], 16) + int(S_result[i], 16))[2:]
        auxiliary = str(auxiliary)
        while l < 8:
            auxiliary_while = auxiliary_while + auxiliary[l]
            l += 1
        auxiliary = auxiliary_while
        l = 0
        auxiliary_while = ''
        S_result[i] = auxiliary
        i += 1

    print()
    print('ESTADO DE SALIDA DEL GENERADOR: ')
    counter = 0 
    for line in S_result:
        print(line, end=" ") # Neccesary to modificate the end, and prints, the matrix at the correct form
        counter += 1
        if counter == 4:
            print()
            counter = 0

# Main Function
if __name__ == '__main__':
    Menu()


# IMPORTANTE
# https://programmerclick.com/article/77661695242/

# Clave a introducir
# 00:01:02:03:04:05:06:07:08:09:0a:0b:0c:0d:0e:0f:10:11:12:13:14:15:16:17:18:19:1a:1b:1c:1d:1e:1f
# Generador de tokens aleatorios de cualquier tipo
# https://docs.python.org/es/3.10/library/secrets.html#secrets.token_bytes
# Conversor de hexadecimal a binario
# https://www.delftstack.com/es/howto/python/python-hex-to-int/
# Binary numbers
# https://www.techiedelight.com/how-to-convert-an-integer-to-a-binary-string-in-python/#:~:text=format()%20function,the%20string%20presentation%20type%20b%20.
# Imprimir sin un salto de línea
# https://www.freecodecamp.org/espanol/news/salto-de-linea-en-python-como-imprimir-en-python-sin-un-salto-de-linea/