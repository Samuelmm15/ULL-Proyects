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

#pragma once
using namespace std;

/**
 * @brief The class that contents the world of the Ant
 * 
 */
class World {
    public:
    int mesh_size = 0; /// The size of the World of the Ant
    int i_ini_min_world, i_ini_max_world = 0;
    int j_ini_min_world, j_ini_max_world = 0; 
    int the_mesh[500][500]; /// The world
    int i_ant_coordinate = 0;
    int j_ant_coordinate = 0;
    string ant_position;
    int limit = 0;
    int resize = 0, resize1 = 0;
    /**
     * @brief The fuction that generates the world of the Ant
     * 
     */
    void World_Generator();
    /**
     * @brief The fuction that prints the status of the world and the Ant
     * 
     */
    void World_Status();
    /**
     * @brief The fuction that sets up the limit of the mesh of the world
     * 
     */
    void Limit_Condition();
};

