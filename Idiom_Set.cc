/** 
 * @file Idiom_Set.cc
 * @breif Implementation of the Idiom_Set class
 */

#include "Idiom_Set.hh"

Idiom_Set::Idiom_Set(){
    std::map<std::string, Idiom> idiom_set;
}

// HACER FUNCION CONTAINS!!!!!!!!!!!!!!!!!!!

void Idiom_Set::write_treecode() const{
    std::string s;
    std::cin >> s;
    std::map<std::string,Idiom>::const_iterator it = idiom_set.find(s);
    if(it != idiom_set.end())it->second.write_treecode(s);
    else std::cout << "Treecode de " << s << ":\nEl idioma no existe\n\n";

} 

void Idiom_Set::write_codes() const{
    std::string s, ch;
    std::cin >> s >> ch;
    std::map<std::string,Idiom>::const_iterator it = idiom_set.find(s);
    if(it == idiom_set.end() and ch == "todos")std::cout << "Codigos de " << s << ":\nEl idioma no existe\n\n";
    else if(it == idiom_set.end())std::cout << "Codigo de " << ch << " en " << s << ":\nEl idioma no existe o el caracter no esta en el idioma\n\n";
    else {
        if(ch == "todos")std::cout << "Codigos de " << s << ":\n";
        else std::cout << "Codigo de " << ch << " en " << s << ":\n";
        it->second.write_codes(ch);
    } 

} 

void Idiom_Set::add_idiom(bool initial){
    std::string name;
    std::cin >> name;
    Idiom i;
    std::map<std::string,Idiom>::iterator it = idiom_set.find(name);
    if(it == idiom_set.end()){
        i.read_idiom();
        idiom_set.insert(std::pair<std::string,Idiom>(name,i));
    }else{
        it->second.modify_idiom();
        std::cout << "Modificado " << name << "\n\n";
        initial = true;
    }  
    if(not initial)std::cout << "Anadido " << name << "\n\n";
} 

void Idiom_Set::write_frequency_table(){
    std::string name;
    std::cin >> name;
    std::map<std::string,Idiom>::iterator it = idiom_set.find(name);
    if(it != idiom_set.end()){
        std::cout << "Tabla de frecuencias de " << name << ':' << std::endl;
        it->second.write_frequencies();
    } 
    else std::cout << "Tabla de frecuencias de " << name << ":\nEl idioma no existe\n\n";
} 

void Idiom_Set::encode(){
    std::string name, text;
    std::cin >> name >> text;
    std::map<std::string,Idiom>::iterator it = idiom_set.find(name);
    std::cout << "Codifica en " << name << " el texto:\n" << text << "\n";
    if(it == idiom_set.end()){
        std::cout << "El idioma no existe\n\n";
    }else{
        it->second.encode(text);
    }  
     
} 

void Idiom_Set::decode(){
    std::string name, text;
    std::cin >> name >> text;
    std::map<std::string,Idiom>::iterator it = idiom_set.find(name);
    std::cout << "Decodifica en " << name << " el texto:\n" << text << "\n";
    if(it == idiom_set.end()){
        std::cout << "El idioma no existe\n\n";
    }else{
        it->second.decode(text);
    }  
    
} 
