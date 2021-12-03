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
#include <sys/types.h> /// library needed to create sockets
#include <sys/socket.h> /// library needed to create sockets
#include <netinet/in.h> /// library needed to create sockets
#include <arpa/inet.h>

#pragma once    /// Setencia que indica al compilador que solo se compile una vez este fichero

struct Message {    /// Estructura necesaria para la generación de mensajes
    std::array<char,1024> text;
};
class Socket {  /// Clase socket necesaria para la creación de un socket
    public:
        Socket(const sockaddr_in& address);
        ~Socket();

        void send_to(const Message& message, const sockaddr_in& address); /// Función necesaria para el envío de mensajes
        void receive_from(Message& message, sockaddr_in& address);
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

Message make_message(std::string in_message) {    /// Función necesaria para la inicialización y creación de un mensaje
    Message message_initialization{};   /// Inicialización de la estructura a vacío
    in_message.copy(message_initialization.text.data(), message_initialization.text.size() - 1, 0);
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
    /// Falta cerrar el socket de alguna manera con la función close()
};

void Socket::send_to(const Message& message, const sockaddr_in& address) {
    int result = sendto(Socket::fd_, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&address), sizeof(address));
    if (result < 0) {
        std::cerr << "Falló sendto: " << strerror(errno) << '\n';
        // return 6;    Mejorar la salida por error de alguna manera
    }
};

void Socket::receive_from(Message& message, sockaddr_in& address) {
    socklen_t src_len = sizeof(address);
    int result = recvfrom(Socket::fd_, &message, sizeof(message), 0, reinterpret_cast<sockaddr*>(&address), &src_len);
    if (result < 0) {
        std::cerr << "Falló rcvfrom: " << strerror(errno) << '\n';
        // return 8;    mejorar la salida de error
    }

    /// Mostrar el mensaje recibido en la terminal
    message.text[1023] = '\0';  /// Necesario para que la salida por pantalla reconozca el final de la cadena de texto
    std::cout << "El sistema envió el mensaje " << message.text.data() << '\n';
};