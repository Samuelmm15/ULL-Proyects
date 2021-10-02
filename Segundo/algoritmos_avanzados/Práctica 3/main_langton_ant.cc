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

int main() { 
   
   int option_world;
   cout << "¿Qué tipo de mundo quiere escoger? (Mundo finito[1], Mundo Infinito[2]): ";
   cin >> option_world;

   if (option_world == 1) {
      
      Universe U;
      U.ant_universe(option_world);

   } else if (option_world == 2) {
      
      Universe U;
      U.ant_universe(option_world);

   } else if (option_world != 1 | 2) {
      cout << "ERROR AL INTRODUCIR EL TIPO DE MUNDO QUE QUIERE ESTABLECER" << endl;
      cout << "Introduzca un número válido para esto" << endl;
      exit(1);
   }

}
