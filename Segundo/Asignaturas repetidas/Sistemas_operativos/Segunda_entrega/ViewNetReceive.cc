/**
 * @file ViewNetReceive.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief File that contents the fuctions neeeded to recieve messages sended into the sockets
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ViewNet.h"

/**
 * @brief Fuction that recieve the message of the remote socket
 * 
 */
void ViewNetReceive_fuction() { 
    sockaddr_in local_ip_address = make_ip_address(6001, "127.0.0.1"); /// Making the local ip address
    Socket S(local_ip_address);    /// Local socket creation

    std::string r_message = "";
    Message free_message = make_message(r_message); /// Generating a empty socket
    sockaddr_in remote_address{};
    S.receive_from(free_message, remote_address); /// Recieve the message and writing it in the screen

    /// Writting the message into the screen
    char* remote_ip = inet_ntoa(remote_address.sin_addr);
    int remote_port = ntohs(remote_address.sin_port);
    free_message.text[1023] = '\0';  /// Necessary to mark the final of a string
    std::cout << "El sistema " << remote_ip << ":" << remote_port << " envió el mensaje '" << free_message.text.data() << "'\n";
};

int main() {
    ViewNetReceive_fuction();
}
