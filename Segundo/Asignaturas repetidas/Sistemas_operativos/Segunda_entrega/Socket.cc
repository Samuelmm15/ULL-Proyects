/**
 * @file Socket.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief File that contents the declaration of the socket methots
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ViewNet.h"

sockaddr_in make_ip_address(int port, const std::string& ip_address) {  
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
};