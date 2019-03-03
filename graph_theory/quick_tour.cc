#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <utility>
#include <algorithm>

template <class Graph>
struct exercise_vertex {
    exercise_vertex(Graph &g_) : g(g_) {}

    using Vertex = typename boost::graph_traits<Graph>::vertex_descriptor;
    void operator() (const Vertex &v) const {
        using GraphTraits = boost::graph_traits<Graph>;
        typename boost::property_map<Graph, boost::vertex_index_t>::type index = boost::get(boost::vertex_index, g);

        // out edge
        std::cout << "out-edges: ";
        typename GraphTraits::out_edge_iterator oi, oe;
        typename GraphTraits::edge_descriptor e;
        for(boost::tie(oi, oe) = boost::out_edges(v, g); oi != oe; ++oi) {
            e = *oi;
            Vertex src = boost::source(e, g), targ = boost::target(e, g);
            std::cout << "(" << index[src] << "," << index[targ] << ") ";
        }
        std::cout << std::endl;

        // in edge
        std::cout << "in-edges: ";
        typename GraphTraits::in_edge_iterator is, ie;
        for(boost::tie(is, ie) = boost::in_edges(v, g); is != ie; ++is) {
            e = *is;
            Vertex src = boost::source(e, g), targ = boost::target(e, g);
            std::cout << "(" << index[src] << "," << index[targ] << ") ";
        }
        std::cout << std::endl;

        // adjacent vertices
        std::cout << "adjacent vertices: ";
        typename GraphTraits::adjacency_iterator ai, ae;
        for(boost::tie(ai, ae) = adjacent_vertices(v, g); ai != ae; ++ai) {
            std::cout << index[*ai] << " ";
        }
        std::cout << std::endl;

        // inverse adjacent vertices
        std::cout << "inverse adjacent vertices: ";
        typename Graph::inv_adjacency_iterator ias, iae;
        //typename GraphTraits::inv_adjacency_iterator ias, iae;
        for(boost::tie(ias, iae) = boost::inv_adjacent_vertices(v, g); ias != iae; ++ias) {
            std::cout << index[*ias] << " ";
        }
        std::cout << std::endl;
    }

    Graph &g;
};

int main()
{
    // set up the graph
    using Graph = boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS>;
    using Edge = std::pair<int, int>;

    enum {A, B, C, D, E, N};
    const int num_vertices = N;
    const char *name = "ABCDE";
    Edge edge_array[] = { Edge(A,B), Edge(A,D), Edge(C,A), Edge(D,C), Edge(C,E), Edge(B,D), Edge(D,E) };
    const int num_edges = sizeof(edge_array) / sizeof(edge_array[0]);

    Graph g(num_vertices);
    for(auto i = 0; i < num_edges; i++) {
        boost::add_edge(edge_array[i].first, edge_array[i].second, g);
    }

    // vertex and edge access
    using Vertex = boost::graph_traits<Graph>::vertex_descriptor;
    using IndexMap = boost::property_map<Graph, boost::vertex_index_t>::type;
    IndexMap index = boost::get(boost::vertex_index, g);

    std::cout << "vertices(g) = ";
    using vertex_iter = boost::graph_traits<Graph>::vertex_iterator;
    std::pair<vertex_iter, vertex_iter> vp;
    for(vp = boost::vertices(g); vp.first != vp.second; ++vp.first) {
        Vertex v = *vp.first;
        std::cout << index[v] << " ";
    }
    std::cout << std::endl;

    std::cout << "edges(g) = ";
    boost::graph_traits<Graph>::edge_iterator eis, eie;
    for(boost::tie(eis, eie) = boost::edges(g); eis != eie; ++eis) {
        std::cout << "(" << index[boost::source(*eis, g)]
                  << "," << index[boost::target(*eis, g)] << ") ";
    }
    std::cout << std::endl;

    // adjacency structure
    std::for_each(vertices(g).first, vertices(g).second, exercise_vertex<Graph>(g));
    return 0;
}
