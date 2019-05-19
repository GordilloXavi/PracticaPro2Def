/** @file Treecode.hh
    @brief Specification for the Treecode class
 */

#ifndef _TREECODE_HH_
#define _TREECODE_HH_ 

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include "BinTree.hh"
#include <map>
#include <set>
#include <algorithm>
#endif

/** @class Treecode
 * @brief A class containing the data structures and operations necessary to represent our treecode
 *
 * This class contains a BinTree that represents a treecode and two std::map's that store the codes and the frequencies for each character, as well as I/O operations and operations to create and modify the data structures in the treecode.
 */

class Treecode {

    private:

        /** @brief The main data structure to represent the Treecode */
        BinTree< std::pair<std::string, int> > tree;

        /** @brief the frequency table for our idiom */
        std::map< std::string,int > frequencies;

        /** @brief the codes for every character in our idiom */
        std::map<std::string, std::string> codes;

        /**@brief Auxiliar method used to obtain non-ASCII characters from a String
         * @pre i = I < s.size()
         * @post out contains Ith character of s, and i has increased in one unit if it was an ASCII character or 2 otherwise
         * @coste Constant
         */
        static void next_symbol(const std::string& s, int& i, std::string& out);


        /**@brief Auxiliar immersion method used to print the treecode in preorder
         * @pre true
         * @post Prints the treecode in preorder to the standard output channel
         * @coste O( N ), where N is the number of nodes in the BinTree that represents the Treecode.  
         */
        static void write_treecode_pre(const BinTree<std::pair<std::string,int>>& t);

        /**@brief Auxiliar immersion method used to print the treecode in inorder
         * @pre true
         * @post Prints the treecode in inorder to the standard output channel
         * @coste O( N ), where N is the number of nodes in the BinTree that represents the Treecode.  
         */
        static void write_treecode_in(const BinTree<std::pair<std::string,int>>& t);

        /** @brief Immersion function used as an auxiliary method to generate the codes for our idiom
         * @pre True
         * @post The std::map codes now contains the codes for all characters in our idiom
         * @coste O( N ), where N is the number of nodes in tree.
         * */
        void generate_codes(const BinTree<std::pair<std::string,int>>& t, std::string s);


    public:

        /** @brief Default constructor
         * @pre True
         * @post Returns an empty Treecode
         * @coste constant
         */
        Treecode();

        /** @brief Reads an the frequency table for the Idiom 
         * @pre There is an int N and N pairs of string, int in the standard input channel 
         * @post The frequency table now contains the pairs of string and int corresponding to the frequancy of each character
         * @coste Linear in relation to N 
         * */
        void read_frequency_table();

        /** @brief Creates the binary tree from the frequency table
         * @pre True
         * @post the private field tree now represents our idiom
         * @coste O( N*log(N) ), where N is the number of characters in our Idiom
         * */
        void make_treecode();

        /** @brief Creates the code for each character in the idiom
         * @pre True
         * @post the private field codes now has the codes for every letter in our idiom
         * @coste O( N ), where N is the number of nodes in tree.
         * */
        void make_codes();


        /** @brief Modifies an existing frequency table
         * @pre The standard input channel contains an integer N and N pairs of string, int
         * @post The Idiom's frequency table now contains the additional pairs from the standard input channel. If tha character in the pair already existed in the Idiom, its frequency is added to the new frequency. 
         * @coste O( N*log(N) )
         * */
        void modify_frequency_table();

        /** @brief Writes the frequency table to the standard output channel 
         * @pre True
         * @post The frequency table has been written to the standard output channel
         * @coste Linear in relation to N, where N is the number of characters in out Idiom 
         * */
        void write_frequencies();


        /** @brief Writes the treecode to the standard output channel 
         * @pre True
         * @post The treecode has been written to the standard output channel if preorder and inorder
         * @coste O( N ), where N is the number of nodes in the BinTree that represents the Treecode.  
         * */
        void write_treecode(const std::string& id) const;

        /** @brief Writes the code(s) of an Idiom to the standard output channel 
         * @pre True
         * @post If Code equals "todos" the codes of Idiom Name have been written to the standard output channel. 
         * if Code equals one of the characters of our Idiom, the code for that character has been written to the standar output channel. Otherwise, an error message is printed. 
         * @coste O( M*log(N) ), where N is the number of characters in the idiom and M is the number of codes that we want to print (M = N if Code = "todos". M = 1 otherwise).  
         * */
        void write_codes(const std::string& ch) const;

        /** @brief Prints to the standard output channel the encoded version of a String
         * @pre True
         * @post If the String txt can be encoded in this idiom, the encoded version of the string is printed to the standard output channel. Otherwise, an error message is printed. 
         * @coste O( N*log(N) ), where N is the length of txt
         * */
        void encode(std::string& txt) const;

        /** @brief Prints to the standard output channel the decoded version of a String
         * @pre True 
         * @post If the String txt can be decoded in this idiom, the decoded version of the string is printed to the standard output channel. Otherwise, an error message is printed. 
         * @coste O( N ), where N is the length of txt
         * */
        void decode(std::string& txt);


};
#endif
