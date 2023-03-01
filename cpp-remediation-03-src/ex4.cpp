#include <string>
#include <map>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <iostream>

using vertex_t = std::string;
using weight_t = float;
using nbh_t = std::pair<vertex_t, weight_t>;
using Graph = std::map<vertex_t, std::vector<nbh_t>>;


// FIXME a "good" data structure

// FIXME the main algorithm
auto shortest_path(const Graph& g, vertex_t src) -> std::map<vertex_t, weight_t>


int main()
{
    Graph g;
    g["A"] = {{"B", 7}, {"C", 9}};
    g["B"] = {{"A", 7}, {"D", 3}};
    g["C"] = {{"A", 9}, {"D", 5}};
    g["D"] = {{"B", 3}, {"C", 5}, {"E", 7}, {"F", 4}, {"G", 2}};
    g["E"] = {{"D", 7}, {"F", 2}};
    g["F"] = {{"D", 4}, {"E", 2}, {"G", 1}};
    g["G"] = {{"D", 2}, {"F", 1}};

    auto res = shortest_path(g, "A");

    for (auto [k,v] : res)
        std::cout << k << " : " << v << "\n";


}