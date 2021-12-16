/**
 * @file File.h
 * @author Samuel Martín Morales (alu0101359526@ull.ed.es)
 * @brief The file that contents the class of the File
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> /// standar library of the program
#include <stdio.h>
#include <string.h> /// library to operate with strings
#include <array>
#include <fstream>  /// library to operate with files
#include <unistd.h> /// library to use the close fuction
#include <sys/types.h> /// library needed to create sockets
#include <sys/socket.h> /// library needed to create sockets
#include <netinet/in.h> /// library needed to create sockets
#include <arpa/inet.h>
#include <sys/types.h>  /// librarys neccesaries to open files
#include <sys/stat.h>
#include <fcntl.h>
#include <cerrno>   /// library neccesarie to errno
#include <cstring>  /// library neccesarue to std::sterror()

/**
 * @brief Class that open files to get the message
 * 
 */
class File {
    public:
        /**
         * @brief Construct a new File object
         * 
         * @param file_name 
         */
        File(const std::string file_name);
        /**
         * @brief Destroy the File object
         * 
         */
        ~File();
        int file_fd;
};