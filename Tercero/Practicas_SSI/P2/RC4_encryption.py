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
    i = 0
    while i != 255:
        S_array.append(i)
        K_array.append(i % key_seed)
        i += 1
    
    j = 0
    i = 0
    while i != 255:
        j = (j + S_array[i] + K_array[i]) % 256
        auxiliary = S_array[i]  # De esta manera se realiza el intercambio de los valores de las listas
        S_array[i] = S_array[j]
        S_array[j] = auxiliary
        i += 1
    
    print("Tras la inicialización de los arrys se obtiene: ")
    print(S_array)
    
# Main Fuction
if __name__ == '__main__':
    print()