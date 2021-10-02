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
#include "langton_finiteworld.h"
#include "langton_infiniteworld.h"
#include "langton_ant.h"
#include "langton_vector.h"
#include "langton_universe.h"

void Finite_World::World_Generator_Finiteworld() {
       for (int i = Finite_World::i_ini_min_world; i < Finite_World::i_ini_max_world; i++) {
         for (int j = Finite_World::j_ini_min_world; j < Finite_World::j_ini_max_world; j++) {
            Finite_World::the_mesh[i][j] = 0;  
         }
      }
};

void Finite_World::World_Status_Finiteworld() { 
   for (int i = Finite_World::i_ini_min_world; i < Finite_World::i_ini_max_world; i++) {        
      for (int j = Finite_World::j_ini_min_world; j < Finite_World::j_ini_max_world; j++) {
         if (Finite_World::the_mesh[i][j] == 0) {
            cout << " " << " ";
         }
         if (Finite_World::the_mesh[i][j] == 1) {
            cout << "x" << " ";
         }
      }
      cout << "\n";
   }  
   cout << endl;
};

void Finite_World::Limit_Condition_Finiteworld() { 
   if (((Finite_World::i_ant_coordinate == Finite_World::i_ini_min_world - 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_min_world)) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_min_world - 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_min_world - 1)) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_min_world) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_min_world - 1))) { 
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl;
         Finite_World::limit = 1;
      } else if ((Finite_World::i_ant_coordinate == Finite_World::i_ini_max_world) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_min_world - 1) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_max_world + 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_min_world - 1)) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_max_world + 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_min_world))) { 
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl;
         Finite_World::limit = 1;
      } else if ((Finite_World::i_ant_coordinate == Finite_World::i_ini_max_world + 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_max_world) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_max_world + 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_max_world + 1)) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_max_world) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_max_world + 1))) { 
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl; 
         Finite_World::limit = 1;
      } else if ((Finite_World::i_ant_coordinate == Finite_World::i_ini_min_world) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_max_world + 1) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_min_world - 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_max_world + 1)) || ((Finite_World::i_ant_coordinate == Finite_World::i_ini_min_world - 1) && (Finite_World::j_ant_coordinate == Finite_World::j_ini_max_world))) { 
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl;
         Finite_World::limit = 1;
      } else if (Finite_World::i_ant_coordinate == Finite_World::i_ini_min_world - 1) {
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl;
         Finite_World::limit = 1;
      } else if (Finite_World::j_ant_coordinate == Finite_World::j_ini_min_world - 1) {
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl;
         Finite_World::limit = 1;
      } else if (Finite_World::i_ant_coordinate == Finite_World::i_ini_max_world + 1) {
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl;
         Finite_World::limit = 1;
      } else if (Finite_World::j_ant_coordinate == Finite_World::j_ini_max_world + 1) {
         cout << "EL JUEGO HA FINALIZADO" << endl;
         cout << "La hormiga ha alcanzado el límite de la malla" << endl;
         Finite_World::limit = 1;
      }
};

void Infinite_World::World_Generator_Infiteworld() {
  for (int i = Infinite_World::i_ini_min_world; i < Infinite_World::i_ini_max_world; i++) {
       for (int j = Infinite_World::j_ini_min_world; j < Infinite_World::j_ini_max_world; j++) {
            Infinite_World::the_mesh[i][j] = 0;  
       }
    }
};

void Infinite_World::World_Status_Infiteworld() { 
   for (int i = Infinite_World::i_ini_min_world; i < Infinite_World::i_ini_max_world; i++) {        
      for (int j = Infinite_World::j_ini_min_world; j < Infinite_World::j_ini_max_world; j++) {
         if (Infinite_World::the_mesh[i][j] == 0) {
            cout << " " << " ";
         }
         if (Infinite_World::the_mesh[i][j] == 1) {
            cout << "x" << " ";
         }
      }
      cout << "\n";
   }  
   cout << endl;
};

void Infinite_World::Limit_Condition_Infiteworld() { 
   if (((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_min_world - 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_min_world)) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_min_world - 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_min_world - 1)) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_min_world) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_min_world - 1))) { 
         if (Infinite_World::ant_position == "^") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 1;
         } else if (Infinite_World::ant_position == "<") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 2;
         } else if (Infinite_World::ant_position == "`") {
            Infinite_World::resize1 = 0;
            Infinite_World::resize1 = 1;
         }
      } else if ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_max_world) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_min_world - 1) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_max_world + 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_min_world - 1)) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_max_world + 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_min_world))) { 
         if (Infinite_World::ant_position == "<") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 2;
         } else if (Infinite_World::ant_position == "v") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 3;
         } else if (Infinite_World::ant_position == "%") {
            Infinite_World::resize1 = 0;
            Infinite_World::resize1 = 2;
         }
      } else if ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_max_world + 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_max_world) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_max_world + 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_max_world + 1)) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_max_world) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_max_world + 1))) { 
          if (Infinite_World::ant_position == "v") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 3;
         } else if (Infinite_World::ant_position == ">") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 4;
         } else if (Infinite_World::ant_position == "¬") {
            Infinite_World::resize1 = 0;
            Infinite_World::resize1 = 3;
         }
      } else if ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_min_world) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_max_world + 1) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_min_world - 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_max_world + 1)) || ((Infinite_World::i_ant_coordinate == Infinite_World::i_ini_min_world - 1) && (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_max_world))) { 
         if (Infinite_World::ant_position == "^") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 1;
         } else if (Infinite_World::ant_position == ">") {
            Infinite_World::resize = 0;
            Infinite_World::resize = 4;
         } else if (Infinite_World::ant_position == "/") {
            Infinite_World::resize1 = 0;
            Infinite_World::resize1 = 4;
         }
      } else if (Infinite_World::i_ant_coordinate == Infinite_World::i_ini_min_world - 1) {
         Infinite_World::resize = 0; 
         Infinite_World::resize = 1;
      } else if (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_min_world - 1) {
         Infinite_World::resize = 0; 
         Infinite_World::resize = 2;
      } else if (Infinite_World::i_ant_coordinate == Infinite_World::i_ini_max_world + 1) {
         Infinite_World::resize = 0; 
         Infinite_World::resize = 3;
      } else if (Infinite_World::j_ant_coordinate == Infinite_World::j_ini_max_world + 1) {
         Infinite_World::resize = 0; 
         Infinite_World::resize = 4;
      
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


void Ant::Ant_Turn() {
   int flag = 0;
   int aux_i_min = 0;
   int aux_i_max = 0;
   for (int i = 0; i < Ant::Ant_List.size(); i++) {
      flag++; 
      if (flag == 1) {
         Ant::i_coordinate = Ant::Ant_List.at(i);

         istringstream convert(Ant::i_coordinate); /// To convert a string to an int
         if (!(convert >> Ant::i_coordinate_value)) {
         Ant::i_coordinate_value = 0;
         } /// Here is the converted number
         aux_i_max++; 
      } else if (flag == 2) {
         Ant::j_coordinate = Ant::Ant_List.at(i);

         istringstream convert1(Ant::j_coordinate); /// To convert a string to an int
         if (!(convert1 >> Ant::j_coordinate_value)) {
         Ant::j_coordinate_value = 0;
         } /// Here is the converted number
         aux_i_max++; 
      } else if (flag == 3) {
         Ant::posititon = Ant::Ant_List.at(i);

         if (the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 0) { 
            if (Ant::posititon == ">") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "/";  
            } else if (Ant::posititon == "/") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "^";
            } else if (Ant::posititon == "^") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "`";
            } else if (Ant::posititon == "`") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "<";
            } else if (Ant::posititon == "<") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "%";
            } else if (Ant::posititon == "%") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "v";
            } else if (Ant::posititon == "V") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "¬";
            } else if (Ant::posititon == "¬") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = ">";
            }
         } else if (Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 1) {  
            if (Ant::posititon == ">") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "¬";  
            } else if (Ant::posititon == "¬") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "v";
            } else if (Ant::posititon == "v") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "%";
            } else if (Ant::posititon == "%") { 
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "<";
            } else if (Ant::posititon == "<") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "`";
            } else if (Ant::posititon == "`") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "^";
            } else if (Ant::posititon == "^") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = "/";
            } else if (Ant::posititon == "/") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon_aux = ">";
            }
         } 

         flag = 0;
         aux_i_max++; 
         Ant::posititon = Ant::posititon_aux;
   
         for (int j = aux_i_min; j < aux_i_max; j++) {
            if (j == aux_i_min) {
               ostringstream reconvert_i;
               reconvert_i << Ant::i_coordinate_value;
               Ant::i_coordinate = reconvert_i.str(); /// Now the int value is converted into a string

               Ant::Ant_List.at(j) = Ant::i_coordinate; 
            } else if (j == (aux_i_min + 1)) {
               ostringstream reconvert_j;
               reconvert_j << Ant::j_coordinate_value;
               Ant::j_coordinate = reconvert_j.str(); /// Now the int value is converted into a string

               Ant::Ant_List.at(j) = Ant::j_coordinate; 
            } else if (j == (aux_i_min + 2)) {
               Ant::Ant_List.at(j) = Ant::posititon; 
            } 
            aux_i_min = aux_i_max;
         }

      }
   }
};

void Ant::Ant_Move() {
   int flag = 0;
   int aux_i_min = 0;
   int aux_i_max = 0;
   for (int i = 0; i < Ant::Ant_List.size(); i++) {
      flag++;
      if (flag == 1) {
         Ant::i_coordinate = Ant::Ant_List.at(i);

         istringstream convert(Ant::i_coordinate); /// To convert a string to an int
         if (!(convert >> Ant::i_coordinate_value)) {
         Ant::i_coordinate_value = 0;
         } /// Here is the converted number
         aux_i_max++; 
      } else if (flag == 2) {
         Ant::j_coordinate = Ant::Ant_List.at(i);

         istringstream convert1(Ant::j_coordinate); /// To convert a string to an int
         if (!(convert1 >> Ant::j_coordinate_value)) {
         Ant::j_coordinate_value = 0;
         } /// Here is the converted number
         aux_i_max++; 
      } else if (flag == 3) {
         Ant::posititon = Ant::Ant_List.at(i);

         if (the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 0) { 
            Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] = 1;
            if (Ant::posititon == ">") { 
               Ant::i_coordinate_value = Ant::i_coordinate_value; 
               Ant::j_coordinate_value  = Ant::j_coordinate_value + 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "/") {
               Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "^") {
               Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "`") {
               Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "<") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "%") {
               Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "V") {
               Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "¬") {
               Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
            }
         } else if (Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] == 1) {  
            Ant::the_mesh_copy[Ant::i_coordinate_value][Ant::j_coordinate_value] = 0;
            if (Ant::posititon == ">") {
               Ant::i_coordinate_value = Ant::i_coordinate_value; 
               Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "¬") {
               Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "v") {
               Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "%") { 
               Ant::i_coordinate_value = Ant::i_coordinate_value + 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "<") {
               Ant::i_coordinate_value = Ant::i_coordinate_value;
               Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "`") {
               Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value - 1;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "^") {
               Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value;
               Ant::posititon = Ant::posititon;
            } else if (Ant::posititon == "/") {
               Ant::i_coordinate_value = Ant::i_coordinate_value - 1;
               Ant::j_coordinate_value = Ant::j_coordinate_value + 1;
               Ant::posititon = Ant::posititon;
            }
         } 
         aux_i_max++;

      /// Actualización de los valores de la lista
      for (int j = aux_i_min; j < aux_i_max; j++) { /// At this point the list values are changed 
         if (j == aux_i_min) {
            ostringstream reconvert_i;
            reconvert_i << Ant::i_coordinate_value;
            Ant::i_coordinate = reconvert_i.str(); /// Now the int value is converted into a string

            Ant::Ant_List.at(j) = Ant::i_coordinate;
         } else if (j == (aux_i_min + 1)) {
            ostringstream reconvert_j;
            reconvert_j << Ant::j_coordinate_value;
            Ant::j_coordinate = reconvert_j.str(); /// Now the int value is converted into a string

            Ant::Ant_List.at(j) = Ant::j_coordinate;
         } else if (j == (aux_i_min + 2)) {
            Ant::Ant_List.at(j) = Ant::posititon;
         } 
         aux_i_min = aux_i_max;
      }
      flag = 0;
      }
   }
};

void Ant::getTurn() {
   return Ant::Ant_Turn();
};

void Ant::getMove() {
   return Ant::Ant_Move();
};

void Ant::Ant_movement() {
   Ant::getMove();
   Ant::getTurn();
};

void Ant::Ant_Status_Representation() {
   int flag = 0;
   for (int i = 0; i < Ant::Ant_List.size(); i++) {
      flag++;
      cout << Ant::Ant_List.at(i) << " ";
      if (flag == 3) {
         cout << endl;
         flag = 0;
      }
   }
};

void Universe::ant_universe(int option_world) {
   Finite_World F;
   Infinite_World I;
   Ant A;
   Vector_World <int> V;

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

      F.World_Generator_Finiteworld(); 

      cout << "Ahora introduzca el número de hormigas que quiere incluir dentro del programa: ";
      cin >> A.num_of_ants;

      do {
         A.Ant_Generator(); 
         for (int n = 0; n < 3; n++) {
            A.Ant_List.push_back(A.ant[n]); 
            }
         A.num_of_ants--;
      } while(A.num_of_ants != 0);

      F.World_Status_Finiteworld(); 


      for (int i = V.i_ini_min; i < V.i_ini_max; i++) { 
      for (int j = V.j_ini_min; j < V.j_ini_max; j++) {
         A.the_mesh_copy[i][j] = F.the_mesh[i][j]; 
      }
   }
   
   do {
      A.Ant_movement(); /// Here starts the game

      int flag = 0;
      for (int i = 0; i < A.Ant_List.size(); i++) {
         flag++; /// aumentamos el valor de flag
         if (flag == 1) {
            A.i_coordinate = A.Ant_List.at(i);

            istringstream convert(A.i_coordinate); /// To convert a string to an int
            if (!(convert >> A.i_coordinate_value)) {
               A.i_coordinate_value = 0;
            } /// Here is the converted number
            F.i_ant_coordinate = A.i_coordinate_value;  
         } else if (flag == 2) {
            A.j_coordinate = A.Ant_List.at(i);

            istringstream convert1(A.j_coordinate); /// To convert a string to an int
            if (!(convert1 >> A.j_coordinate_value)) {
               A.j_coordinate_value = 0;
            } /// Here is the converted number
            F.j_ant_coordinate = A.j_coordinate_value; 
         } else if (flag == 3) {
            A.posititon = A.Ant_List.at(i);
            F.ant_position = A.posititon;
            F.Limit_Condition_Finiteworld(); 
            flag = 0;
         }
      }

      for (int i = V.i_ini_min; i < V.i_ini_max; i++) {
         for (int j = V.j_ini_min; j < V.j_ini_max; j++) {
            F.the_mesh[i][j] = A.the_mesh_copy[i][j];
         }
      }
      
      F.World_Status_Finiteworld();
      A.Ant_Status_Representation();

  } while (F.limit != 1);
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

      I.World_Generator_Infiteworld();

      cout << "Ahora introduzca el número de hormigas que quiere incluir dentro del programa: ";
      cin >> A.num_of_ants;

      do {
         A.Ant_Generator(); 
         for (int n = 0; n < 3; n++) {
            A.Ant_List.push_back(A.ant[n]);
            }
         A.num_of_ants--;
      } while(A.num_of_ants != 0);

      I.World_Status_Infiteworld(); 

      for (int i = V.i_ini_min; i < V.i_ini_max; i++) { 
      for (int j = V.j_ini_min; j < V.j_ini_max; j++) {
         A.the_mesh_copy[i][j] = I.the_mesh[i][j]; 
      }
   }

   int counter = 0;
   
   do {
      A.Ant_movement(); /// Here starts the game

      int flag = 0;
      for (int i = 0; i < A.Ant_List.size(); i++) {
         flag++; /// aumentamos el valor de flag
         if (flag == 1) {
            A.i_coordinate = A.Ant_List.at(i);

            istringstream convert(A.i_coordinate); /// To convert a string to an int
            if (!(convert >> A.i_coordinate_value)) {
               A.i_coordinate_value = 0;
            } /// Here is the converted number
            I.i_ant_coordinate = A.i_coordinate_value;  
         } else if (flag == 2) {
            A.j_coordinate = A.Ant_List.at(i);

            istringstream convert1(A.j_coordinate); /// To convert a string to an int
            if (!(convert1 >> A.j_coordinate_value)) {
               A.j_coordinate_value = 0;
            } /// Here is the converted number
            I.j_ant_coordinate = A.j_coordinate_value; 
         } else if (flag == 3) {
            A.posititon = A.Ant_List.at(i);
            I.ant_position = A.posititon;
            I.Limit_Condition_Infiteworld(); 
            flag = 0;
         }
      }

      for (int i = V.i_ini_min; i < V.i_ini_max; i++) {
         for (int j = V.j_ini_min; j < V.j_ini_max; j++) {
            I.the_mesh[i][j] = A.the_mesh_copy[i][j];
         }
      }

      if (I.resize | I.resize1 == 1 | 2 | 3 | 4) { 
         V.aux = I.resize;
         V.aux1 = I.resize1;

         V.Mesh_Resize();

         I.resize = 0; 
         I.resize1 = 0;

         I.i_ini_min_world = V.i_ini_min;
         I.j_ini_max_world = V.i_ini_max;
         I.j_ini_min_world = V.j_ini_min;
         I.j_ini_max_world = V.j_ini_max;

      }

      counter++;

      if (counter == 20) {
         cout << endl;
         cout << "¿ DESEA FINALIZAR LA EJECUCIÓN DEL JUEGO ?" << endl;
         int option;
         cout << "SI LO DESEA PULSE 1, SI DESEA QUE NO 0 : ";
         cin >> option;

         if (option == 1) {
            I.limit = 1;
         } else if (option == 0) {
            counter = 0;
         }
      }

      I.World_Status_Infiteworld();
      A.Ant_Status_Representation();

  } while (I.limit != 1);
    exit(1);

   }

   
};

/// LA MODIFICACIÓN NO FUNCIONA, PERO ESTA FUE MI IMPLEMENTACIÓN
/*
   /// La operación de comprobacion de si una hormiga está delante de otra se debe de hacer antes de la actualización de los valores para comprobar
      int flag1 = 0;
      int position_counter = 0; /// This the counter of the position counter of the ants
      int position_i_aux = 0;
      for (int i = 0; i < Ant::Ant_List.size(); i++) {
         if (i == flag1) {
            ostringstream reconvert_i;
            reconvert_i << Ant::i_coordinate_value;
            Ant::i_coordinate = reconvert_i.str(); /// Now the int value is converted into a string

            if (position_i_aux == 0) {
               position_i_aux = Ant::i_coordinate_value;
            } else if (position_i_aux != 0) {
               if (position_i_aux < Ant::i_coordinate_value) {
                  position_counter++;
                  position_i_aux = Ant::i_coordinate_value;
               } else if (position_i_aux > Ant::i_coordinate_value) {
                  position_counter++;
                  position_i_aux = Ant::i_coordinate_value;
               }
            }
            flag1 = flag1 + 3;
         }
      }
*/