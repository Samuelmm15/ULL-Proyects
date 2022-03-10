""""
 @file chacha20.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Chacha20 encryption
 @version 0.1
 @date 2022-03-10
  
 @copyright Copyright (c) 2022
"""

# Libraries declaration
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

def Chacha20_Encryption(hexadecimal_key, hexadecimal_counter, hexadecimal_nonce):
    print()

# Main Function
if __name__ == '__main__':
    Menu()


# Generador de tokens aleatorios de cualquier tipo
# https://docs.python.org/es/3.10/library/secrets.html#secrets.token_bytes