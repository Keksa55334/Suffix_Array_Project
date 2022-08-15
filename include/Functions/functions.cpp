#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include "functions.h"

//PART OF CODE FOR TRIE METHOD
//constructor
Slovo::Slovo(char sl){
    slovo=sl;
}
//operator overloads
bool operator==(const Slovo &lhs,const Slovo &rhs){
    return lhs.slovo==rhs.slovo;
}
bool operator<(const Slovo &lhs,const Slovo &rhs){
    return lhs.slovo<rhs.slovo;
}
bool operator>(const Slovo &lhs,const Slovo &rhs){
    return lhs.slovo>rhs.slovo;
}

//function to insert nodes in children_vector
void insert_into_vec(std::vector<Slovo*> &vec,Slovo &slovo,std::vector<Slovo*> &active){
    int n=vec.size();
    if(n==0){//if there are no children insert node
        vec.push_back(&slovo);
        active.push_back(&slovo);//active are nodes who can "get" children, etc nodes at the end of the chain or the root node
    }else {
        //while node is lexigraphically greater traverse the vector
        auto i=vec.begin();
        while(i!=vec.end() && *(*i)<slovo){
            i++;
        }
        if(i!=vec.end() && *(*i)==slovo){//equal nodes, no need for insertion, but make the equal node in children_vector active
            active.push_back((*i));
        }else{
            //found a spot according to lexiographical order,insert
            vec.insert(i,&slovo);
            active.push_back(&slovo);
        }
    }
}

//method for $ insertion at the end
void insert_into_vector_end(std::vector<Slovo*> &vec,Slovo &slovo){
    vec.insert(vec.begin(),&slovo);/*
    $ must be inserted at the beggining of the children array, because 
         A                A
        / \              / \
       $   M            M   $ 
    will give different suffix array, left trie will give correctly that A<AM, but the right one will give A>AM, which is incorrect
    */
}                                     

//function to create trie
Slovo* create_trie(std::string input_str){

    std::vector<Slovo*> active;//init active vector
    Slovo *first=new Slovo(' ');//create root node
    active.push_back(first);//insert root node in active vector
    for(int i=0;i<input_str.length();i++){//loop through input string
        
        //
        std::vector<Slovo *> active2;//vector that is used as a helping variable,in which new active's are inserted, so vector active is not overwrittend during looping through it
        active2.push_back(first);
        for(auto it=active.begin();it!=active.end();it++){//for every active node insert children
            Slovo *sl=new Slovo(toupper(input_str[i]));//for every separate tree "path", even though its an equal char, a new object must be created
            insert_into_vec((*(*it)).children_vector,*sl,active2);//insert children
        }
        active=active2;

    }
    //end
    
    for(auto it=active.begin();it!=active.end();it++){//inser end sign
        Slovo *end=new Slovo('$');
        insert_into_vector_end((*(*it)).children_vector,*end);
    }

    return first;

}

//function to traverse trie and create suffix array
void trie_traversal(Slovo *first,int length,std::vector<int> &suffix_array,int n){
    if((*first).children_vector.size()==0){//if at end sign
        if((length-1)!=0){//to ignore $ path
            suffix_array.push_back(n-(length-1));
        }
        
    
    }else{
        for(auto it=(*first).children_vector.begin();it!=(*first).children_vector.end();it++){
            
            trie_traversal(*it,length+1,suffix_array,n);//go one level lower
        }
    }

}

//final result
std::vector<int> trie_method_result(std::string input_str){//function to combine everything and give result
    int n=input_str.length();
    Slovo *first=create_trie(input_str);

    std::vector<int> suffix_array;
    int length=0;

    trie_traversal(first,length,suffix_array,n);


    return suffix_array;
}

//END OF TRIE PART

//for brute force and similar functions to be correct, all chars need to either be uppercase or lowercase
std::string str_to_upper(std::string str){
    std::string str2="";
    for(int i=0;i<str.length();i++){
        str2+=toupper(str[i]);
    }
    return str2;
}


//BRUTE FORCE 


std::vector<int> brute_force(std::string input_str){
    std::string input=str_to_upper(input_str);
    int n=input.length();
    std::vector<std::string> str;//vector of all  suffixes
    
    for(int i=0;i<n;i++){
        str.push_back(input.substr(i,n-i));
    }
    std::sort(str.begin(),str.end());//sort
    std::vector<int> vec;//suffix array
    for(int i=0;i<str.size();i++){
        vec.push_back(n-str[i].length());// n-length is the suffix index
    }
    return vec;
}

//END OF BRUTE FORCE


//26 VECTORS, THEN BRUTE FORCE APPROACH
std::vector<int> container_brute_force(std::string input){
    

    std::string input_str=str_to_upper(input);//to uppercase
    int n=input_str.length();
    std::vector<int> return_vec;
    std::vector<std::string> lista[26];
    for(int i=0;i<n;i++){
        lista[input_str[i]-65].push_back(input_str.substr(i,n-i));//add substrings to their container
    }
    
    
    for(int i=0;i<26;i++){
        
            
                
        int m=lista[i].size();
        if(m>0){//if container not empty
            if(m>1){//if more than 1 substring in container
                std::sort(lista[i].begin(),lista[i].end());//sort
            }
                        
            for(int k=0;k<m;k++){
                            
                return_vec.push_back(n-lista[i][k].length());
                            
            }
                    
        }
                
            
        
        
    }


    return return_vec;
}


//FUNCTION TO GENERATE RANDOM STRING

std::string gen_random(const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}
