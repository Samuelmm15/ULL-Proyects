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

#include "langton_world.h"
#include "langton_ant.h"

int main() { 
   World W;
   Ant A;
   cout << "Antes de comenzar el juego introduzca el tamaño de la malla que va a recorrer la hormiga: ";
   cin >> W.mesh_size;
   W.the_mesh[W.mesh_size][W.mesh_size];
   W.World_Generator(); /// generamos el mundo
   A.Ant_Generator(); /// generamos la hormiga
   W.World_Status(); /// imprimimos por primera vez el mundo
   
   for (int i = 0; i < W.mesh_size; i++) { /// En este punto se produce la copia
      for (int j = 0; j < W.mesh_size; j++) {
         A.the_mesh_copy[i][j] = W.the_mesh[i][j]; /// la malla del mundo es igual a la copia
      }
   }



   do {
      A.Ant_movement(); /// Here starts the game
      W.i_ant_coordinate = A.i_coordinate_value; /// igualamos estos valores para poder comprobar los limites
      W.j_ant_coordinate = A.j_coordinate_value; /// igualamos estos valores para poder comprobar los limites
      W.ant_position = A.posititon; /// igualamos estos valores para poder comprobar los limites
      W.Limit_Condition();
       for (int i = 0; i < W.mesh_size; i++) {
         for (int j = 0; j < W.mesh_size; j++) {
            W.the_mesh[i][j] = A.the_mesh_copy[i][j]; /// igualamos la malla original a la nueva malla obtenida para poder imprimir la malla correcta
         }
      }
      A.Ant_Status(); /// cambiamos el estado de la hormiga
      W.World_Status(); /// imprimimos de nuevo la malla
      A.Ant_Status_Representation(); /// imprimimos el estado de la hormiga
  } while (W.limit != 1);





}



/// Para poder imprimir por pantalla
/*
    for (int n = 0; n < A.the_mesh_copy.size(); n++) {
      cout << A.the_mesh_copy.at(n) << " ";
   }

*/
