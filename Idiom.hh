/** @file Idiom.hh
    @brief Specification for the Idiom class 
 */

#ifndef _IDIOM_HH_
#define _IDIOM_HH_

#include "Treecode.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

/*
 * Idiom class
 */

/** @class Idiom
 * @brief Represents the set of data structures and operations neded to represent our idioms.
 *
 * Offers operations for reading new or existing idioms and displaying some of their features (treecode, frequency table and codes), as well as a constructor method.
 */
class Idiom {

    private:

        /** @brief The treecode that will allow us to construct the codes for our characters */
        Treecode tree;

    public:
        /** @brief Default constructor
         * @pre True
         * @post Returns an empty Idiom, with and empty Treecode
         * @coste Constant
         * */
        Idiom();
        

        /** @brief Prints to the standard output channel the encoded version of a String
         * @pre True
         * @post If the String txt can be encoded in this idiom, the encoded version of the string is printed to the standard output channel. Otherwise, an error message is printed. 
         * @coste O( N*log(N) ), where N is the length of txt
         * */
        void encode(std::string& txt);

        /** @brief Prints to the standard output channel the decoded version of a String
         * @pre True 
         * @post If the String txt can be decoded in this idiom, the decoded version of the string is printed to the standard output channel. Otherwise, an error message is printed. 
         * @coste O( N ), where N is the length of txt
         * */
        void decode(std::string& txt);


        /** @brief Writes the frequency table to the standard output channel 
         * @pre True
         * @post The frequency table has been written to the standard output channel
         * @coste Linear in realation to N, where N is the number of characters in Idiom Name 
         * */
        void write_frequencies();


        /** @brief Writes the treecode to the standard output channel 
         * @pre True
         * @post The treecode has been written to the standard output channel if preorder and inorder
         * @coste O( N ), where N is the number of nodes in the BinTree that represents the Treecode.  
         * */
        void write_treecode(const std::string& s) const;

        /** @brief Writes the code(s) of an Idiom to the standard output channel 
         * @pre True
         * @post If Code equals "todos" the codes of Idiom Name have been written to the standard output channel. 
         * if Code equals one of the characters of our Idiom, the code for that character has been written to the standar output channel. Otherwise, an error message is printed. 
         * @coste O( M*log(N) ), where N is the number of characters in the idiom and M is the number of codes that we want to print (M = N if Code = "todos". M = 1 otherwise).  
         * */
        void write_codes(const std::string& ch) const;

        /** @brief Reads an Idiom 
         * @pre There is an integer N and N pairs of String, int waiting in the standard input channel.
         * @post The implicit parameter is an idiom containing the frequency table and the codes for the N characters 
         * @coste O( N*log(N) ), where N is the number of characters in our idiom. The cost is highr than expected because upon reading an Idiom we also generatew the treecode and the codes for that Idiom.
         * */
        void read_idiom();

        /** @brief Generates the treecode from the frequency table
         * @pre True
         * @post The treecode has been generated
         */
        void make_treecode();

        /** @brief Modifies an existing Idiom
         * @pre The standard input channel contains an integer N and N pairs of string, int
         * @post The Idiom's frequency table, treecode and codes now contain the additional pairs from the standard input channel. If tha character in the pair already existed in the Idiom, its frequency is added to the new frequency. 
         * @coste O( N*log(N) )
         * */
        void modify_idiom();


};
#endif
