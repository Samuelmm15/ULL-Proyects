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
    int num_port = 6001 ;
    std::string ip_num_local = "127.0.0.1";
    sockaddr_in local_ip_address = make_ip_address(num_port, ip_num_local); /// Making the local ip address
    Socket S(local_ip_address);    /// Local socket creation

    std::string r_message = "";
    Message free_message = make_message(r_message); /// Generating a empty socket
    sockaddr_in remote_ip = make_ip_address(6000, ip_num_local);
    S.receive_from(free_message, remote_ip); /// Recieve the message and writing it in the screen

};

int main() {
    ViewNetReceive_fuction();
}
