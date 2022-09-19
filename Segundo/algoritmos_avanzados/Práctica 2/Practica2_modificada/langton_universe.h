/**
 * @file langton_world.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the file that contains the world of the ant
 * Lagton ant diterministic discrete system. To understant the functioning go to the site: https://es.wikipedia.org/wiki/Hormiga_de_Langton
 * This Langton Ant is different than the original, because, this is a special game, when the ant arrive to the limit of the mesh, the mesh is resized.
 * @version 0.1
 * @date 2021-03-06
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
 * @brief Class to content all the main fuction of the program
 * 
 */
class Universe {
    public:
    /**
     * @brief Fuction that contents the main behavious of the program
     * 
     */
    void ant_universe();
};