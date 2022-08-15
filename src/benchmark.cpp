#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include "functions.h"


std::string str_50=gen_random(50);
std::string str_500=gen_random(500);
std::string str_1000=gen_random(1000);
std::string str_5000=gen_random(5000);
std::string str_10000=gen_random(10000);
std::string str_50000=gen_random(50000);

//BENCHMARKING STRINGS LENGTH 50
static void BM_Brute_50(benchmark::State& state){
    for(auto _ : state){
        brute_force(str_50);
    }
}
static void BM_Container_50(benchmark::State& state){
    for(auto _ : state){
        container_brute_force(str_50);
    }
}

static void BM_Trie_50(benchmark::State& state){
    for(auto _ : state){
        trie_method_result(str_50);
    }
}

//BENCHMARKING STRINGS LENGTH 500
static void BM_Brute_500(benchmark::State& state){
    for(auto _ : state){
        brute_force(str_500);
    }
}
static void BM_Container_500(benchmark::State& state){
    for(auto _ : state){
        container_brute_force(str_500);
    }
}

static void BM_Trie_500(benchmark::State& state){
    for(auto _ : state){
        trie_method_result(str_500);
    }
}

//BENCHMARKING STRINGS LENGTH 1000
static void BM_Brute_1000(benchmark::State& state){
    for(auto _ : state){
        brute_force(str_1000);
    }
}
static void BM_Container_1000(benchmark::State& state){
    for(auto _ : state){
        container_brute_force(str_1000);
    }
}

static void BM_Trie_1000(benchmark::State& state){
    for(auto _ : state){
        trie_method_result(str_1000);
    }
}

//BENCHMARKING STRINGS LENGTH 5000
static void BM_Brute_5000(benchmark::State& state){
    for(auto _ : state){
        brute_force(str_5000);
    }
}
static void BM_Container_5000(benchmark::State& state){
    for(auto _ : state){
        container_brute_force(str_5000);
    }
}

static void BM_Trie_5000(benchmark::State& state){
    for(auto _ : state){
        trie_method_result(str_5000);
    }
}

//BENCHMARKING STRINGS LENGTH 10000; NO TRIE, MY PC KILLS THE PROGRAM
static void BM_Brute_10000(benchmark::State& state){
    for(auto _ : state){
        brute_force(str_10000);
    }
}
static void BM_Container_10000(benchmark::State& state){
    for(auto _ : state){
        container_brute_force(str_10000);
    }
}



//BENCHMARKING STRINGS LENGTH 50000; NO TRIE, MY PC KILLS THE PROGRAM
static void BM_Brute_50000(benchmark::State& state){
    for(auto _ : state){
        brute_force(str_50000);
    }
}
static void BM_Container_50000(benchmark::State& state){
    for(auto _ : state){
        container_brute_force(str_50000);
    }
}

//50
BENCHMARK(BM_Brute_50);
BENCHMARK(BM_Container_50);
BENCHMARK(BM_Trie_50);

//500
BENCHMARK(BM_Brute_500);
BENCHMARK(BM_Container_500);
BENCHMARK(BM_Trie_500);

//1000
BENCHMARK(BM_Brute_1000);
BENCHMARK(BM_Container_1000);
BENCHMARK(BM_Trie_1000);

//5000
BENCHMARK(BM_Brute_5000);
BENCHMARK(BM_Container_5000);
BENCHMARK(BM_Trie_5000);

//10000
BENCHMARK(BM_Brute_10000);
BENCHMARK(BM_Container_10000);

//50000
BENCHMARK(BM_Brute_50000);
BENCHMARK(BM_Container_50000);



BENCHMARK_MAIN();