from ctypes import *

def Menu():
    print("<< Bienvenido al programa de cifrado Chacha20 >>")
    print()
    
    hexadecimal_key = input("Introduzca la clave de cifrado: ")
    hexadecimal_counter = input("Introduzca el contador: ")
    hexadecimal_nonce = Aleatory_Nonce()
    
    Chacha20_Encryption(hexadecimal_key, hexadecimal_counter, hexadecimal_nonce)
    
def Aleatory_Nonce():
    nonce_result = '00:00:00:09:00:00:00:4a:00:00:00:00'
    return nonce_result

def Chacha20_Encryption(hexadecimal_key, hexadecimal_counter, hexadecimal_nonce):
    print()

if __name__ == '__main__':
    Menu()