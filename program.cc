/**@mainpage
 
  PRO2 Lab Project
  Xavier Gordillo Ramos
  Subgroup 21

 
 */

/** @file main.cc
 @brief Main program
 */


#include "Idiom_Set.hh"

#ifndef NO_DIAGRAM
//#include <iostream> //iostream ya esta incluido en idioma.hh
#include "BinTree.hh"
#endif

/** @brief Main program for the exercise */
int main(){

    Idiom_Set idiom_set = Idiom_Set();
    std::string input_string;
    int n;
    std::cin >> n;
    for(int i = 0; i<n; ++i)idiom_set.add_idiom(true);
    while(std::cin >> input_string && input_string != "fin"){
        
        if(input_string == "anadir/modificar")idiom_set.add_idiom(false);
        else if(input_string == "tabla_frec")idiom_set.write_frequency_table();
        else if(input_string == "treecode")idiom_set.write_treecode();
        else if(input_string == "codigos")idiom_set.write_codes();
        else if(input_string == "codifica")idiom_set.encode();
        else if(input_string == "decodifica")idiom_set.decode();

    } 
} 
