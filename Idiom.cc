/**
 * @file Idiom.cc
 * @brief Implementation of the Idiom class
 */

#include "Idiom.hh"

Idiom::Idiom(){
   Treecode tree;
}

void Idiom::read_idiom(){
    tree.read_frequency_table();
    tree.make_treecode();
    tree.make_codes();
} 

void Idiom::modify_idiom(){
    tree.modify_frequency_table();
    tree.make_treecode();
    tree.make_codes();
} 

void Idiom::write_frequencies() const{
    tree.write_frequencies();
} 

void Idiom::write_treecode(const std::string& s) const{
    tree.write_treecode(s);
} 


void Idiom::write_codes(const std::string& ch) const{
    tree.write_codes(ch);
} 

void Idiom::encode(std::string& txt) const{
    tree.encode(txt);
} 

void Idiom::decode(std::string& txt) const{
    std::string s = txt;    
    tree.decode(s);
} 
