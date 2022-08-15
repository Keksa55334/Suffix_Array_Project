#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

//TRIE PART
struct Slovo{
    std::vector<Slovo*> children_vector;//children nodes are stored in this vector
    char slovo;//char value of node
    friend bool operator==(const Slovo&, const Slovo&);
    friend bool operator<(const Slovo&,const Slovo&);
    friend bool operator>(const Slovo&,const Slovo&);
    Slovo(char sl);
};
bool operator==(const Slovo &lhs,const Slovo &rhs);
bool operator<(const Slovo &lhs,const Slovo &rhs);
bool operator>(const Slovo &lhs,const Slovo &rhs);
void insert_into_vec(std::vector<Slovo*> &vec,Slovo &slovo,std::vector<Slovo*> &active);// function to insert nodes in children_vector
void insert_into_vector_end(std::vector<Slovo*> &vec,Slovo &slovo);//function to insert $ at the end
Slovo* create_trie(std::string input_str);//create trie
void trie_traversal(Slovo *first,int length,std::vector<int> &suffix_array,int n);//traverse trie
std::vector<int> trie_method_result(std::string input_str);//end result
//END OF TRIE PART


std::string str_to_upper(std::string str);
//BRUTE FORCE PART
std::vector<int> brute_force(std::string input);
//END OF BRUTE FORCE PART


//26 CONTAINERS PART
std::vector<int> container_brute_force(std::string input_str);

//RANDOM STRING FUNCTION
std::string gen_random(const int len);