""""
 @file Vernam_encryption.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Vernam encryption
 @version 0.1
 @date 2022-02-15
  
 @copyright Copyright (c) 2022
"""

# Neccesary libraries

import random
import sys

# Fuctions declarations

# Fuction neccesary to encrypt the message entered by keyboard
def Vernam_encryption(encrypt_message):    
    print()
    print(f"El mensaje que se quiere cifrar es {encrypt_message}")
    
    ascii_character_values = [] 
    for character in encrypt_message:   
        ascii_character_values.append(ord(character))   # At this point the program change the characters into ascii code
    
    # print(f"El código ascci a cifrar es: {ascii_character_values}") # Commments to comprobe the correct functioning of the program
    
    binary_character = [] 
    for x in ascii_character_values:
        binary_character.append(format(x, "08b"));  # At this point the program change the ascii code into binary numbers, 8 bits length
    
    # print(f"Los caracteres ascii convertidos a binario puro son de la manera: {binary_character}") # Commments to comprobe the correct functioning of the program
    
    binary_character_united = ""
    for x in binary_character:
        binary_character_united += str(x)   # At this point the list united to print the original message binary string
    print()
    print(f"El mensaje original convertido a binario es {binary_character_united} y su longitud es {len(binary_character_united)}")
    
    print()
    print("¿Cómo prefiere generar la clave de cifrado? [Manual(M)/Aleatoria(R)]: ")
    option = input()
    
    if (option == "M") | (option == "m"):
        Manual_key_production(binary_character, binary_character_united)
    elif (option == "R") | (option == "r"):
        Aleatory_key_production(encrypt_message, binary_character)
    else:
        print()
        print(f"Opción introducida no soportada, no se reconoce <<{option}>>")
        print()
        sys.exit(1) # Program exit with error

# Fuction neccesary to descipher the message entered by keyboard
def Vernam_decipher(encrypt_message_binary, binary_keys):
    encrypt_message_binary_list = []
    encrypt_message_binary_number = 0
    i = 0
    for x in encrypt_message_binary:   # At this point the program makes the xor operation to get original message
        encrypt_message_binary_number = bin(int(x,2) ^ int(binary_keys[i],2))
        encrypt_message_binary_list.append(encrypt_message_binary_number[2:])
        i += 1
    print()
    print(f"La lista de valores binarios del mensaje cifrado es {encrypt_message_binary_list}")
    
    # Binary to ascii convertion, then to characters
    encrypt_message_converted = 0   
    encrypt_message_converted_list = []
    for x in encrypt_message_binary_list:
        encrypt_message_converted = int(str(x), 2)
        encrypt_message_converted_list.append(encrypt_message_converted)
    # print(f"El mensaje en ascci de manera convertida es {encrypt_message_converted_list}") # Commments to comprobe the correct functioning of the program
    
    encrypt_message_characters = ""
    encrypt_message_characters_list = []
    for x in encrypt_message_converted_list:
        encrypt_message_characters = chr(x)
        encrypt_message_characters_list.append(encrypt_message_characters)
    # print(f"El mensaje encriptado finalmente es de manera listada {encrypt_message_characters_list}") # Commments to comprobe the correct functioning of the program
    
    # The list is united to print the original message
    encrypt_message_characters = ""
    for x in encrypt_message_characters_list:
        encrypt_message_characters += str(x)
    print()
    print(f"El mensaje final descifrado es {encrypt_message_characters}")
    Program_exit()

def Menu(encrypt_message_binary,key_character_binary_number):
    print()
    print("¿ Desea descifrar el mensaje ? [S/N]")
    option = input()
    if (option == "S") | (option == "s"):
        print()
        Vernam_decipher(encrypt_message_binary,key_character_binary_number)
    elif (option == "N") | (option == "n"):
        Program_exit() 
    else:
        print()
        print(f"Opción introducida no soportada, no se reconoce <<{option}>>")
        print()
        sys.exit(1) # Program exit with error

def Manual_key_production(binary_character, binary_character_united):
    print("Introduzca la clave de cifrado: ")
    option = input()
    
    if len(option) != len(binary_character_united):
        print()
        print("[Error] La clave introducida por teclado, no cumple los requisitos de longitud necesaria para poder realizar el cifrado de Vernam.")
        print("Salida del programa.")
        sys.exit(1) # Program exit with error
    
    manual_key = []
    string_aux = ""
    i = 0
    for x in option:
        if i != 7:
            string_aux = string_aux + x
        elif i == 7:
            string_aux = string_aux + x
            manual_key.append(string_aux)
            i = -1   # Initializating again the values
            string_aux = ""
        i += 1
        
    print(f"La lista de claves introducida de manera manual es: {manual_key}")
    
    encrypt_message_binary = []
    encrypt_message_number = 0
    i = 0
    for x in binary_character:
        encrypt_message_number = bin(int(x, 2) ^ int(manual_key[i], 2)) # At this point the program makes the xor operation
        encrypt_message_binary.append(encrypt_message_number[2:])
        i += 1
    # print(f"El mensaje cifrado en forma de lista es la manera: {encrypt_message_binary}") # Commments to comprobe the correct functioning of the program
    
    final_encrypt_message = "" 
    for x in encrypt_message_binary:
        final_encrypt_message += str(x) # At this point the list united to print the encrypt message in binary
    print()
    print(f"Finalmente el mensaje cifrado convertido a binario es {final_encrypt_message}")
    
    # List convertion to ascii code, then to characters to print the encrypt message
    encrypt_message_converted = 0   # Binary to decimal convertion
    encrypt_message_converted_list = []
    for x in encrypt_message_binary:
        encrypt_message_converted = int(str(x), 2)
        encrypt_message_converted_list.append(encrypt_message_converted)
    # print(f"El mensaje en ascci de manera convertida es {encrypt_message_converted_list}") # Commments to comprobe the correct functioning of the program
    
    # Decimal to binary convertion
    encrypt_message_characters = ""
    encrypt_message_characters_list = []
    for x in encrypt_message_converted_list:
        encrypt_message_characters = chr(x)
        encrypt_message_characters_list.append(encrypt_message_characters)
    # print(f"El mensaje encriptado finalmente es de manera listada {encrypt_message_characters_list}") # Commments to comprobe the correct functioning of the program
    
    # The list is united to print the encrypt message
    encrypt_message_characters = ""
    for x in encrypt_message_characters_list:
        encrypt_message_characters += str(x)
    print(f"El mensaje cifrado es {encrypt_message_characters}")
    
    Menu(encrypt_message_binary,manual_key)
    
def Aleatory_key_production(encrypt_message, binary_character):
    i = 0   # At this point the program generates the random keys to encrypt the message
    finish = len(encrypt_message)
    random_binary_number = ""
    random_character_binary_number = []
    while i < finish:
        random_binary_number_list = [str(x) for x in random.choices([0,1], k=len(binary_character[i]))] # Random keys generator
        for x in random_binary_number_list:
            random_binary_number += str(x)
        random_character_binary_number.append(random_binary_number)
        random_binary_number = ""
        i += 1
    print(f"La lista de claves aleatorias por caracter es {random_character_binary_number}")
    
    encrypt_message_binary = []
    encrypt_message_number = 0
    i = 0
    for x in binary_character:
        encrypt_message_number = bin(int(x, 2) ^ int(random_character_binary_number[i], 2)) # At this point the program makes the xor operation
        encrypt_message_binary.append(encrypt_message_number[2:])
        i += 1
    # print(f"El mensaje cifrado en forma de lista es la manera: {encrypt_message_binary}") # Commments to comprobe the correct functioning of the program
    
    final_encrypt_message = "" 
    for x in encrypt_message_binary:
        final_encrypt_message += str(x) # At this point the list united to print the encrypt message in binary
    print()
    print(f"Finalmente el mensaje cifrado convertido a binario es {final_encrypt_message}")
    
    # List convertion to ascii code, then to characters to print the encrypt message
    encrypt_message_converted = 0   # Binary to decimal convertion
    encrypt_message_converted_list = []
    for x in encrypt_message_binary:
        encrypt_message_converted = int(str(x), 2)
        encrypt_message_converted_list.append(encrypt_message_converted)
    # print(f"El mensaje en ascci de manera convertida es {encrypt_message_converted_list}") # Commments to comprobe the correct functioning of the program
    
    # Decimal to binary convertion
    encrypt_message_characters = ""
    encrypt_message_characters_list = []
    for x in encrypt_message_converted_list:
        encrypt_message_characters = chr(x)
        encrypt_message_characters_list.append(encrypt_message_characters)
    # print(f"El mensaje encriptado finalmente es de manera listada {encrypt_message_characters_list}") # Commments to comprobe the correct functioning of the program
    
    # The list is united to print the encrypt message
    encrypt_message_characters = ""
    for x in encrypt_message_characters_list:
        encrypt_message_characters += str(x)
    print(f"El mensaje cifrado es {encrypt_message_characters}")
    
    Menu(encrypt_message_binary,random_character_binary_number)

def Program_exit():
    print()
    print("Salida del programa de manera correcta")
    print("Finalización del programa")
    print()
    sys.exit(0) # Program exit without error

# Main program Fuction
if __name__ == '__main__':
    print("Introduzca el mensaje que quiere cifrar: ")
    encrypt_message = input()  
    Vernam_encryption(encrypt_message)
