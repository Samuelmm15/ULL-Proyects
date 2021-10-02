/**
 * @file langton_ant.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Lagton ant diterministic discrete system. To understant the functioning go to the site: https://es.wikipedia.org/wiki/Hormiga_de_Langton
 * This Langton Ant is different than the original, because, this is a special game, that has a limit of 500 cells and when the Ant find the limit of the mesh, the game finish.
 * @version 0.1
 * @date 2021-02-22
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
 * @brief This class helps to make the world object
 * 
 */
class World {
    private:
    /**
     * @brief This fuction helps to determinate the limits of the mesh
     * 
     */
    void Limit_Condition(); 
    public:
    int mesh_size; /// The size of the World of the Ant
    string the_mesh[500][500]; /// The world
    int i_ant_coordinate;
    int j_ant_coordinate;
    string ant_position;
    int limit = 0;
    /**
     * @brief The fuction that genrates the mesh or the world of the Ant
     * 
     */
    void World_Generator();
    /**
     * @brief The fuction that print the diferent steps that the Ant do
     * 
     */
    void World_Status();
    /**
     * @brief The fuction that help the Ant to interact with the World
     * 
     */
    void Cell_Change(); 
};

/**
 * @brief This class helps to make the Ant object
 * 
 */
class Ant { /// The class to generate the Ant of the game and her movements
    public:
    string ant[3]; /// The Ant
    string i_coordinate;  /// The i position of the Ant
    string j_coordinate; /// The j position of the Ant
    string posititon; /// The direction of the Ant
    int i_coordinate_value;
    int j_coordinate_value;
    /**
     * @brief The fuction that creates the Ant
     * 
     */
    void Ant_Generator(); 
    /**
     * @brief The fuction that makes the Ant updated
     * 
     */
    void Ant_Status(); 
    /**
     * @brief The fuction that prints the state of the Ant
     * 
     */
    void Ant_Status_Representation();
};