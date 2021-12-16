/**
 * @file ViewNetSend.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief File that contents the fuction needed to Send messages into the sockets
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ViewNet.h"
#include "File.h"

/**
 * @brief Fuction that send the message into the remote socket
 * 
 */
void ViewNetSend_fuction() {
    sockaddr_in local_address = make_ip_address(6000, "127.0.0.1"); /// Socket address initialization
    Socket S(local_address);    /// Create the socket object
    sockaddr_in remote_address = make_ip_address(6001, "127.0.0.1");
    std::string file_name = "prueba.txt";
    File F(file_name);

    char file_content[100];
    int length;
    while((length = read(F.file_fd, file_content, 1024)) > 0);
    
    std::string buff(file_content);
    Message message = make_message(buff); /// Generating the message getted of the file
    S.send_to(message, remote_address);  /// Send the message into the remote socket
    
};

int main() {
    ViewNetSend_fuction();
}
