""""
 @file aes_Rijndael_algorithm_ShiftRow.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

# Primera fila rota 0 bytes
# Segunda fila rota 1 byte
# Tercera fila rota 2 bytes
# Cuarta fila rota 3 bytes

def ShiftRow(cipher_text_block):
    # The algorithm starts here
    i = 0
    j = 0
    counter = 0
    auxiliary_string = []
    while i < len(cipher_text_block):
        if i > 0:
            while j < len(cipher_text_block[i]):
                if (i == 1) and (counter < 1): # First Rotate
                    auxiliary = cipher_text_block[i][0]
                    cipher_text_block[i].remove(auxiliary)
                    cipher_text_block[i].append(auxiliary)
                elif (i == 2) and (counter < 2): # Second Rotate
                    auxiliary = cipher_text_block[i][0]
                    cipher_text_block[i].remove(auxiliary)
                    cipher_text_block[i].append(auxiliary)
                elif (i == 3) and (counter < 3): # Thirth Rotate
                    auxiliary = cipher_text_block[i][0]
                    cipher_text_block[i].remove(auxiliary)
                    cipher_text_block[i].append(auxiliary)
                counter += 1
                j += 1
        counter = 0
        j = 0
        i += 1
    
    # # Print
    # print()
    # print('El resultado tras el desplazamiento de las filas es: ')
    # i = 0
    # j = 0
    # while i < len(cipher_text_block):
    #     while j < len(cipher_text_block[i]):
    #         print(cipher_text_block[i][j], end=' ')
    #         j += 1
    #     print()
    #     j = 0
    #     i += 1
        
    return cipher_text_block
