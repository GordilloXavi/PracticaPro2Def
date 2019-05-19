/** @file Idiom_Set.hh
    @brief Specifiction for the Idiom_Set class
 */

#ifndef _IDIOM_SET_HH_
#define _IDIOM_SET_HH_

#include "Idiom.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif


/** @class Idiom_Set
 * @brief This class is used to store and acess multiple Idioms.
 *
 * This class contains a map what will allow us to store and acess our Idioms in an efficient way.
 * If we try to acess an Idiom that does not exist, the class will handle that case.
 */

class Idiom_Set {

    private:
        /** @brief The data structure used to store and acess Idiom objects. */
        std::map<std::string, Idiom> idiom_set;

    public:


        /** @brief Default constructor
         * @pre True
         * @post Returns an empty Idiom (empty tree, frequency table and codes)
         * @coste Constant
         * */
        Idiom_Set();
        
        /** @brief Reads and adds an Idiom to the set
         * @pre There is a String S an integer N followed by N pairs of string,int waiting in the standard input channel
         * @post The set contains the new idiom S
         * @coste Linear in relation to N
         */
        void add_idiom(bool initial);


        /** @brief Prints to the standard output channel the encoded version of a String
         * @pre There are two Strings Name, Text waiting in the standard input channel
         * @post If the Idiom Name is in the set and the String Text can be encoded in this idiom, the encoded version of the string is printed to the standard output channel. Otherwise, an error message is printed. 
         * @coste O( N*log(N) ), where N is the length of Text 
         * */
        void encode();


        /** @brief Prints to the standard output channel the decoded version of a String
         * @pre There are two Strings Name, Text waiting in the standard input channel
         * @post If the Idiom Name is in the set and the String Text can be decoded in this idiom, the decoded version of the string is printed to the standard output channel. Otherwise, an error message is printed. 
         * @coste O( N ), where N is the length of Text 
         * */
        void decode();


        /** @brief Writes the frequency table to the standard output channel 
         * @pre There is a String Name waiting in the standard input channel 
         * @post If the Idiom Name is in the set, the frequency table has been written to the standard output channel. Otherwise, an error message is printed. 
         * @coste Linear in realation to N, where N is the number of characters in Idiom Name 
         * */
        void write_frequency_table(); 


        /** @brief Writes the treecode table to the standard output channel 
         * @pre There is a String Name waiting in the standard input channel 
         * @post If the Idiom Name is in the set, the treecode has been written (in preorder and inorder) to the standard output channel. Otherwise, an error message is printed. 
         * @coste O( N ), where N is the number of nodes in the BinTree that represents the Treecode.  
         * */
        void write_treecode() const; 
        
        
        /** @brief Writes the code(s) of an Idiom to the standard output channel 
         * @pre There is a String Name and a String Code waiting in the standard input channel 
         * @post If the Idiom Name is in the set:
         * if Code equals "todos" the codes of Idiom Name have been written to the standard output channel. 
         * if Code equals one of the characters of Idiom Name, the code for that character has been written to the standar output channel. 
         * Otherwise, an error message is printed. 
         * @coste O( M*log(N) ), where N is the number of characters in the idiom and M is the number of codes that we want to print (M = N if Code = "todos". M = 1 otherwise).  
         * */
        void write_codes() const;


};
#endif
