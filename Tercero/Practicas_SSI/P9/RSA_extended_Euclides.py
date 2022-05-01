""""
 @file RSA_extended_Euclides.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief Implementation of Extended Euclides Algorithm
 @version 0.1
 @date 2022-05-01
  
 @copyright Copyright (c) 2022
"""

def Extended_Euclides_Algorithm(a, b):
    # This is the extended euclides algorithm
    if b == 0:
        return 0
 
    auxiliary = 1
    auxiliary1 = 0
    auxiliary2 = 1
    result = 0
 
    while b != 0:
        q = a//b   # Permite obtener el número natural, es decir, cuantas veces multiplicado es el número b para que resulte a
        r = a - b * q
        u = auxiliary - q * auxiliary1
        v = result - q * auxiliary2
        # Update a,b
        a = b
        b = r
        # Update for the next iteration
        auxiliary = auxiliary1
        auxiliary1 = u
        result = auxiliary2
        auxiliary2 = v
 
    return result