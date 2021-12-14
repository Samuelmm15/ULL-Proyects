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

void ViewNetSend_fuction() {    /// Función necesaria para realizar el diagrama
    /// PREPARACIÓN DEL SOCKET REMOTO
    int num_port = 6000;
    std::string ip_remote_num = "127.0.0.1";
    std::string answer = "";

    std::cout << "Quiere introducir los valores para la creación del socket de forma manual(s/n): ";
    std::cin >> answer;

    for (int i = 0; i < answer.size(); i++) { /// Para convertir la cadena en minúscula en el caso de que haya sido introducida en mayúscula
        answer[i] = tolower(answer[i]);
    }

    if (answer == "s") {    /// Incialización y creación del socket
        std::cout << "Introduzca el número del puerto que quiere asignar al socket (Si pulsa intro se asignará el puerto 0 de manera predeterminada): " << '\n';
        std::cin >> num_port;
        std::cout << "Introduzca la dirección ip la cúal quiere asignar al socket (Si pulsa intro se asignará una aleatoria): " << '\n';
        std::cin >> ip_remote_num;
    }
    sockaddr_in remote_address = make_ip_address(num_port, ip_remote_num);  /// declaración del socket remoto
    Socket S(remote_address);    /// Inicialización y creación del socket
    std::string file_name = "prueba.txt";
    File F(file_name);

    if (F.file_open.eof()) {    /// liberación de recursos en el caso del que fichero esté vacío
        S.~Socket();    /// Cierre del socket
        F.~File();  /// Cierre del fichero
    }

    char file_content[100];
    while(!F.file_open.eof()) {
        F.file_open >> file_content;
    }

    std::string buff(file_content);
    
    // std::cout << buff << '\n';  COMPROBACIÓN DE QUE LA LECTURA DEL FICHERO SE HA REALIZADO DE MANERA CORRECTA
    
    /// Hacer uso del make message
    Message message = make_message(buff);
    /// Hacer uso del send to
    S.send_to(message, remote_address);  /// De esta manera se está realizando el envío del mensaje recogido del fichero de texto
    
};

int main() {
    ViewNetSend_fuction();  /// Ejecución de la función
}

/// APERTURA DEL ARCHIVO PRUEBA.TXT
    // std::string file_name = "prueba.txt";
    // File F(file_name);  /// en este punto se realiza la apertura del fichero

    // /// COMPROBACIÓN DE QUE EL FICHERO NO SE ENCUENTRA VACÍO
    // if (F.end_of_file() == 0) {
    //     S.~Socket(); /// Liberación de los recursos en el caso de que se llegue al final del archivo
    //     F.~File();
    //     /// exit(0); FALTA LA FINALIZACIÓN DEL PROGRAMA
    // }

    // /// Lectura del fichero y guardado del contenido en un vector
    // int read_byte = -1; /// Necesario para determinar el momento en el que se produce que se alcanza el final del fichero
    // char* buff;
    // int buff_size = 1024;   /// tamaño del vector del contenido del fichero
    // while (read_byte != 0) {
    //     read_byte = read(F.result_open, buff, buff_size);   /// manera de leer el contenido del fichero abierto
    // }

    // /// Convertir el tipo char to string
    // std::string buff_string(buff);  /// Conversión del vector de caracteres a string
