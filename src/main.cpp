#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include "functions.h"

int main(void){
    //Dummy main for Mauna string
    std::vector<int> suff_arr=trie_method_result("Mauna");
    for(int i=0;i<suff_arr.size();i++){
        std::cout<<suff_arr[i]<<" ";

    
    }
    std::cout<<std::endl;
}