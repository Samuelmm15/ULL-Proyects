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

# Declaración y uso de funciones

def Vernam_encryption(encrypt_message):    # Función que se encarga de cifrar el mensaje original solicitado en la función principal
    print(f"El mensaje que se quiere encriptar es {encrypt_message}")

# Función principal del programa
if __name__ == '__main__':
    print("Introduzca el mensaje que quiere cifrar: ")
    encrypt_message = input()   # En este punto tenemos el mensaje que se quiera cifrar
    Vernam_encryption(encrypt_message)