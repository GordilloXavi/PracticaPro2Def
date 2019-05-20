/** @file Treecode.cc
 * @brief Implementation of the Treecode Class
 */


#include "Treecode.hh"

Treecode::Treecode() {
    BinTree<std::pair<std::string,int>> tree;
    std::map<std::string,int> frequencies;
    std::map<std::string,std::string> codes;
}

bool operator<(const BinTree<std::pair<std::string,int>>& t1, const BinTree<std::pair<std::string,int>>& t2){
    return t1.value().second < t2.value().second or (t1.value().second == t2.value().second and t1.value().first < t2.value().first);
} 



void Treecode::make_treecode() {
    std::set<BinTree<std::pair<std::string,int>>> s;
    std::map<std::string,int>::iterator it = frequencies.begin();

    while(it != frequencies.end()){
        s.insert(BinTree<std::pair<std::string,int>>(std::pair<std::string,int>(*it)));
        ++it;
    } 

    while(s.size()>1){
        BinTree<std::pair<std::string,int>> aux1 = *(s.begin());
        s.erase(s.begin());
        BinTree<std::pair<std::string,int>> aux2 = *(s.begin());
        s.erase(s.begin());
        BinTree<std::pair<std::string,int>> t2;
        if(aux1.value().first < aux2.value().first)t2 = BinTree<std::pair<std::string,int>>(std::pair<std::string,int>(aux1.value().first+aux2.value().first, aux1.value().second + aux2.value().second), aux1, aux2);
        else t2 = BinTree<std::pair<std::string,int>>(std::pair<std::string,int>(aux2.value().first+aux1.value().first, aux1.value().second + aux2.value().second), aux1, aux2);
        s.insert(t2);
    } 

    tree = *(s.begin());
} 

void Treecode::read_frequency_table(){
    int n, x;
    std::string s;
    std::cin >> n;
    for(int i = 0; i<n; ++i){
        std::cin >> s >> x;
        frequencies.insert(std::pair<std::string,int>(s, x));
    } 
} 

void Treecode::write_frequencies(){
    std::map<std::string,int>::const_iterator it = frequencies.begin();
    while(it != frequencies.end()){
        std::cout << it->first << ' ' << it->second << std::endl;
        ++it;
    } 
    std::cout << std::endl;
} 


void Treecode::write_treecode(const std::string& id) const{
    std::cout << "Treecode de " << id << ":\nrecorrido en preorden:" << std::endl;
    Treecode::write_treecode_pre(tree);
    std::cout << "recorrido en inorden:" << std::endl;
    Treecode::write_treecode_in(tree);
    std::cout << std::endl;
} 

void Treecode::write_treecode_pre(const BinTree<std::pair<std::string,int>>& t) {
    
    if(not t.empty()){
        std::cout << t.value().first << ' ' << t.value().second << std::endl;
        if(not(t.left().empty() or t.right().empty())){
            if(t.left().value().second < t.right().value().second or (t.left().value().second == t.right().value().second and t.left().value().first < t.right().value().first)){
                write_treecode_pre(t.left());
                write_treecode_pre(t.right());
            }else{
                write_treecode_pre(t.right());
                write_treecode_pre(t.left());
            }  
        }
    } 

} 

void Treecode::write_treecode_in(const BinTree<std::pair<std::string,int>>& t) {

    if(not t.empty()){
        if(not(t.left().empty() or t.right().empty())){
            if(t.left().value().second < t.right().value().second or (t.left().value().second == t.right().value().second and t.left().value().first < t.right().value().first)){
                write_treecode_in(t.left());
                std::cout << t.value().first << ' ' << t.value().second << std::endl;
                write_treecode_in(t.right());
            }else{
                write_treecode_in(t.right());
                std::cout << t.value().first << ' ' << t.value().second << std::endl;
                write_treecode_in(t.left());
            }  
        }else{
            std::cout << t.value().first << ' ' << t.value().second << std::endl;
        } 
    } 

} 

void Treecode::write_codes(const std::string& ch) const{
    if(ch == "todos"){
        std::map<std::string,std::string>::const_iterator it;
        for(it = codes.begin(); it != codes.end(); ++it){
            std::cout << it->first << " " << it->second << std::endl;
        }std::cout << std::endl; 
        
    }else{
        std::map<std::string,std::string>::const_iterator it = codes.find(ch);
        if(it == codes.end())std::cout << "El idioma no existe o el caracter no esta en el idioma\n\n";
        else std::cout << it->first << " " << it->second << "\n\n";
    }  
} 

void Treecode::make_codes(){
    std::string s = "";
    codes = std::map<std::string,std::string>();
    generate_codes(tree, s);
} 

void Treecode::generate_codes(const BinTree<std::pair<std::string,int>>& t, std::string s){
       if(t.right().empty() and t.left().empty()){
            codes.insert(std::pair<std::string,std::string>(t.value().first, s));
       } else{
           generate_codes(t.left(), s+"0");
           generate_codes(t.right(), s+"1");
       }  
}  


void Treecode::next_symbol(const std::string& s, int& i, std::string& out){
    if (s[i]>=0) {out = std::string(1, s[i]); ++i;}
    else {out = std::string(s, i, 2); i+=2;}
} 

void Treecode::encode(std::string& txt) const{
    std::string s;
    int sz = txt.length();
    int i = 0;
    std::string res;
    std::map<std::string,std::string>::const_iterator it;
    while(i<sz){
       next_symbol(txt,i,s); 
        it = codes.find(s);
        if(it == codes.end()){
            std::cout << "El texto no pertenece al idioma; primer caracter que falla: " << s;
            break;
        }else{
            res+=(*it).second;
        }  
    } 
    if(it != codes.end())std::cout << res;
    std::cout << "\n\n";
} 


void Treecode::decode(std::string& txt){

    int sz = txt.length();
    BinTree<std::pair<std::string,int>> t(tree.value(), tree.left(), tree.right());
    std::string res = "";
    int i, last_pos = 0;
    for(i = 0; i<=sz; ){ //i<=sz
       if(t.left().empty() or t.right().empty()){
            res.append(t.value().first);
            t = BinTree<std::pair<std::string,int>>(tree.value(), tree.left(),tree.right());
            last_pos = i;
            if(i == sz)break;
       } else if(i == sz)break;
       else if(txt[i] == '0'){
            if(t.left().value().second < t.right().value().second or (t.left().value().second == t.right().value().second and t.left().value().first < t.right().value().first)){
            t = t.left();
            }else t = t.right();
            ++i;
       } else {
            if(t.left().value().second < t.right().value().second or (t.left().value().second == t.right().value().second and t.left().value().first < t.right().value().first)){
            t = t.right();
            }else t = t.left();
           ++i;
       }  
    } 
    if(tree.value().first != t.value().first)std::cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << last_pos << "\n\n";
    else std::cout << res << "\n\n";

} 

void Treecode::modify_frequency_table(){
    int n, x;
    std::string s;
    std::cin >> n;
    frequencies = std::map<std::string,int>(frequencies);
    for(int i = 0; i<n; ++i){
        std::cin >> s >> x;
        std::map<std::string,int>::iterator it = frequencies.find(s);
        if(it != frequencies.end()){
            it->second += x;
        }else{
            frequencies.insert(std::pair<std::string,int>(s,x));
        }  
    } 
}  
