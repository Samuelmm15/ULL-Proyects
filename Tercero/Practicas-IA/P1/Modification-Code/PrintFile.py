"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief This file cotains the function that prints the final table to see the results.
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

import os
from colorama import Fore
from colorama import init
from prettytable import PrettyTable

"""This function prints the final table that contains the results of the search.
    """
def PrintFile(finalRoute, initialNode, finalNode, distanceResult, partialRoute, visited, verticesNumber, edgesNumber):
    myTable = PrettyTable(["n", "m", "V0", "V1", "Camino", "Distancia", "Nodos generados", "Nodos inspeccionados"])
    
    # This structure makes the final route representation.
    i = 0
    vectorToPrint = []
    while i < len(finalRoute):
        if (i < len(finalRoute) - 1):
            vectorToPrint.append(finalRoute[i][0])
            vectorToPrint.append("-->")
        else:
            vectorToPrint.append(finalRoute[i][0])
            vectorToPrint.append("-->")
            vectorToPrint.append(finalRoute[i][1])
        i += 1
    
    # Add rows to the table
    myTable.add_row([verticesNumber, edgesNumber, initialNode, finalNode, vectorToPrint, distanceResult, len(partialRoute), len(visited)])
    print()
    print(Fore.MAGENTA + 'Generación de la tabla resultante:')
    print(myTable)