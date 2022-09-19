/**
 * @file langton_finiteworld.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Lagton ant diterministic discrete system. To understant the functioning go to the site: https://es.wikipedia.org/wiki/Hormiga_de_Langton
 * @version 0.1
 * @date 2021-03-14
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

#pragma once
using namespace std;

/**
 * @brief The class that inherited the class World
 * 
 */
class Finite_World : public World { 
    public:
    /**
     * @brief The fuction that generates the finite world
     * 
     */
    void World_Generator_Finiteworld();
    /**
     * @brief The fuction that prints the world
     * 
     */
    void World_Status_Finiteworld();
    /**
     * @brief The fuction that calculates the limit of the mesh of the world
     * 
     */
    void Limit_Condition_Finiteworld();
};