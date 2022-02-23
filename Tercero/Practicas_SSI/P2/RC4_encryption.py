""""
 @file Vernam_encryption.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of RC4 encryption
 @version 0.1
 @date 2022-02-23
  
 @copyright Copyright (c) 2022
"""

# Libraries declaration

# Fuction declaration
# Menu neccesary to input the paramethers of the encryption
from re import S


def Menu():
    print("<< Bienvenido al programa de cifrado RC4 >>")
    print()
    print("Para comenzar introduzca la semilla de clave: ")
    key_seed = input()
    print("Introduzca el texto que desea cifrar: ")
    original_message = input()
    
    RC4_encryption(key_seed, original_message)

# Fuction that make the RC4 encryption
def RC4_encryption(key_seed, original_message):
    # Start with the inicialization of the KSA
    S_array = []  # Zero inicialization of the arrays
    K_array = []
    seed_length = 256    # HAY QUE TENER EN CUENTA QUE EL TAMAÑO DE LA SEMILLA DEPENDE, PUEDE PONERSE QUE SE INTRODUZCA POR TECLADO
    i = 0
    while i != 256:
        S_array.append(i)
        K_array.append(i % seed_length)
        i += 1
    print(S_array)  # Comprobation of the inicialization
    print(K_array)
    
    j = 0
    i = 0
    while i != 256:
        j = (j + S_array[i] + K_array[i]) % 256
        auxiliary = S_array[i]  # De esta manera se realiza el intercambio de los valores de las listas
        S_array[i] = S_array[j]
        S_array[j] = auxiliary
        i += 1
    print()
    print("Tras la inicialización de los arrys se obtiene: ")
    print(S_array)
    
    # Start with the second part of the encrypt secuence
    i = 0
    j = 0
    i = (i + 1) % 256
    j = (j + S_array[i]) % 256
    auxiliary = S_array[i] # At this point produce the exchange of the list values
    S_array[i] = S_array[j]
    S_array[j] = auxiliary
    t = (S_array[i] + S_array[j]) % 256
    
    # Convert S[t] result into a binary number
    binary_S = format(S_array[t], "08b")
    
    print(f"El byte 1 de texto cifrado es {S_array[t]}, en binario es {binary_S}")
    
# Main Fuction
if __name__ == '__main__':
    Menu()