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

/**
 * @brief Fuction that send the message into the remote socket
 * 
 */
void ViewNetSend_fuction() {
    int num_port = 6000;
    std::string ip_remote_num = "127.0.0.1";
    std::string answer = "";

    std::cout << "Quiere introducir los valores para la creación del socket de forma manual(s/n): ";
    std::cin >> answer;

    for (int i = 0; i < answer.size(); i++) { /// To convert the upper into a lower case
        answer[i] = tolower(answer[i]);
    }

    if (answer == "s") { 
        std::cout << "Introduzca el número del puerto que quiere asignar al socket (Si pulsa intro se asignará el puerto 0 de manera predeterminada): " << '\n';
        std::cin >> num_port;
        std::cout << "Introduzca la dirección ip la cúal quiere asignar al socket (Si pulsa intro se asignará una aleatoria): " << '\n';
        std::cin >> ip_remote_num;
    }
    sockaddr_in remote_address = make_ip_address(num_port, ip_remote_num);  /// Socket address initialization
    Socket S(remote_address);    /// Create the socket object
    std::string file_name = "prueba.txt";
    File F(file_name);

    if (F.file_open.eof()) {    /// If the file is empty
        S.~Socket();    
        F.~File();
    }

    char file_content[100];
    while(!F.file_open.eof()) {
        F.file_open >> file_content;
    }

    std::string buff(file_content);
        
    Message message = make_message(buff);   /// Generating the message getted of the file
    S.send_to(message, remote_address);  /// Send the message into the remote socket
    
};

int main() {
    ViewNetSend_fuction();
}
