#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <utility>
#include <cfloat>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <assert.h>

//define a strut of node measurement from source node S
struct NODE_M {
    int node;
    double dist_to_s;
    NODE_M () : node(0),dist_to_s(0.0) {}
    NODE_M (int n, double d) : node(n),dist_to_s(d) {}
    friend bool operator>(const NODE_M &x, const NODE_M &y);
    friend bool operator<(const NODE_M &x, const NODE_M &y);
    friend bool operator==(const NODE_M &x, const NODE_M &y);
    friend bool operator!=(const NODE_M &x, const NODE_M &y);
    std::string repr() const {return "node:" + std::to_string(node) + " | dist:" + std::to_string(dist_to_s);}
};

//define node and graph
struct Edge{
    int u; // node u
    int v; // node v
    double d; //distance between node u and v
    Edge(int u, int v, double d) : u(u),v(v),d(d){}
    std::string repr() const {return "u:" + std::to_string(u) + " | v:" + std::to_string(v) + " | d:" + std::to_string(d);}
};

bool operator>(const NODE_M &x, const NODE_M &y)
{
   return x.dist_to_s > y.dist_to_s;
}

bool operator<(const NODE_M &x, const NODE_M &y)
{
   return x.dist_to_s < y.dist_to_s;
}

bool operator==(const NODE_M &x, const NODE_M &y)
{
   return x.node == y.node;
}

bool operator!=(const NODE_M &x, const NODE_M &y)
{
   return x.node != y.node;
}

template <typename T>
struct compare_item
{
    bool operator()(const T& n1, const T& n2) const
    {
        return n1 > n2;
    }
};

class Graph{
private:
    std::map<int,std::list<int>> adj_map;
    std::map<std::pair<int,int>,double> dist_map;
public:
    Graph(){}

    bool has_edge(Edge e) const {
        return dist_map.count(std::make_pair(e.u,e.v)) || dist_map.count(std::make_pair(e.v,e.u));
    }

    bool has_edge(int u, int v) const {
        return dist_map.count(std::make_pair(u,v)) || dist_map.count(std::make_pair(v,u));
    }

    void add_edge(Edge e){
        assert(!has_edge(e)); // do not add repeated edge
        adj_map[e.u].push_back(e.v); // u -> v direction
        adj_map[e.v].push_back(e.u); // v -> u direction
        dist_map[std::make_pair(e.u,e.v)] = e.d;
    }

    const std::list<int> get_list(int node) const{
        return (adj_map.count(node)) ? adj_map.at(node) : std::list<int>(); 
    }

    const double get_dist(int u, int v) const {
        assert(has_edge(u,v));
        if (dist_map.count(std::make_pair(u,v))) {
            return dist_map.at(std::make_pair(u,v));
        } else {
            return dist_map.at(std::make_pair(v,u));
        }
    }

};

#endif //GRAPH_H