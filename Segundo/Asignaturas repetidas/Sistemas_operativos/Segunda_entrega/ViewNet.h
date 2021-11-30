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
#include <sys/types.h> /// library needed to create sockets
#include <sys/socket.h> /// library needed to create sockets
#include <netinet/in.h> /// library needed to create sockets
#include <arpa/inet.h>

#pragma once    /// Setencia que indica al compilador que solo se compile una vez este fichero

class Socket {  /// Clase socket necesaria para la creación de un socket
    public:
        Socket(const sockaddr_in& address);
        ~Socket();
    private:
        int fd_;
};

sockaddr_in make_ip_address(int port, const std::string& ip_address = std::string()) {  /// Función necesaria para la creación o el uso de distintas direcciones
    if (ip_address.size() == 0) {    /// En el caso en el que no se haya introducido ninguna dirección ip
        sockaddr_in local_inicialization{}; /// Inicialización de la estructura a vacío
        local_inicialization.sin_family = AF_INET;
        local_inicialization.sin_port = htons(port);
        local_inicialization.sin_addr.s_addr = htonl(INADDR_ANY);
    } else {
        sockaddr_in local_inicialization{}; /// Inicialización de la estructura a vacío
        local_inicialization.sin_family = AF_INET;
        local_inicialization.sin_port = htons(port);
        
        char ip_address_auxiliary[100]; /// Conversión del string en char
        strcpy(ip_address_auxiliary, ip_address.c_str());

        inet_aton(ip_address_auxiliary, &local_inicialization.sin_addr);
        // local_inicialization.sin_addr.s_addr = htonl(ip_address);
    }

};

Socket::Socket(const sockaddr_in& address) {
    Socket::fd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (Socket::fd_ < 0) {
        std::cerr << "No se pudo crear el socket: " << strerror(errno) << '\n';
        // return 3;   /// Determinar el tipo de error que se quiere usar para este caso
    } 

    int result = bind(Socket::fd_, reinterpret_cast<const sockaddr*>(&address), sizeof(address));

    if (result < 0) {
        std::cerr << "Falló bind: " << result << '\n';
        // return 5;   /// Determinar el tipo de error que se quiere usar para este caso
    }

};

Socket::~Socket() {
    // socket.close(Socket::fd_);
}