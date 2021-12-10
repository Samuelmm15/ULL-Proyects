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

void ViewNetReceive_fuction() { /// Función necesaria para la realización del diagrama
    /// CREACIÓN DEL SOCKET LOCAL Y ASIGNACIÓN DE LA DIRECCIÓN BIND()
    int num_port = 0;
    std::string ip_num = "";
    Socket S(make_ip_address(num_port, ip_num));    /// creación del socket local

    std::string r_message = "";
    Message free_message = make_message(r_message);
    sockaddr_in remote_ip = make_ip_address(num_port, ip_num);
    S.receive_from(free_message, remote_ip); /// recepción del mensaje pasado a través del socket

};

int main() {
    ViewNetReceive_fuction(); /// ejecución de la función
}
