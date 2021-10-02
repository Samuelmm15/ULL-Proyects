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

void World::World_Generator() {  /// Ponemos que se trata de una matriz con todo cero son las casillas blancas y 1 son las negras
    for (int i = 0; i < World::mesh_size; i++) {
       for (int j = 0; j < World::mesh_size; j++) {
            World::the_mesh[i][j] = 0;  
       }
    }
};

void World::World_Status() {     /// cambiar la manera de impresión para arreglar esto
    for (int i = 0; i < World::mesh_size; i++) {        
      for (int j = 0; j < World::mesh_size; j++) {
         if (World::the_mesh[i][j] == 0) {
            cout << " " << " ";
         }
         if (World::the_mesh[i][j] == 1) {
            cout << "x" << " ";
         }
      }
      cout << "\n";
   }  
   cout << endl;
};

void World::Limit_Condition() { 
   if (World::i_ant_coordinate == (World::mesh_size + 1)) {
      cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
      cout << "FIN DEL JUEGO" << endl;
      cout << "RESULTADO FINAL:" << endl;
      World::limit = 1;
   }
   if (World::j_ant_coordinate == (World::mesh_size + 1)) {
      cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
      cout << "FIN DEL JUEGO" << endl;
      cout << "RESULTADO FINAL:" << endl;
      World::limit = 1;
   } 
   if (World::i_ant_coordinate == -1) { 
      cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
      cout << "FIN DEL JUEGO" << endl;
      cout << "RESULTADO FINAL" << endl;
      World::limit = 1;
   }
   if (World::j_ant_coordinate == -1) {
      cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
      cout << "FIN DEL JUEGO" << endl;
      cout << "RESULTADO FINAL:" << endl;
      World::limit = 1;
   }
   if (World::i_ant_coordinate && World::j_ant_coordinate == 0) {
      if (World::ant_position == "^" || "<") {
         cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
         cout << "FIN DEL JUEGO" << endl;
         cout << "RESULTADO FINAL:" << endl;
         World::limit = 1;
      }
   }
   if ((World::i_ant_coordinate == World::mesh_size) && (World::j_ant_coordinate == 0)) {
      if (World::ant_position == "<" || "v") {
         cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
         cout << "FIN DEL JUEGO" << endl;
         cout << "RESULTADO FINAL:" << endl;
         World::limit = 1;
      }
   }
   if (World::i_ant_coordinate && World::j_ant_coordinate == World::mesh_size) {
      if (World::ant_position == ">" || "v") {
         cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
         cout << "FIN DEL JUEGO" << endl;
         cout << "RESULTADO FINAL:" << endl;
         World::limit = 1;
      }
   }
   if ((World::i_ant_coordinate == 0) && (World::j_ant_coordinate == World::mesh_size)) {
      if (World::ant_position == "^" || ">") {
         cout << "LA HORMIGA A LLEGADO AL LÍMITE DE LA MALLA" << endl;
         cout << "FIN DEL JUEGO" << endl;
         cout << "RESULTADO FINAL:" << endl;
         World::limit = 1;
      }
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
   Ant::i_coordinate = reconvert_i.str(); /// ahora está convertido el valor int en una string para actualizar la hormiga
   
   ostringstream reconvert_j;
   reconvert_j << Ant::j_coordinate_value;
   Ant::j_coordinate = reconvert_j.str(); /// ahora está convertido el valor int en una string para actualizar la hormiga

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
            Ant::posititon = "^";  
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1; 
            Ant::j_coordinate_value  = Ant::j_coordinate_value;
      } else if (Ant::posititon == "^") {
            Ant::posititon = "<";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      } else if (Ant::posititon == "<") {
            Ant::posititon = "v";
            Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "v") {
            Ant::posititon = ">";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
      }
   } else if (Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 1) {  
      Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] = 0;
      if (Ant::posititon == ">") {
            Ant::posititon = "v";  
            Ant::i_coordinate_value = Ant::i_coordinate_value + 1; 
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "^") {
            Ant::posititon = ">";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
      } else if (Ant::posititon == "<") {
            Ant::posititon = "^";
            Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
            Ant::j_coordinate_value = Ant::j_coordinate_value;
      } else if (Ant::posititon == "v") { 
            Ant::posititon = "<";
            Ant::i_coordinate_value = Ant::i_coordinate_value;
            Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
      }
   }
};

void Ant::Ant_Status_Representation() {
   for (int n = 0; n < 3; n++) {
      cout << Ant::ant[n] << " ";
   }
   cout << endl;
};


/// Esto debe de estar en la hormiga y no en el mundo
/* 
if (World::the_mesh[World::i_ant_coordinate][World::j_ant_coordinate] == " ") {  
      World::the_mesh[World::i_ant_coordinate][World::j_ant_coordinate] = "x";
      if (World::ant_position == ">") {
            World::ant_position = "^";  
            World::i_ant_coordinate = World::i_ant_coordinate - 1; 
            World::j_ant_coordinate = World::j_ant_coordinate;
      } else if (World::ant_position == "^") {
            World::ant_position = "<";
            World::i_ant_coordinate = World::i_ant_coordinate;
            World::j_ant_coordinate = World::j_ant_coordinate - 1;
      } else if (World::ant_position == "<") {
            World::ant_position = "v";
            World::i_ant_coordinate = World::i_ant_coordinate + 1;
            World::j_ant_coordinate = World::j_ant_coordinate;
      } else if (World::ant_position == "v") {
            World::ant_position = ">";
            World::i_ant_coordinate = World::i_ant_coordinate;
            World::j_ant_coordinate = World::j_ant_coordinate + 1;
      }
   } else if (World::the_mesh[World::i_ant_coordinate][World::j_ant_coordinate] == "x") {  
      World::the_mesh[World::i_ant_coordinate][World::j_ant_coordinate] = " ";
      if (World::ant_position == ">") {
            World::ant_position = "v";  
            World::i_ant_coordinate = World::i_ant_coordinate + 1; 
            World::j_ant_coordinate = World::j_ant_coordinate;
      } else if (World::ant_position == "^") {
            World::ant_position = ">";
            World::i_ant_coordinate = World::i_ant_coordinate;
            World::j_ant_coordinate = World::j_ant_coordinate + 1;
      } else if (World::ant_position == "<") {
            World::ant_position = "^";
            World::i_ant_coordinate = World::i_ant_coordinate - 1;
            World::j_ant_coordinate = World::j_ant_coordinate;
      } else if (World::ant_position == "v") { 
            World::ant_position = "<";
            World::i_ant_coordinate = World::i_ant_coordinate;
            World::j_ant_coordinate = World::j_ant_coordinate - 1;
      }
   }

   return World::Limit_Condition();
*/