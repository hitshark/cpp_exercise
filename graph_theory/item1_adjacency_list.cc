#include <boost/graph/adjacency_list.hpp>
//#include <boost/graph/graph_traits.hpp>
#include <iostream>
#include <utility>

using namespace boost;
using namespace std;

int main()
{
    using G = boost::adjacency_list<listS, vecS, undirectedS>;
    G g;
    add_edge(0, 1, g);
    add_edge(1, 4, g);
    add_edge(4, 0, g);
    add_edge(2, 5, g);

    cout<<boost::num_edges(g)<<endl;
    cout<<boost::num_vertices(g)<<endl;

    using vertex_iter = boost::graph_traits<G>::vertex_iterator;
    std::pair<vertex_iter, vertex_iter> vip;

    std::cout<<"vertices in g = [";
    vip = vertices(g);
    for(auto vi = vip.first; vi != vip.second; ++vi) {
        cout << *vi <<" ";
    }
    std::cout<<"]"<<std::endl;


    using edge_iter = boost::graph_traits<G>::edge_iterator;
    std::pair<edge_iter, edge_iter> eip;
    eip = edges(g);

    cout<<"edge in g = [";
    for(auto ei = eip.first; ei != eip.second; ++ei) {
        cout<<*ei<<endl;
        cout<<"(source edge ="<<boost::source(*ei, g);
        cout<<" targe edge ="<<boost::target(*ei, g)<<")"<<endl;
    }

    cout<<"]"<<endl;

    return 0;
}
