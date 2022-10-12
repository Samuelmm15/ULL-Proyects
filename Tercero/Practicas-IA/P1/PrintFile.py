import os

def PrintFile(finalRoute):
    file = open("outputFile.txt", "w")
    file.write('V0 ')
    file.write('V1 ')
    file.write('Camino                                         ')
    file.write('Distancia ')
    file.write('Nodos generados ')
    file.write('Nodos inspeccionados' + os.linesep)
    i = 0
    while i < len(finalRoute):
        if (i < len(finalRoute) - 1):
            file.write(f'{finalRoute[i][0]} --> ')
        else:
            file.write(f'{finalRoute[i][0]} --> ')
            file.write(f'{finalRoute[i][1]}' + os.linesep)
        i += 1