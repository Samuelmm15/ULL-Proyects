#if !defined FTPServer_H
#define FTPServer_H

#include <list>


#include "ClientConnection.h"

class FTPServer {
public:
  FTPServer(int port = 21); /// constructor de la clase
  void run(); /// para ejecutar el servicio
  void stop(); /// para parar el servicio

private:
  int port; /// puerto
  int msock; /// socket
  std::list<ClientConnection*> connection_list; /// lista de conexión
};

#endif