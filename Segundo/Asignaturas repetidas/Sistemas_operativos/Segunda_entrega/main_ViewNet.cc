/**
 * @file main_ViewNet.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "ViewNet.h"
#include "ViewNetSend.h"
#include "ViewNetReceive.h"

int main() {
    
}

// int num_port = 0;
//     std::string ip_num = "";
//     std::string answer = "";

//     std::cout << "Quiere introducir los valores para la creación del socket de forma manual(s/n): ";
//     std::cin >> answer;

//     for (int i = 0; i < answer.size(); i++) { /// Para convertir la cadena en minúscula en el caso de que haya sido introducida en mayúscula
//         answer[i] = tolower(answer[i]);
//     }

//     if (answer == "s") {    /// Incialización y creación del socket
//         std::cout << "Introduzca el número del puerto que quiere asignar al socket (Si pulsa intro se asignará el puerto 0 de manera predeterminada): " << '\n';
//         std::cin >> num_port;
//         std::cout << "Introduzca la dirección ip la cúal quiere asignar al socket (Si pulsa intro se asignará una aleatoria): " << '\n';
//         std::cin >> ip_num;
//     }
//     Socket S(make_ip_address(num_port, ip_num));    /// Inicialización y creación del socket

//     std::cout << "Quiere enviar un mensaje a través del socket(s/n): ";
//     std::cin >> answer;

//     for (int i = 0; i < answer.size(); i++) { /// Para convertir la cadena en minúscula en el caso de que haya sido introducida en mayúscula
//         answer[i] = tolower(answer[i]);
//     }

//     if (answer == "s") {
//         std::string message_to_send_to = "";
//         std::cout << "Introduzca el mensaje que quiere enviar: ";
//         std::cin >> message_to_send_to;

//         std::cout << "Introduzca los datos para la conexión con el socket remoto: " << '\n';
//         std::cout << "Introduzca el número del puerto que quiere asignar al socket: " << '\n';
//         std::cin >> num_port;
//         std::cout << "Introduzca la dirección ip la cúal quiere asignar al socket: " << '\n';
//         std::cin >> ip_num;

//         S.send_to(make_message(message_to_send_to), make_ip_address(num_port, ip_num));
//     }

//     std::cout << "Quiere mostrar por pantalla el mensaje enviado(s/n): ";
//     std::cin >> answer;

//     for (int i = 0; i < answer.size(); i++) { /// Para convertir la cadena en minúscula en el caso de que haya sido introducida en mayúscula
//         answer[i] = tolower(answer[i]);
//     }

//     if (answer == "s") {
//         std::string message_to_recieve_from = "";
//         std::cout << "Introduzca el mensaje que quiere enviar: ";
//         std::cin >> message_to_recieve_from;

//         std::cout << "Introduzca los datos para la conexión con el socket remoto: " << '\n';
//         std::cout << "Introduzca el número del puerto que quiere asignar al socket: " << '\n';
//         std::cin >> num_port;
//         std::cout << "Introduzca la dirección ip la cúal quiere asignar al socket: " << '\n';
//         std::cin >> ip_num;

//         Message mensaje = make_message(message_to_recieve_from); 
//         sockaddr_in dir_ip = make_ip_address(num_port, ip_num);
//         S.receive_from(mensaje,dir_ip);
//     }