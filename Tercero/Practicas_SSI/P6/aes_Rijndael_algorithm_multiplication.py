def AES_multplication(first_byte, second_byte):
    
    # Initialization
    algorithm_byte = '00011011'
    result = ''
    result_aux = ''
    for i in first_byte:
        result = bin(int(i, 16))[2:].zfill(4)
        result_aux = result_aux + result
    first_byte = result_aux
    
    result = ''
    result_aux = ''
    for i in second_byte:
        result = bin(int(i, 16))[2:].zfill(4)
        result_aux = result_aux + result
    second_byte = result_aux
    
    # Multiplication algorithm
    k = 1
    l = 0
    result = []
    auxiliary_result = 0
    # First iteration
    table = first_byte
    if second_byte[7] == '1':
        result.append(table)
    # Scrolling
    if table[0] == '1': # Table iteration
        table = bin((int(table, 2) << 1))[2:].zfill(8)
        auxiliary = ''
        j = 1
        while j < len(table): # To obtain the first operator
            auxiliary = auxiliary + table[j]
            j += 1
        table = auxiliary
        auxiliary_result = bin(int(table, 2) ^ int(algorithm_byte, 2))[2:].zfill(8)
        table = auxiliary_result
    else:
        table = bin(int(table, 2) << 1)[2:].zfill(8)
    if second_byte[6] == '1':
        result.append(table)
    l = 5
    while k < 7:
        if table[0] == '1': # Table iteration
            table = bin((int(table, 2) << 1))[2:].zfill(8)
            auxiliary = ''
            j = 1
            while j < len(table): # To obtain the first operator
                auxiliary = auxiliary + table[j]
                j += 1
            table = auxiliary
            auxiliary_result = bin(int(table, 2) ^ int(algorithm_byte, 2))[2:].zfill(8)
            table = auxiliary_result
        else:
            table = bin(int(table, 2) << 1)[2:].zfill(8)
        if second_byte[l] == '1':
            result.append(table)
        l -= 1
        k += 1
        
    m = 1
    final_result = result[0]
    while m < len(result):
        final_result = bin(int(final_result, 2) ^ int(result[m], 2))[2:].zfill(8)
        m += 1
   
    return final_result