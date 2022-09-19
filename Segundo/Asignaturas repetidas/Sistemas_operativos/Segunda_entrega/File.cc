/**
 * @file File.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief File that contents the declaration of the file constructor
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "File.h"

File::File(const std::string file_name) {
    if ((file_fd = open("prueba.txt", O_RDONLY)) < 0) {
        std::cerr << "Falló la apertura del fichero." << strerror(errno) << '\n';
    }
};

File::~File() {
    close(file_fd);
};