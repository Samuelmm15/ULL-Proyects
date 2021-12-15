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
        std::ifstream file_open;
};

/**
 * @brief Fuction that generates differents ip address
 * 
 * @param port 
 * @param ip_address 
 * @return sockaddr_in 
 */
sockaddr_in make_ip_address(int port, const std::string& ip_address = std::string()) {  
    sockaddr_in local_inicialization{}; /// Empty initialization of the struct
    if (ip_address.size() == 0) {    /// If the string is empty
        local_inicialization.sin_addr.s_addr = INADDR_ANY;
    } else {
        char ip_address_auxiliary[100]; /// String to char convertion
        strcpy(ip_address_auxiliary, ip_address.c_str());
        inet_aton(ip_address_auxiliary, &local_inicialization.sin_addr);
    }
    local_inicialization.sin_family = AF_INET;
    local_inicialization.sin_port = htons(port);
    return local_inicialization;
};

/**
 * @brief Fuction that generates messages
 * 
 * @param in_message 
 * @return Message 
 */
Message make_message(std::string in_message) {    
    Message message_initialization{}; 
    in_message.copy(message_initialization.text.data(), message_initialization.text.size() - 1, 0);
    return message_initialization;
};

Socket::Socket(const sockaddr_in& address) {
    Socket::fd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (Socket::fd_ < 0) {
        std::cerr << "No se pudo crear el socket: " << strerror(errno) << '\n';
    } 

    int result = bind(Socket::fd_, reinterpret_cast<const sockaddr*>(&address), sizeof(address));

    if (result < 0) {
        std::cerr << "Falló bind: " << result << std::strerror(errno) << '\n';
    }
};

Socket::~Socket() {
    close(Socket::fd_);
};

void Socket::send_to(const Message& message, const sockaddr_in& address) {
    int result = sendto(Socket::fd_, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&address), sizeof(address));
    if (result < 0) {
        std::cerr << "Falló sendto: " << strerror(errno) << '\n';
    }
};

void Socket::receive_from(Message& message, sockaddr_in& address) {
    socklen_t src_len = sizeof(address);
    int result = recvfrom(Socket::fd_, &message, sizeof(message), 0, reinterpret_cast<sockaddr*>(&address), &src_len);
    if (result < 0) {
        std::cerr << "Falló rcvfrom: " << strerror(errno) << '\n';
    }

    /// Mostrar el mensaje recibido en la terminal
    char* remote_ip = inet_ntoa(address.sin_addr);
    int remote_port = ntohs(address.sin_port);
    message.text[1023] = '\0';  /// Necessary to mark the final of a string
    std::cout << "El sistema " << remote_ip << ":" << remote_port << " envió el mensaje '" << message.text.data() << "'\n";
};

File::File(const std::string file_name) {
    File::file_open.open(file_name); /// Open the file
    if (File::file_open.is_open()) {
        std::cout << "El fichero " << file_name << " ha sido abierto de manera correcta." << '\n';
    } else {
        std::cout << "Error en la apertura del fichero " << file_name << '\n';
    }
};

File::~File() {
    File::file_open.close();
};