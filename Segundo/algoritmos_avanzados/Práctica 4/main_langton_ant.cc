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
#include "langton_finiteworld.h"
#include "langton_infiniteworld.h"
#include "langton_ant.h"
#include "langton_vector.h"
#include "langton_universe.h"

int main() { /// En la función principal se deben de inicializar el mundo y las hormigas y ser pasadas como objetos del universo
   Finite_World F;
   Infinite_World I;
   Ant A; 
   Universe U;
   Vector_World <int> V;
   list<Ant> ant_list; /// con esto ya tenemos creada la lista de hormigas

   int option_world;
   cout << "¿Qué tipo de mundo quiere escoger? (Mundo finito[1], Mundo Infinito[2]): ";
   cin >> option_world;

   if (option_world == 1) {

      cout << "Antes de comenzar el juego introduzca el tamaño de la malla que va a recorrer la hormiga: ";
      cin >> F.mesh_size;

      V.i_ini_min = 0; 
      V.j_ini_min = 0; 
      V.i_ini_max = F.mesh_size; 
      V.j_ini_max = F.mesh_size; 

      F.the_mesh[V.i_ini_max][V.j_ini_max]; 

      F.i_ini_min_world = V.i_ini_min; 
      F.i_ini_max_world = V.i_ini_max;
      F.j_ini_min_world = V.j_ini_min;
      F.j_ini_max_world = V.j_ini_max;

      F.World_Generator_Finiteworld(); /// Accedemos a la clase generadora del mundo 


      int num_of_ants = 0;
      cout << "Ahora introduzca el número de hormigas que quiere incluir dentro del programa: ";
      cin >> num_of_ants;

      for (int i = 0; i < num_of_ants; i++) {
         ant_list.push_back(A); /// CON ESTO CREAMOS TODAS LAS HORMIGAS DEL TIPO OBJETO
      }

      A.Ant_Generator(ant_list); /// generamos las hormigas 

      U.ant_universe(option_world, F, I, A, V, ant_list); /// Le pasamos a la función universo todos los objetos necesarios
      exit(1);

   } else if (option_world == 2) {
      cout << "Antes de comenzar el juego introduzca el tamaño de la malla que va a recorrer la hormiga: ";
      cin >> I.mesh_size;

      V.i_ini_min = 0; 
      V.j_ini_min = 0; 
      V.i_ini_max = I.mesh_size; 
      V.j_ini_max = I.mesh_size; 

      I.the_mesh[V.i_ini_max][V.j_ini_max]; 

      I.i_ini_min_world = V.i_ini_min; 
      I.i_ini_max_world = V.i_ini_max;
      I.j_ini_min_world = V.j_ini_min;
      I.j_ini_max_world = V.j_ini_max;

      I.World_Generator_Infiteworld(); /// Accedemos a la clase generadora del mundo 

      int num_of_ants = 0;
      cout << "Ahora introduzca el número de hormigas que quiere incluir dentro del programa: ";
      cin >> num_of_ants;

      for (int i = 0; i < num_of_ants; i++) {
         ant_list.push_back(A); /// CON ESTO CREAMOS TODAS LAS HORMIGAS DEL TIPO OBJETO
      }

      A.Ant_Generator(ant_list); /// generamos las hormigas 

      U.ant_universe(option_world, F, I, A, V, ant_list);
      exit(1);

   } else if (option_world != 1 | 2) {
      cout << "ERROR AL INTRODUCIR EL TIPO DE MUNDO QUE QUIERE ESTABLECER" << endl;
      cout << "Introduzca un número válido para esto" << endl;
      exit(1);
   }

}
