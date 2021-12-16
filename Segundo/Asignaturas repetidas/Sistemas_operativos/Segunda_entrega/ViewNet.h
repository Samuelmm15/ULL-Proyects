/**
 * @file ViewNet.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
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

#pragma once 

/**
 * @brief Struct that generates messages 
 * 
 */
struct Message {
    std::array<char,1024> text;
};
/**
 * @brief Class use to generate sockets
 * 
 */
class Socket { 
    public:
        /**
         * @brief Construct a new Socket object
         * 
         * @param address 
         */
        Socket(const sockaddr_in& address);
        /**
         * @brief Destroy the Socket object
         * 
         */
        ~Socket();
        /**
         * @brief Fuction that send messages into the socket
         * 
         * @param message 
         * @param address 
         */
        void send_to(const Message& message, const sockaddr_in& address); 
        /**
         * @brief Fuction that recieve messages from a remote socket
         * 
         * @param message 
         * @param address 
         */
        void receive_from(Message& message, sockaddr_in& address);
    private:
        int fd_;
};

/**
 * @brief Fuction that generates differents ip address
 * 
 * @param port 
 * @param ip_address 
 * @return sockaddr_in 
 */
sockaddr_in make_ip_address(int port, const std::string& ip_address);

/**
 * @brief Fuction that generates messages
 * 
 * @param in_message 
 * @return Message 
 */
Message make_message(std::string in_message);
