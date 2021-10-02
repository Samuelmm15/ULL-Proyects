/**
 * @file langton_vector.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the file that contains the vector of the mesh
 * Lagton ant diterministic discrete system. To understant the functioning go to the site: https://es.wikipedia.org/wiki/Hormiga_de_Langton
 * This Langton Ant is different than the original, because, this is a special game, when the ant arrive to the limit of the mesh, the mesh is resized.
 * @version 0.1
 * @date 2021-03-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/// This coments help me to understand the functions of the differents librarys
#include <iostream> /// the main library of the program
#include <fstream> /// the library to read and write text files
#include <stdlib.h> /// the library to use exit(1);
#include <string.h> /// the library to operate with strings
#include <vector> /// the library to do a vector with strings
#include <algorithm> /// the library to use the iterator
#include <cctype> /// the library to use toupper or tolower
#include <sstream> /// library to use the convertors of strings and numbers (istringstream or ostringstream)
#include <list> /// library to use the class list

using namespace std;

/**
 * @brief The fuction that make the resize of the matrix
 * 
 * @tparam T The parametrer that establish the tipe of the values of the matrix
 */
template <class T>
class Vector_World { 
    public:
    int i_ini_min, i_ini_max = 0; /// The i value of the matrix
    int j_ini_min , j_ini_max = 0; /// The j value of the matrix
    int aux, aux1 = 0;
    int mesh_copy_to_resize[500][500];
    /**
     * @brief The fuction that makes the values of the matrix resize
     * 
     */
    void Mesh_Resize() {
        if ((aux == 1) || ((aux == 1) && (aux1 == 1))) { 
            i_ini_min--;
            aux = 0;
            if (aux1 == 1) {
                j_ini_min--;
                aux1 = 0;
            }
        } else if ((aux == 2) || (aux1 == 2)) {
            j_ini_min--;
            aux = 0;
            if (aux1 == 2) {
                i_ini_max++;
                aux1 = 0;
            }
        } else if ((aux == 3) || (aux1 == 3)) {
            i_ini_max++;
            aux = 0;
            if (aux1 == 3) {
                j_ini_max++;
                aux1 = 0;
            }
        } else if ((aux == 4) || (aux1 == 4)) {
            j_ini_max++;
            aux = 0;
            if (aux1 == 4) {
                i_ini_min = i_ini_min--;
                aux1 = 0;
            }
        }
    }
};