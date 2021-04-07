/**
 * @file langton_ant.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Lagton ant diterministic discrete system. To understant the functioning go to the site: https://es.wikipedia.org/wiki/Hormiga_de_Langton
 * @version 0.1
 * @date 2021-02-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "langton_world.h"
#include "langton_ant.h"
#include "langton_vector.h"
#include "langton_universe.h"

void World::World_Generator() {  
    for (int i = World::i_ini_min_world; i < World::i_ini_max_world; i++) {
       for (int j = World::j_ini_min_world; j < World::j_ini_max_world; j++) {
            World::the_mesh[i][j] = 0;  
       }
    }
};

void World::World_Status() {    
    for (int i = World::i_ini_min_world; i < World::i_ini_max_world; i++) {        
      for (int j = World::j_ini_min_world; j < World::j_ini_max_world; j++) {
         if (World::the_mesh[i][j] == 0) {
            cout << " " << " ";
         }
         if (World::the_mesh[i][j] == 1) {
            cout << "x" << " ";
         }
         if (World::the_mesh[i][j] == 2) {
            cout << "O" << " ";
         }
      }
      cout << "\n";
   }  
   cout << endl;
};

void World::Limit_Condition() {
   if (((World::i_ant_coordinate == World::i_ini_min_world - 1) && (World::j_ant_coordinate == World::j_ini_min_world)) || ((World::i_ant_coordinate == World::i_ini_min_world - 1) && (World::j_ant_coordinate == World::j_ini_min_world - 1)) || ((World::i_ant_coordinate == World::i_ini_min_world) && (World::j_ant_coordinate == World::j_ini_min_world - 1))) { 
         if (World::ant_position == "^") {
            World::resize = 0;
            World::resize = 1;
         } else if (World::ant_position == "<") {
            World::resize = 0;
            World::resize = 2;
         } else if (World::ant_position == "`") {
            World::resize1 = 0;
            World::resize1 = 1;
         }
      } else if ((World::i_ant_coordinate == World::i_ini_max_world) && (World::j_ant_coordinate == World::j_ini_min_world - 1) || ((World::i_ant_coordinate == World::i_ini_max_world + 1) && (World::j_ant_coordinate == World::j_ini_min_world - 1)) || ((World::i_ant_coordinate == World::i_ini_max_world + 1) && (World::j_ant_coordinate == World::j_ini_min_world))) { 
         if (World::ant_position == "<") {
            World::resize = 0;
            World::resize = 2;
         } else if (World::ant_position == "v") {
            World::resize = 0;
            World::resize = 3;
         } else if (World::ant_position == "%") {
            World::resize1 = 0;
            World::resize1 = 2;
         }
      } else if ((World::i_ant_coordinate == World::i_ini_max_world + 1) && (World::j_ant_coordinate == World::j_ini_max_world) || ((World::i_ant_coordinate == World::i_ini_max_world + 1) && (World::j_ant_coordinate == World::j_ini_max_world + 1)) || ((World::i_ant_coordinate == World::i_ini_max_world) && (World::j_ant_coordinate == World::j_ini_max_world + 1))) { 
          if (World::ant_position == "v") {
            World::resize = 0;
            World::resize = 3;
         } else if (World::ant_position == ">") {
            World::resize = 0;
            World::resize = 4;
         } else if (World::ant_position == "¬") {
            World::resize1 = 0;
            World::resize1 = 3;
         }
      } else if ((World::i_ant_coordinate == World::i_ini_min_world) && (World::j_ant_coordinate == World::j_ini_max_world + 1) || ((World::i_ant_coordinate == World::i_ini_min_world - 1) && (World::j_ant_coordinate == World::j_ini_max_world + 1)) || ((World::i_ant_coordinate == World::i_ini_min_world - 1) && (World::j_ant_coordinate == World::j_ini_max_world))) { 
         if (World::ant_position == "^") {
            World::resize = 0;
            World::resize = 1;
         } else if (World::ant_position == ">") {
            World::resize = 0;
            World::resize = 4;
         } else if (World::ant_position == "/") {
            World::resize1 = 0;
            World::resize1 = 4;
         }
      } else if (World::i_ant_coordinate == World::i_ini_min_world - 1) {
         World::resize = 0; 
         World::resize = 1;
      } else if (World::j_ant_coordinate == World::j_ini_min_world - 1) {
         World::resize = 0; 
         World::resize = 2;
      } else if (World::i_ant_coordinate == World::i_ini_max_world + 1) {
         World::resize = 0; 
         World::resize = 3;
      } else if (World::j_ant_coordinate == World::j_ini_max_world + 1) {
         World::resize = 0; 
        World::resize = 4;
      
      }
};

void Ant::Ant_Generator() { 
    cout << "Introduzca las coordenadas donde quiere que comience la hormiga, debe de introducir los valores de i y de j de la manera (i j): ";
    cin >> Ant::i_coordinate;
    cin >> Ant::j_coordinate;
    cout << "A continuación introduzca la dirección a la que quiere que apunte la hormiga al comenzar: ";
    cin >> Ant::posititon;

    for (int n = 0; n < 3; n++) {  
      if (n == 0) {
         Ant::ant[n] = Ant::i_coordinate;
      } else if (n == 1) {
         Ant::ant[n] = Ant::j_coordinate;
      } else if (n == 2) {
         Ant::ant[n] = Ant::posititon;
      }
    }

   istringstream convert(Ant::i_coordinate); /// To convert a string to an int
   if (!(convert >> Ant::i_coordinate_value)) {
      Ant::i_coordinate_value = 0;
   } /// Here is the converted number
   istringstream convert1(Ant::j_coordinate); /// To convert a string to an int
   if (!(convert1 >> Ant::j_coordinate_value)) {
      Ant::j_coordinate_value = 0;
   } /// Here is the converted number

}; 

void Ant::Ant_Status() { 
   ostringstream reconvert_i;
   reconvert_i << Ant::i_coordinate_value;
   Ant::i_coordinate = reconvert_i.str(); /// Now the int value is converted into a string
   
   ostringstream reconvert_j;
   reconvert_j << Ant::j_coordinate_value;
   Ant::j_coordinate = reconvert_j.str(); /// Now the int value is converted into a string

   for (int n = 0; n < 3; n++) { 
      if (n == 0) {
         Ant::ant[n] = Ant::i_coordinate;
      } else if (n == 1) {
         Ant::ant[n] = Ant::j_coordinate;
      } else if (n == 2) {
         Ant::ant[n] = Ant::posititon;
      }
    }
};

void Ant::Ant_movement() { 
   if (the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 0) {
      Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] = 1;
      if (Ant::posititon == ">") {
            Ant::posititon = "/";  
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1; 
            Ant::j_coordinate_value  = Ant::j_coordinate_value + 1;
      } else if (Ant::posititon == "/") {
            Ant::posititon = "^";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "^") {
            Ant::posititon = "`";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      } else if (Ant::posititon == "`") {
            Ant::posititon = "<";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      } else if (Ant::posititon == "<") {
            Ant::posititon = "%";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      } else if (Ant::posititon == "%") {
            Ant::posititon = "v";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "V") {
         Ant::posititon = "¬";
         Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
         Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
      } else if (Ant::posititon == "¬") {
         Ant::posititon = ">";
         Ant::i_coordinate_value = Ant::i_coordinate_value;
         Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
      }
   } else if (Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 1) {  
      Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] = 0;
      if (Ant::posititon == ">") {
            Ant::posititon = "¬";  
            Ant::i_coordinate_value = Ant::i_coordinate_value + 1; 
            Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
      } else if (Ant::posititon == "¬") {
            Ant::posititon = "v";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "v") {
            Ant::posititon = "%";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      } else if (Ant::posititon == "%") { 
            Ant::posititon = "<";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      } else if (Ant::posititon == "<") {
            Ant::posititon = "`";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      } else if (Ant::posititon == "`") {
            Ant::posititon = "^";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "^") {
            Ant::posititon = "/";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
      } else if (Ant::posititon == "/") {
            Ant::posititon = ">";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
      }
   } else if (Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 2) { /// se debe de girar 180º
      Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] = 0;
        if (Ant::posititon == ">") {
            Ant::posititon = "<";  
            Ant::i_coordinate_value = Ant::i_coordinate_value; 
            Ant::j_coordinate_value = Ant::j_coordinate_value - 2;
      } else if (Ant::posititon == "¬") {
            Ant::posititon = "`";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 2;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 2;
      } else if (Ant::posititon == "v") {
            Ant::posititon = "^";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 2;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "%") { 
            Ant::posititon = "/";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 2;
            Ant::j_coordinate_value = Ant::j_coordinate_value + 2;
      } else if (Ant::posititon == "<") {
            Ant::posititon = ">";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value + 2;
      } else if (Ant::posititon == "`") {
            Ant::posititon = "¬";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 2;
            Ant::j_coordinate_value = Ant::j_coordinate_value + 2;
      } else if (Ant::posititon == "^") {
            Ant::posititon = "v";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 2;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "/") {
            Ant::posititon = "%";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 2;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 2;
      }
   }
};

void Ant::Ant_Status_Representation() {
   for (int n = 0; n < 3; n++) {
      cout << Ant::ant[n] << " ";
   }
   cout << endl;
};

void Universe::ant_universe() {
   World W;
   Ant A;
   Vector <int> V;

   cout << "Antes de comenzar el juego introduzca el tamaño de la malla que va a recorrer la hormiga: ";
   cin >> W.mesh_size;
   
   V.i_ini_min = 0; 
   V.j_ini_min = 0; 
   V.i_ini_max = W.mesh_size; 
   V.j_ini_max = W.mesh_size; 

   W.the_mesh[V.i_ini_max][V.j_ini_max]; 

   W.i_ini_min_world = V.i_ini_min; 
   W.i_ini_max_world = V.i_ini_max;
   W.j_ini_min_world = V.j_ini_min;
   W.j_ini_max_world = V.j_ini_max;

   W.World_Generator(); 
   A.Ant_Generator(); 
   W.World_Status(); 
   
   for (int i = V.i_ini_min; i < V.i_ini_max; i++) { 
      for (int j = V.j_ini_min; j < V.j_ini_max; j++) {
         A.the_mesh_copy[i][j] = W.the_mesh[i][j]; 
      }
   }

   int counter = 0;
   
   do {
      A.Ant_movement(); /// Here starts the game

      W.i_ant_coordinate = A.i_coordinate_value; 
      W.j_ant_coordinate = A.j_coordinate_value; 
      W.ant_position = A.posititon; 
      W.Limit_Condition(); 

      for (int i = V.i_ini_min; i < V.i_ini_max; i++) {
         for (int j = V.j_ini_min; j < V.j_ini_max; j++) {
            if ((i < 0) || (j < 0)) {
               A.the_mesh_copy[i][j] = 2;
            }
            
            W.the_mesh[i][j] = A.the_mesh_copy[i][j];
            
            if ((i >= V.i_ini_max) || (j >= V.j_ini_max)) {
                  A.the_mesh_copy[i][j] = 2;
               }
            }
         }

      if (W.resize == 1 | 2 | 3 | 4) { 
         V.aux = W.resize;
         V.aux1 = W.resize1;

         V.Mesh_Resize();

         W.resize = 0; 
         W.resize1 = 0;

         W.i_ini_min_world = V.i_ini_min;
         W.i_ini_max_world = V.i_ini_max;
         W.j_ini_min_world = V.j_ini_min;
         W.j_ini_max_world = V.j_ini_max;

      }

      counter++;

      if (counter == 20) {
         cout << endl;
         cout << "¿ DESEA FINALIZAR LA EJECUCIÓN DEL JUEGO ?" << endl;
         int option;
         cout << "SI LO DESEA PULSE 1, SI DESEA QUE NO 0 : ";
         cin >> option;

         if (option == 1) {
            W.limit = 1;
         } else if (option == 0) {
            counter = 0;
         }
      }

      A.Ant_Status();
      W.World_Status();
      A.Ant_Status_Representation();

  } while (W.limit != 1);
    exit(1);
};
