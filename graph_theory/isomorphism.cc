#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/vf2_sub_graph_iso.hpp>
#include <iostream>

using namespace boost;

int main()
{
    using graph_type = adjacency_list<setS, vecS, bidirectionalS>; 
    graph_type small(2);
    add_edge(0, 1, small);
    add_edge(0, 2, small);

    graph_type large(4);
    add_edge(0, 1, large);
    add_edge(0, 4, large);
    add_edge(1, 2, large);
    add_edge(2, 3, large);

    vf2_print_callback<graph_type, graph_type> callback(small, large);
    vf2_subgraph_iso(small, large, callback);

    return 0;
}

