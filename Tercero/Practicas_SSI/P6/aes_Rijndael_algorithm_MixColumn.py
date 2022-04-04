""""
 @file aes_Rijndael_algorithm_MixColumn.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Rijndael algorithm
 @version 0.1
 @date 2022-03-30
  
 @copyright Copyright (c) 2022
"""

# Multiply all the column to a standar matrix

def MixColumn(cipher_text_block):
    mixColumn_matrix = [['2','3','1','1'],     
                        ['1','2','3','1'],
                        ['1','1','2','3'],
                        ['3','1','1','2']]
    
    first_column = []
    second_column = []
    thirth_column = []
    fourth_column = []
        
    # Obtain the first column
    i = 0
    j = 0
    while i < len(cipher_text_block):
        first_column.append(cipher_text_block[i][j])
        i += 1
    
    c = 0
    a = []
    b = []
    while c < 4:
        a.append(hex(int(first_column[c],16)))
        h = hex(int(first_column[c],16) & 0x80)
        b.append(hex((int(first_column[c],16) << 1) % 256))
        if (h == 0x80):
            b[c] = hex(int(int(b[c],16) ^ 0x1b,16))
        c += 1
    first_column[0] = hex(int(b[0],16) ^ int(a[3],16) ^ int(a[2],16) ^ int(b[1],16) ^ int(a[1],16) & 0xFF)[2:].zfill(2)
    first_column[1] = hex(int(b[1],16) ^ int(a[0],16) ^ int(a[3],16) ^ int(b[2],16) ^ int(a[2],16) & 0xFF)[2:].zfill(2)
    first_column[2] = hex(int(b[2],16) ^ int(a[1],16) ^ int(a[0],16) ^ int(b[3],16) ^ int(a[3],16) & 0xFF)[2:].zfill(2)
    first_column[3] = hex(int(b[3],16) ^ int(a[2],16) ^ int(a[1],16) ^ int(b[0],16) ^ int(a[0],16) & 0xFF)[2:].zfill(2)
    
    # Obtain the second column
    i = 0
    j = 1
    while i < len(cipher_text_block):
        second_column.append(cipher_text_block[i][j])
        i += 1

    c = 0
    a = []
    b = []
    while c < 4:
        a.append(hex(int(second_column[c],16)))
        h = hex(int(second_column[c],16) & 0x80)
        b.append(hex((int(second_column[c],16) << 1) % 256))
        if (h == 0x80):
            b[c] = hex(int(int(b[c],16) ^ 0x1b,16))
        c += 1
    second_column[0] = hex(int(b[0],16) ^ int(a[3],16) ^ int(a[2],16) ^ int(b[1],16) ^ int(a[1],16) & 0xFF)[2:].zfill(2)
    second_column[1] = hex(int(b[1],16) ^ int(a[0],16) ^ int(a[3],16) ^ int(b[2],16) ^ int(a[2],16) & 0xFF)[2:].zfill(2)
    second_column[2] = hex(int(b[2],16) ^ int(a[1],16) ^ int(a[0],16) ^ int(b[3],16) ^ int(a[3],16) & 0xFF)[2:].zfill(2)
    second_column[3] = hex(int(b[3],16) ^ int(a[2],16) ^ int(a[1],16) ^ int(b[0],16) ^ int(a[0],16) & 0xFF)[2:].zfill(2)
    
    # Obtain the thirth column
    i = 0
    j = 2
    while i < len(cipher_text_block):
        thirth_column.append(cipher_text_block[i][j])
        i += 1
    
    c = 0
    a = []
    b = []
    while c < 4:
        a.append(hex(int(thirth_column[c],16)))
        h = hex(int(thirth_column[c],16) & 0x80)
        b.append(hex((int(thirth_column[c],16) << 1) % 256))
        if (h == 0x80):
            b[c] = hex(int(int(b[c],16) ^ 0x1b,16))
        c += 1
    thirth_column[0] = hex(int(b[0],16) ^ int(a[3],16) ^ int(a[2],16) ^ int(b[1],16) ^ int(a[1],16) & 0xFF)[2:].zfill(2)
    thirth_column[1] = hex(int(b[1],16) ^ int(a[0],16) ^ int(a[3],16) ^ int(b[2],16) ^ int(a[2],16) & 0xFF)[2:].zfill(2)
    thirth_column[2] = hex(int(b[2],16) ^ int(a[1],16) ^ int(a[0],16) ^ int(b[3],16) ^ int(a[3],16) & 0xFF)[2:].zfill(2)
    thirth_column[3] = hex(int(b[3],16) ^ int(a[2],16) ^ int(a[1],16) ^ int(b[0],16) ^ int(a[0],16) & 0xFF)[2:].zfill(2)
    
    # Obtain the fourth column
    i = 0
    j = 3
    while i < len(cipher_text_block):
        fourth_column.append(cipher_text_block[i][j])
        i += 1
    
    c = 0
    a = []
    b = []
    while c < 4:
        a.append(hex(int(fourth_column[c],16)))
        h = hex(int(fourth_column[c],16) & 0x80)
        b.append(hex((int(fourth_column[c],16) << 1) % 256))
        if (h == 0x80):
            b[c] = hex(int(int(b[c],16) ^ 0x1b,16))
        c += 1
    fourth_column[0] = hex(int(b[0],16) ^ int(a[3],16) ^ int(a[2],16) ^ int(b[1],16) ^ int(a[1],16) & 0xFF)[2:].zfill(2)
    fourth_column[1] = hex(int(b[1],16) ^ int(a[0],16) ^ int(a[3],16) ^ int(b[2],16) ^ int(a[2],16) & 0xFF)[2:].zfill(2)
    fourth_column[2] = hex(int(b[2],16) ^ int(a[1],16) ^ int(a[0],16) ^ int(b[3],16) ^ int(a[3],16) & 0xFF)[2:].zfill(2)
    fourth_column[3] = hex(int(b[3],16) ^ int(a[2],16) ^ int(a[1],16) ^ int(b[0],16) ^ int(a[0],16) & 0xFF)[2:].zfill(2)
   
    cipher_text_block_result = []
   
    cipher_text_block_result.append(first_column)
    cipher_text_block_result.append(second_column)
    cipher_text_block_result.append(thirth_column)
    cipher_text_block_result.append(fourth_column)
   
    print()
    print('Finalmente, tras la operación de MixColumns: ')
    
    print()
    i = 0
    j = 0
    while i < len(cipher_text_block_result):
        while j < len(cipher_text_block_result[i]):
            print(cipher_text_block_result[i][j], end=' ')
            j += 1
        print()
        j = 0
        i += 1
        
    return cipher_text_block_result