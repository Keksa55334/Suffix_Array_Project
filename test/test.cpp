#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include "functions.h"

//ASSERT RESULTS ARE EQUAL

//assert vectors equal sizes
TEST(Equality,VectorSize){
    std::string input=gen_random(1000);
    std::vector<int> suff_arr_brute=brute_force(input);
    std::vector<int> suff_arr_container_brute=container_brute_force(input);
    std::vector<int> suff_arr_trie=trie_method_result(input);

    ASSERT_EQ(suff_arr_brute.size(),suff_arr_container_brute.size())<<"Array lengths of brute force and container approach differ";
    ASSERT_EQ(suff_arr_brute.size(),suff_arr_trie.size())<<"Array lengths of brute force and trie approach differ";
    ASSERT_EQ(suff_arr_trie.size(),suff_arr_container_brute.size())<<"Array lengths of container and trie approach differ";

}

TEST(Equality,ArrayContent){
    std::string input=gen_random(1000);
    std::vector<int> suff_arr_brute=brute_force(input);
    std::vector<int> suff_arr_container_brute=container_brute_force(input);
    std::vector<int> suff_arr_trie=trie_method_result(input);

    for(int i=0;i<suff_arr_brute.size();i++){
        ASSERT_EQ(suff_arr_brute[i],suff_arr_container_brute[i])<<"Results of brute and container approach differ";
        ASSERT_EQ(suff_arr_container_brute[i],suff_arr_trie[i])<<"Results of trie and container approach differ";
        ASSERT_EQ(suff_arr_brute[i],suff_arr_trie[i])<<"Results of brute and trie approach differ";
    }

}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}