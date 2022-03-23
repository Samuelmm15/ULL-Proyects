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
    key_seed = []
    value = -1
    while value != 0:
        value = int(input("Para comenzar introduzca la semilla de clave (introduzca cero para dejar de introducir valores): "))
        if value != 0:
            key_seed.append(value)
    value = -1
    original_message = []
    while value != 0:
        value = int(input("Introduzca el texto que desea cifrar (introduzca cero para dejar de introducir valores): "))
        if value != 0:
            original_message.append(value)
    print()
    print(f"La clave introducida es {key_seed}")
    print(f"El mensaje a cifrar es {original_message}")
    
    RC4_encryption(key_seed, original_message)

# Fuction that make the RC4 encryption
def RC4_encryption(key_seed, original_message):
    # Start with the inicialization of the KSA
    S_array = []  # Zero inicialization of the arrays
    K_array = []
    seed_length = len(key_seed)    
    i = 0
    j = 0
    while i != 256:
        S_array.append(i)
        K_array.append(key_seed[j])
        i += 1
        j+= 1
        if j == len(key_seed):
            j = 0
    print()
    print(S_array)  # Comprobation of the inicialization
    print()
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
    print()
    print(S_array)
    
    # Start with the second part of the encrypt secuence
    k = 0
    byte = 1
    i = 0
    j = 0
    
    while (k != len(original_message)):
        i = (i + 1) % 256
        j = (j + S_array[i]) % 256
        auxiliary = S_array[i] # At this point produce the exchange of the list values
        S_array[i] = S_array[j]
        S_array[j] = auxiliary
        t = (S_array[i] + S_array[j]) % 256
    
        # Convert S[t] result into a binary number
        binary_S = format(S_array[t], "08b")
    
        print()
        print(f"El byte {byte} de secuencia cifrante es: S[{t}] = {S_array[t]}, en binario es {binary_S}")
    
        # Convert original_message into a binary number
        binary_original_message = format(original_message[k], "08b")
    
        print(f"El byte {byte} de texto original es: M[{byte}] = {original_message[k]}, en binario es {binary_original_message}")
    
        # Convert the original message into a encrypt message
        encrypt_message = []
        l = 0
        for x in binary_S:
            encrypt_message_auxiliary = bin(int(x, 2) ^ int(binary_original_message[l], 2))
            encrypt_message.append(encrypt_message_auxiliary[2:])
            l += 1
    
        final_encrypt_message = "" # The union of the binary encrypt message
        for x in encrypt_message:
            final_encrypt_message += str(x)
            
        # Binary to decimal convertion
        decimal_encrypt_convertion = 0;
        for position, x in enumerate(encrypt_message[::-1]):
            decimal_encrypt_convertion += int(x) * 2 ** position
    
        print(f"El byte {byte} de texto cifrado es C[{byte}] = {decimal_encrypt_convertion} en binario {final_encrypt_message}")
    
        k += 1
        byte += 1
    
# Main Fuction
if __name__ == '__main__':
    Menu()