/**
 * @file main_langton_ant.cc
 * @author samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Lagton ant diterministic discrete system. To understant the functioning go to the site: https://es.wikipedia.org/wiki/Hormiga_de_Langton
 * @version 0.1
 * @date 2021-02-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "langton_ant.h"
#include "langton_world.h"

int main() { 
   World W;
   Ant A;
   cout << "Antes de comenzar el juego introduzca el tamaño de la malla que va a recorrer la hormiga: ";
   cin >> W.mesh_size;
   W.the_mesh[W.mesh_size][W.mesh_size];
   W.World_Generator();
   A.Ant_Generator();
   W.i_ant_coordinate = A.i_coordinate_value;
   W.j_ant_coordinate = A.j_coordinate_value;
   W.ant_position = A.posititon;
  
  
  do {
      W.Cell_Change(); /// Here starts the game 
      A.i_coordinate_value = W.i_ant_coordinate;
      A.j_coordinate_value = W.j_ant_coordinate;
      A.posititon = W.ant_position;
      A.Ant_Status();
      W.World_Status();
      A.Ant_Status_Representation();
  } while (W.limit != 1);

}

/// An extra option for the program:
/* 
string decision;
   cout << "Antes de terminar, ¿ quiere visualizar el resultado final del estado de la hormiga ?" << endl;
   cout << "Si quiere visualizarlo, introduzca si, en caso contrario, no : ";
   cin >> decision;

   if (decision == "si") {
      for (int n = 0; n < 3; n++) {
         cout << A.ant[n] << " ";
      }
      cout << endl;
      cout << "Este es el resultado final de la hormiga para la malla, el comienzo y dirección introducidos" << endl;
      exit(1);
   } else if (decision == "no") {
      cout << "Juego finalizado" << endl;
      exit(1);
   } else if (decision != "si" || "no") {
      cout << "Error al introducir una respuesta adecuada" << endl;
      cout << "La respuesta introducida debe ser de la manera: 'si' o 'no'." << endl;
      exit(1);
   }
*/