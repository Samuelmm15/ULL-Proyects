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
            cout << "x" << " ";
         }
         if (Finite_World::the_mesh[i][j] == 1) {
            cout << " " << " ";
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
            cout << "x" << " ";
         }
         if (Infinite_World::the_mesh[i][j] == 1) {
            cout << " " << " ";
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

void Ant::Ant_Generator(list<Ant> &ant_list) { 

   list<Ant>::iterator p = ant_list.begin(); /// The iterator of the ant list
   while (p != ant_list.end()) {
      cout << "Introduzca las coordenadas donde quiere que comience la hormiga, debe de introducir los valores de i y de j de la manera (i j): ";
      cin >> p->i_coordinate;
      cin >> p->j_coordinate;
      cout << "A continuación introduzca la dirección a la que quiere que apunte la hormiga al comenzar: ";
      cin >> p->posititon;

      int flag = 0;
      for (int j = 0; j < 3; j++) {
         flag++;
         if (flag == 1) {
            p->ant[j] = p->i_coordinate;
         } else if (flag == 2) {
            p->ant[j] = p->j_coordinate;
         } else if (flag == 3) {
         p->ant[j] = p->posititon;
         }
      }
      p++; /// The next node
   }
}; 


void Ant::Ant_Turn(list<Ant> &ant_list, int const ant_option, Finite_World &F, Infinite_World &I) {

   list<Ant>::iterator p = ant_list.begin(); /// The iterator of the ant list

   if ((ant_option == 1) || (ant_option == 2)) {
      while (p != ant_list.end()) {

      istringstream convert(p->i_coordinate); /// To convert a string to an int
      if (!(convert >> p->i_coordinate_value)) {
         p->i_coordinate_value = 0;
      } /// Here is the converted number

      istringstream convert1(p->j_coordinate); /// To convert a string to an int
      if (!(convert1 >> p->j_coordinate_value)) {
         p->j_coordinate_value = 0;
      } /// Here is the converted number

      if ((F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 1) || (I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 1)) { 
      F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] = 0; /// The updates of the colours of the meshes 
      I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] = 0;
      if (p->posititon == ">") {
         p->posititon_aux = "/";  
      } else if (p->posititon == "/") {
         p->posititon_aux = "^";
      } else if (p->posititon == "^") {
         p->posititon_aux = "`";
      } else if (p->posititon == "`") {
         p->posititon_aux = "<";
      } else if (p->posititon == "<") {
         p->posititon_aux = "%";
      } else if (p->posititon == "%") {
         p->posititon_aux = "v";
      } else if (p->posititon == "v") {
         p->posititon_aux = "¬";
      } else if (p->posititon == "¬") {
         p->posititon_aux = ">";
      }
      } else if ((F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 0) || (I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 0)) {
      F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] = 1;
      I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] = 1;  
      if (p->posititon == ">") {
         p->posititon_aux = "¬";  
      } else if (p->posititon == "¬") {
         p->posititon_aux = "v";
      } else if (p->posititon == "v") {
         p->posititon_aux = "%";
      } else if (p->posititon == "%") { 
         p->posititon_aux = "<";
      } else if (p->posititon == "<") {
         p->posititon_aux = "`";
      } else if (p->posititon == "`") {
         p->posititon_aux = "^";
      } else if (p->posititon == "^") {
         p->posititon_aux = "/";
      } else if (p->posititon == "/") {
         p->posititon_aux = ">";
         }
      } 
      p->posititon = p->posititon_aux;
      p++; /// The next node of the list
      } 
   } 
};

void Ant::Ant_Move(list<Ant> &ant_list, int const ant_option, Finite_World &F, Infinite_World &I) {

   list<Ant>::iterator p = ant_list.begin(); /// The iterator of the list

   if (ant_option == 1) { /// The lagton ant

      while (p != ant_list.end()) {

      istringstream convert(p->i_coordinate); /// To convert a string to an int
      if (!(convert >> p->i_coordinate_value)) {
         p->i_coordinate_value = 0;
      } /// Here is the converted number

      istringstream convert1(p->j_coordinate); /// To convert a string to an int
      if (!(convert1 >> p->j_coordinate_value)) {
         p->j_coordinate_value = 0;
      } /// Here is the converted number

      if ((F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 1) || (I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 1)) { 
         if (p->posititon == ">") { 
            p->i_coordinate_value = p->i_coordinate_value; 
            p->j_coordinate_value = p->j_coordinate_value + 1;
         } else if (p->posititon == "/") {
            p->i_coordinate_value = p->i_coordinate_value - 1;
            p->j_coordinate_value = p->j_coordinate_value + 1;
         } else if (p->posititon == "^") {
            p->i_coordinate_value = p->i_coordinate_value - 1;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "`") {
            p->i_coordinate_value = p->i_coordinate_value - 1;
            p->j_coordinate_value = p->j_coordinate_value - 1;
         } else if (p->posititon == "<") {
            p->i_coordinate_value = p->i_coordinate_value;
            p->j_coordinate_value = p->j_coordinate_value - 1;
         } else if (p->posititon == "%") {
            p->i_coordinate_value = p->i_coordinate_value + 1;
            p->j_coordinate_value = p->j_coordinate_value - 1;
         } else if (p->posititon == "v") {
            p->i_coordinate_value = p->i_coordinate_value + 1;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "¬") {
            p->i_coordinate_value = p->i_coordinate_value + 1;
            p->j_coordinate_value = p->j_coordinate_value + 1;
         }
      } else if ((F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 0) || (I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 0)) { 
         if (p->posititon == ">") {
            p->i_coordinate_value = p->i_coordinate_value; 
            p->j_coordinate_value = p->j_coordinate_value + 1;
         } else if (p->posititon == "¬") {
            p->i_coordinate_value = p->i_coordinate_value + 1;
            p->j_coordinate_value = p->j_coordinate_value + 1;
         } else if (p->posititon == "v") {
            p->i_coordinate_value = p->i_coordinate_value + 1;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "%") { 
            p->i_coordinate_value = p->i_coordinate_value + 1;
            p->j_coordinate_value = p->j_coordinate_value - 1;
         } else if (p->posititon == "<") {
            p->i_coordinate_value = p->i_coordinate_value;
            p->j_coordinate_value = p->j_coordinate_value - 1;
         } else if (p->posititon == "`") {
            p->i_coordinate_value = p->i_coordinate_value - 1;
            p->j_coordinate_value = p->j_coordinate_value - 1;
         } else if (p->posititon == "^") {
            p->i_coordinate_value = p->i_coordinate_value - 1;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "/") {
            p->i_coordinate_value = p->i_coordinate_value - 1;
            p->j_coordinate_value = p->j_coordinate_value + 1;
         }
      }

      /// The update of the values of the ant
      int flag = 0;
      for (int i = 0; i < 3; i++) {
         flag++;
         if (flag == 1) {
            ostringstream reconvert_i;
            reconvert_i << p->i_coordinate_value;
            p->i_coordinate = reconvert_i.str(); /// Now the int value is converted into a string

            p->ant[i] = p->i_coordinate;
         } else if (flag == 2) {
            ostringstream reconvert_j;
            reconvert_j << p->j_coordinate_value;
            p->j_coordinate = reconvert_j.str(); /// Now the int value is converted into a string

            p->ant[i] = p->j_coordinate;
         } else if (flag == 3) {
            p->ant[i] = p->posititon;
         }
      }

      p++; /// The next node of the ant 
   }

   } else if (ant_option == 2) { /// The langton ant modified

      while (p != ant_list.end()) {

      istringstream convert(p->i_coordinate); /// To convert a string to an int
      if (!(convert >> p->i_coordinate_value)) {
         p->i_coordinate_value = 0;
      } /// Here is the converted number

      istringstream convert1(p->j_coordinate); /// To convert a string to an int
      if (!(convert1 >> p->j_coordinate_value)) {
         p->j_coordinate_value = 0;
      } /// Here is the converted number

      if ((F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 1) || (I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 1)) { 
         if (p->posititon == ">") { 
            p->i_coordinate_value = p->i_coordinate_value; 
            p->j_coordinate_value = p->j_coordinate_value + 2;
         } else if (p->posititon == "/") {
            p->i_coordinate_value = p->i_coordinate_value - 2;
            p->j_coordinate_value = p->j_coordinate_value + 2;
         } else if (p->posititon == "^") {
            p->i_coordinate_value = p->i_coordinate_value - 2;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "`") {
            p->i_coordinate_value = p->i_coordinate_value - 2;
            p->j_coordinate_value = p->j_coordinate_value - 2;
         } else if (p->posititon == "<") {
            p->i_coordinate_value = p->i_coordinate_value;
            p->j_coordinate_value = p->j_coordinate_value - 2;
         } else if (p->posititon == "%") {
            p->i_coordinate_value = p->i_coordinate_value + 2;
            p->j_coordinate_value = p->j_coordinate_value - 2;
         } else if (p->posititon == "v") {
            p->i_coordinate_value = p->i_coordinate_value + 2;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "¬") {
            p->i_coordinate_value = p->i_coordinate_value + 2;
            p->j_coordinate_value = p->j_coordinate_value + 2;
         }
      } else if ((F.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 0) || (I.the_mesh[p->i_coordinate_value][p->j_coordinate_value] == 0)) { 
         if (p->posititon == ">") {
            p->i_coordinate_value = p->i_coordinate_value; 
            p->j_coordinate_value = p->j_coordinate_value + 2;
         } else if (p->posititon == "¬") {
            p->i_coordinate_value = p->i_coordinate_value + 2;
            p->j_coordinate_value = p->j_coordinate_value + 2;
         } else if (p->posititon == "v") {
            p->i_coordinate_value = p->i_coordinate_value + 2;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "%") { 
            p->i_coordinate_value = p->i_coordinate_value + 2;
            p->j_coordinate_value = p->j_coordinate_value - 2;
         } else if (p->posititon == "<") {
            p->i_coordinate_value = p->i_coordinate_value;
            p->j_coordinate_value = p->j_coordinate_value - 2;
         } else if (p->posititon == "`") {
            p->i_coordinate_value = p->i_coordinate_value - 2;
            p->j_coordinate_value = p->j_coordinate_value - 2;
         } else if (p->posititon == "^") {
            p->i_coordinate_value = p->i_coordinate_value - 2;
            p->j_coordinate_value = p->j_coordinate_value;
         } else if (p->posititon == "/") {
            p->i_coordinate_value = p->i_coordinate_value - 2;
            p->j_coordinate_value = p->j_coordinate_value + 2;
         }
      }

      /// The update of the values of the ant
      int flag = 0;
      for (int i = 0; i < 3; i++) {
         flag++;
         if (flag == 1) {
            ostringstream reconvert_i;
            reconvert_i << p->i_coordinate_value;
            p->i_coordinate = reconvert_i.str(); /// Now the int value is converted into a string

            p->ant[i] = p->i_coordinate;
         } else if (flag == 2) {
            ostringstream reconvert_j;
            reconvert_j << p->j_coordinate_value;
            p->j_coordinate = reconvert_j.str(); /// Now the int value is converted into a string

            p->ant[i] = p->j_coordinate;
         } else if (flag == 3) {
            p->ant[i] = p->posititon;
         }
      }

      p++; /// The next node of the ant
   }
   }

};

void Ant::getTurn(list<Ant> &ant_list, int const ant_option, Finite_World &F, Infinite_World &I) {
   return Ant::Ant_Turn(ant_list, ant_option, F, I);
};

void Ant::getMove(list<Ant> &ant_list, int const ant_option, Finite_World &F, Infinite_World &I) {
   return Ant::Ant_Move(ant_list, ant_option, F, I);
};

void Ant::Ant_movement(list<Ant> &ant_list, int const ant_option, Finite_World &F, Infinite_World &I) {
   Ant::getTurn(ant_list, ant_option, F, I);
   Ant::getMove(ant_list, ant_option, F, I);
};

void Ant::Ant_Status_Representation(list<Ant> ant_list) {
   list<Ant>::iterator p = ant_list.begin();
   while (p != ant_list.end()) {
      for (int i = 0; i < 3; i++) {
         cout << p->ant[i] << " "; 
      }
      cout << endl;
      p++; 
   }
};

void Universe::ant_universe(int const option_world, int const ant_option, Finite_World &F, Infinite_World &I, Ant &A, Vector_World<int> &V, list<Ant> &ant_list) {

   if (option_world == 1) {
      F.World_Status_Finiteworld(); 
   do {
      A.Ant_movement(ant_list, ant_option,F,I); /// Here starts the game

      list<Ant>::iterator p = ant_list.begin();
      while (p != ant_list.end()) {
         F.i_ant_coordinate = p->i_coordinate_value;
         F.j_ant_coordinate = p->j_coordinate_value;
         F.ant_position = p->posititon;
         F.Limit_Condition_Finiteworld();
         p++;
      }
      
      F.World_Status_Finiteworld();
      A.Ant_Status_Representation(ant_list);

  } while (F.limit != 1);
    exit(1);

   } else if (option_world == 2) {

      I.World_Status_Infiteworld();
      int counter = 0; 
   
      do {
         A.Ant_movement(ant_list, ant_option,F,I); /// Here starts the game

         list<Ant>::iterator p = ant_list.begin();
         while (p != ant_list.end()) {
            I.i_ant_coordinate = p->i_coordinate_value;
            I.j_ant_coordinate = p->j_coordinate_value;
            I.ant_position = p->posititon;
            I.Limit_Condition_Infiteworld();
            p++;
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
      A.Ant_Status_Representation(ant_list);

      } while (I.limit != 1);
      exit(1);
   }  
};