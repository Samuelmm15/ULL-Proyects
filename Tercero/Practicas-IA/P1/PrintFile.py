import os
from prettytable import PrettyTable

def PrintFile(finalRoute, initialNode, finalNode, distanceResult, partialRoute, visited):
    myTable = PrettyTable(["V0", "V1", "Camino", "Distancia", "Nodos generados", "Nodos inspeccionados"])
    
    # This includes all the content in a vector to print at the table
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
    myTable.add_row([initialNode, finalNode, vectorToPrint, distanceResult, len(partialRoute), len(visited)])
    print()
    print(myTable)
    
    # This prints into an output file, but it not works with the prettyTable
    # file = open("outputFile.txt", "w")
    # file.write(myTable)