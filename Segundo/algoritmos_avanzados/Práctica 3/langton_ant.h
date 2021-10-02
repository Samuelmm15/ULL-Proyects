/**
 * @file langton_ant.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the file that contains the ant
 * Lagton ant diterministic discrete system. To understant the functioning go to the site: https://es.wikipedia.org/wiki/Hormiga_de_Langton
 * This Langton Ant is different than the original, because, this is a special game, when the ant arrive to the limit of the mesh, the mesh is resized.
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
 * @brief The class to generate the Ant of the game and her movements
 * 
 */
class Ant { 
    private:
    /**
     * @brief The fuction that calculates the turn of the ant
     * 
     */
    void Ant_Turn();
    /**
     * @brief The fuction that calculates the movement of the ant
     * 
     */
    void Ant_Move();
    public:
    string ant[3]; /// The Ant
    int num_of_ants = 0;
    int aux_num = 0;
    string i_coordinate;  /// The i position of the Ant
    string j_coordinate; /// The j position of the Ant
    string posititon; /// The direction of the Ant
    string posititon_aux;
    int i_coordinate_value = 0;
    int j_coordinate_value = 0;
    int the_mesh_copy[500][500];
    vector<string> Ant_List;
    /**
     * @brief The fuction that generates the Ant 
     * 
     */
    void Ant_Generator(); 
    /**
     * @brief The fuction that changes the values of the Ant
     * 
     */
    void Ant_movement(); 
    /**
     * @brief The fuction that represents the Ant
     * 
     */
    void Ant_Status_Representation();
    /**
     * @brief Get the Turn object
     * 
     */
    void getTurn(); 
    /**
     * @brief Get the Move object
     * 
     */
    void getMove();
};