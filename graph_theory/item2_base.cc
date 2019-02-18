#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
    using Graph = boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS>;
    Graph g;
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 3, g);
    boost::add_edge(1, 2, g);
    boost::add_edge(2, 3, g);

    cout << "number of vertices: " << boost::num_vertices(g) << endl;
    cout << "number of edges: " << boost::num_edges(g) << endl;

    Graph::vertex_iterator vertexIt, vertexEnd;
    Graph::adjacency_iterator neighbourIt, neighbourEnd;

    boost::tie(vertexIt, vertexEnd) = boost::vertices(g);
    for(; vertexIt != vertexEnd; ++vertexIt) {
        std::cout << "edge vertex: " << *vertexIt << std::endl;

        Graph::in_edge_iterator inedgeIt, inedgeEnd;
        boost::tie(inedgeIt, inedgeEnd) = boost::in_edges(*vertexIt, g);
        std::cout << "in edge: ";
        for(; inedgeIt != inedgeEnd; ++inedgeIt) {
            std::cout << *inedgeIt << std::endl;
        }
        std::cout << std::endl;

        Graph::out_edge_iterator outedgeIt, outedgeEnd;
        boost::tie(outedgeIt, outedgeEnd) = boost::out_edges(*vertexIt, g);
        std::cout << "out edge: ";
        for(; outedgeIt != outedgeEnd; ++outedgeIt) {
            std::cout << *outedgeIt << std::endl;
        }
        std::cout << std::endl;
    }
    */

    using VertexNameProp = boost::property<boost::vertex_name_t, std::string>;
    using EdgeWeightProp = boost::property<boost::edge_weight_t, int>;
    using G = boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, VertexNameProp, EdgeWeightProp>;
    G g;
    std::string city[4] = {"beijing", "tokoyo", "newyork", "paris"};
    G::vertex_descriptor v[4];
    v[0] = boost::add_vertex(city[0], g);
    v[1] = boost::add_vertex(city[1], g);
    v[2] = boost::add_vertex(city[2], g);
    v[3] = boost::add_vertex(city[3], g);

    boost::add_edge(v[0], v[1], 10, g);
    boost::add_edge(v[0], v[2], 40, g);
    boost::add_edge(v[0], v[3], 50, g);

    G::vertex_iterator vs, ve;
    boost::property_map<G, boost::vertex_name_t>::type vertexprop = boost::get(boost::vertex_name, g);
    boost::property_map<G, boost::edge_weight_t>::type edgeprop = boost::get(boost::edge_weight, g);

    boost::tie(vs, ve) = boost::vertices(g);
    for(; vs != ve; ++vs) {
        std::string vprop = vertexprop[*vs];
        std::cout << vprop << std::endl;
        // vertexprop[*vs] =

        G::out_edge_iterator oes, oee;
        boost::tie(oes, oee) = boost::out_edges(*vs, g);
        for(; oes != oee; ++oes) {
            std::cout << edgeprop[*oes] << std::endl;
        }
    }

    return 0;
}
