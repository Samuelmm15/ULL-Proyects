""""
 @file Vernam_encryption.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief 
 @version 0.1
 @date 2022-02-15
  
 @copyright Copyright (c) 2022
"""

# Implementa el cifrado y el descifrado de Vernam.
# EL cifrado debe de operar bit a bit mediante la operación XOR entre el mensaje origianl y la clave aleatoria
# El descifrado debe de operar también bit a bit mediante la operación XOR entre el mensaje cifrado y la clave aleatoria (Suponemos que la clave es pasada para que sea descifrada)
# Hacer uso del código ASCII para poder pasar las letras a bytes y viceversa

# NOTA: HAY QUE TENER EN CUENTA QUE EN PYTHON EL CÓDIGO SE EJECUTA DE MANERA LINEAL

# Librerías necesarias
import random

# Declaración y uso de funciones

def Vernam_encryption(encrypt_message):    # Función que se encarga de cifrar el mensaje original solicitado en la función principal
    print(f"El mensaje que se quiere encriptar es {encrypt_message}")
    
    ascii_character_values = [] # Declaración de la variables como un vector
    for character in encrypt_message:   # De esta manera se obtiene cada caracter de la cadena de texto
        ascii_character_values.append(ord(character))   # De esta manera se convierte cada caracter en un código ascii
    
    print(f"El código ascci a cifrar es: {ascii_character_values}") # En este punto se tiene un vector de valores ascci correspondiente con la cadena original
    
    binary_character = [] # Declaración de una lista vacía
    for x in ascii_character_values:
        binary_character.append(format(x, "b"));  # La opción "b" especifica que se quiere convertir la cadena a binario puro
    
    print(f"Los caracteres ascii convertidos a binario puro son de la manera: {binary_character}") # En este punto tenemos todos los caracteres ascci convertidos a binario puro
    
    binary_character_united = ""
    for x in binary_character:
        binary_character_united += str(x)
    print(f"El mensaje original convertido a binario es {binary_character_united} y su longitud es {len(binary_character_united)}")
    
    i = 0   # Obtención de las distintas claves
    finish = len(encrypt_message)
    random_binary_number = ""
    random_character_binary_number = []
    while i < finish:
        random_binary_number_list = [str(x) for x in random.choices([0,1], k=len(binary_character[i]))] # De esta manera sacamos la clave de cada item de la lista
        for x in random_binary_number_list:
            random_binary_number += str(x)
        random_character_binary_number.append(random_binary_number)
        random_binary_number = ""
        i += 1
    print(f"La lista de claves aleatorias por caracter es {random_character_binary_number}")
    
    encrypt_message_binary = [] # Realización de la operación xor con las claves
    encrypt_message_number = 0
    i = 0
    for x in binary_character:
        encrypt_message_number = bin(int(x, 2) ^ int(random_character_binary_number[i], 2)) # En este punto se realiza la operación de xor
        encrypt_message_binary.append(encrypt_message_number[2:])
        i += 1
    print(f"El mensaje cifrado en forma de lista es la manera: {encrypt_message_binary}")
    
    final_encrypt_message = ""  # Unión de la lista para formar un único mensaje cifrado
    for x in encrypt_message_binary:
        final_encrypt_message += str(x)
    print(f"Finalmente el mensaje cifrado convertido a binario es {final_encrypt_message}")
    
    # Conversión de la lista en binario a ascii y después a caracteres
    encrypt_message_converted = 0   # Conversión de binario a decimal
    encrypt_message_converted_list = []
    for x in encrypt_message_binary:
        encrypt_message_converted = int(str(x), 2)
        encrypt_message_converted_list.append(encrypt_message_converted)
    print(f"El mensaje en ascci de manera convertida es {encrypt_message_converted_list}")
    
    # Conversión de decimal mediante ascci a letras
    encrypt_message_characters = ""
    encrypt_message_characters_list = []
    for x in encrypt_message_converted_list:
        encrypt_message_characters = chr(x)
        encrypt_message_characters_list.append(encrypt_message_characters)
    print(f"El mensaje encriptado finalmente es de manera listada {encrypt_message_characters_list}")
    
    # Unión del mensaje cifrado como resultado final
    encrypt_message_characters = ""
    for x in encrypt_message_characters_list:
        encrypt_message_characters += str(x)
    print(f"El mensaje final cifrado es {encrypt_message_characters}")
    
    print("Desea desencriptar el mensaje [S/N]")
    option = input()
    if option == "S":
        Vernam_decipher(encrypt_message_binary,random_character_binary_number)
    
def Vernam_decipher(encrypt_message_binary, random_binary_keys):
    encrypt_message_binary_list = []
    encrypt_message_binary_number = 0
    i = 0
    for x in encrypt_message_binary:   # Realizar la operación de xor para poder descifrar el mensaje original
        encrypt_message_binary_number = bin(int(x,2) ^ int(random_binary_keys[i],2))
        encrypt_message_binary_list.append(encrypt_message_binary_number[2:])
        i += 1
    print(f"La lista de valores binarios del mensaje cifrado con las claves aleatorias es {encrypt_message_binary_list}")
    
    # COnversión de binario a ascii y finalmente a caracteres
    encrypt_message_converted = 0   # Conversión de binario a decimal
    encrypt_message_converted_list = []
    for x in encrypt_message_binary_list:
        encrypt_message_converted = int(str(x), 2)
        encrypt_message_converted_list.append(encrypt_message_converted)
    print(f"El mensaje en ascci de manera convertida es {encrypt_message_converted_list}")
    
    encrypt_message_characters = ""
    encrypt_message_characters_list = []
    for x in encrypt_message_converted_list:
        encrypt_message_characters = chr(x)
        encrypt_message_characters_list.append(encrypt_message_characters)
    print(f"El mensaje encriptado finalmente es de manera listada {encrypt_message_characters_list}")
    
    # Unión del mensaje cifrado como resultado final
    encrypt_message_characters = ""
    for x in encrypt_message_characters_list:
        encrypt_message_characters += str(x)
    print(f"El mensaje final cifrado es {encrypt_message_characters}")

# Función principal del programa
if __name__ == '__main__':
    print("Introduzca el mensaje que quiere cifrar: ")
    encrypt_message = input()   # En este punto tenemos el mensaje que se quiera cifrar
    Vernam_encryption(encrypt_message)

    
    
# La función ord() sirve para obtener el código ascii de cualquier caracter de entrada
# La función chr() sirve para convertir un valor numerico en un caracter ascii
# La función format() sirve para convertir cualquier entero de entrada en binario puro
# La función len() sirve para obtener el tamaño de una cadena
# La función choice() devuelve un elemento aleatorio de una secuencia dada.

# PÁGINAS IMPORTANTES DE LA PRÁCTICA
# https://stackoverflow.com/questions/4387138/pythonascii-character-decimal-representation-conversion
# https://www.lawebdelprogramador.com/foros/Python/1773321-Como-generar-un-numero-binario-aleatorio.html
# https://www.delftstack.com/es/howto/python/convert-string-to-ascii-python/
# https://www.delftstack.com/es/howto/python/python-int-to-binary/
# https://www.educative.io/edpresso/how-to-convert-string-to-binary-in-python
# https://ellibrodepython.com/operadores-bitwise
# https://es.acervolima.com/programa-de-python-para-sumar-dos-numeros-binarios/
