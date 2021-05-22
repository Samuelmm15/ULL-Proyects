//****************************************************************************
//                         REDES Y SISTEMAS DISTRIBUIDOS
//                      
//                     2º de grado de Ingeniería Informática
//                       
//              This class processes an FTP transaction.
// 
//****************************************************************************



#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cerrno>
#include <netdb.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h> 
#include <iostream>
#include <dirent.h>

#include "common.h"

#include "ClientConnection.h"




ClientConnection::ClientConnection(int s) {
    int sock = (int)(s);
  
    char buffer[MAX_BUFF];

    control_socket = s;
    // Check the Linux man pages to know what fdopen does.
    fd = fdopen(s, "a+");
    if (fd == NULL){
	std::cout << "Connection closed" << std::endl;

	fclose(fd);
	close(control_socket);
	ok = false;
	return ;
    }
    
    ok = true;
    data_socket = -1;
    parar = false;
   
  
  
};


ClientConnection::~ClientConnection() { 
 	fclose(fd);
	close(control_socket); 
  
}

int s;
int connect_TCP( char *address,  uint16_t  port) { 
    // Implement your code to define a socket here
    struct sockaddr_in sin;
    struct hostent *hent;

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);

    hent = gethostbyname(address);
    if (hent) {
        memcpy(&sin.sin_addr, hent->h_addr_list, hent->h_length);
    } else if ((sin.sin_addr.s_addr = inet_addr((char*)address)) == INADDR_NONE) {
        errexit("No se pudo resolver el nombre %s\n ", address);
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        errexit("No se puede crear el socket: %s\n", strerror(errno));
    }

    if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        errexit("No se puede conectar con %s: %s\n", address, strerror(errno));
    }


    return s; // You must return the socket descriptor.

}






void ClientConnection::stop() { 
    close(data_socket);
    close(control_socket);
    parar = true;
  
}





    
#define COMMAND(cmd) strcmp(command, cmd)==0

// This method processes the requests.
// Here you should implement the actions related to the FTP commands.
// See the example for the USER command.
// If you think that you have to add other commands feel free to do so. You 
// are allowed to add auxiliary methods if necessary.

void ClientConnection::WaitForRequests() {
    if (!ok) {
	 return;
    }
    
    fprintf(fd, "220 Service ready\n");
    bool passive_mode = false;

    while(!parar) {

      fscanf(fd, "%s", command);
      if (COMMAND("USER")) {
	    fscanf(fd, "%s", arg);
	    fprintf(fd, "331 User name ok, need password\n");
      }
      else if (COMMAND("PWD")) {
	   
      }
      else if (COMMAND("PASS")) {
        fscanf(fd, "%s", arg);
        if(strcmp(arg,"1234") == 0){
            fprintf(fd, "230 User logged in\n");
        }
        else{
            fprintf(fd, "530 Not logged in.\n");
            parar = true;
        }
	   
      }
      else if (COMMAND("PORT")) { 
	  // To be implemented by students
      int host_number[3];
      int port_number[1];
        fflush(fd);
        fscanf(fd, "%d,%d,%d,%d,%d,%d", &host_number[0], &host_number[1], &host_number[2], &host_number[3], &port_number[0], &port_number[1]);
        if (fscanf) { 
            fprintf(fd, "200 The command is correct.\r\n");
        }
        else {
            fprintf(fd, "425 Unable to open data connection\r\n");
            parar = true;
        }
      }
      else if (COMMAND("PASV")) { /// Acceder a modo pasivo
	  // To be implemented by students
      if (passive_mode == false) {
          passive_mode = true;
      } else {
          passive_mode = false;
      }

      }
      else if (COMMAND("STOR") ) { /// Almacenar un archivo en el host remoto
	    // To be implemented by students
        fflush(fd); /// To clean the buffer
        fscanf(fd, "%s", arg); 
        if (strcmp(arg, " ") == 0) {
            fprintf(fd, "450 Requested file action not completed. The file is not available.\r\n");
        } else {
            ///send(s, arg, 9, 0); /// Función para el envío de datos a través del socket
            fprintf(fd, "226 Closing the data connection. The requested file action was successful.\r\n");
        } 
      }
      else if (COMMAND("RETR")) {  /// Recupera un archivo remoto
	   // To be implemented by students
        fscanf(fd, "%s", arg);
        if (strcmp(arg, " ") == 0) {
            fprintf(fd, "450 Requested file action not completed. The file is not available.\r\n");
        }
        else {
            fprintf(fd, "425 Unable to open data connection.\r\n");
            fprintf(fd, "226 Closing the data connection. The requested file action was successful.\r\n");
        }
        
      }
      else if (COMMAND("LIST")) { /// Enumerar archivos remotos
	   // To be implemented by students
        fscanf(fd, "%s", arg);
        fprintf(fd, "125 The data connection is now open, the transfer starts.");

        fprintf(fd, "225 Correct requested file action; completed.");
      }
      else if (COMMAND("SYST")) {
           fprintf(fd, "215 UNIX Type: L8.\n");   
      }

      else if (COMMAND("TYPE")) {
	  fscanf(fd, "%s", arg);
	  fprintf(fd, "200 OK\n");   
      }
     
      else if (COMMAND("QUIT")) {
        fprintf(fd, "221 Service closing control connection. Logged out if appropriate.\n");
        close(data_socket);	
        parar=true;
        break;
      }
  
      else  {
	    fprintf(fd, "502 Command not implemented.\n"); fflush(fd);
	    printf("Comando : %s %s\n", command, arg);
	    printf("Error interno del servidor\n");
	
      }
      
    }
    
    fclose(fd);

    
    return;
  
};
