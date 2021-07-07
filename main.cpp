#include <iostream>
#include <vector>

#define INF 10000

typedef int weight;

class Graph{
private:
    std::vector<std::vector<weight>> matrix_of_adjacency;
    int vertexes;
    int edges;
public:
    void input(){
        std::cout<<"Enter number of vertexes: ";
        std::cin>> vertexes;
        std::cout<<"Enter number of edges: ";
        std::cin>> edges;
        matrix_of_adjacency.resize(vertexes);
        for(auto& line: matrix_of_adjacency){
            line.resize(edges);
        }
        std::cout<<"Enter weights according to your graph.\n";
        for(int i = 0; i < vertexes; ++i){
            for(int j = 0; j < edges; ++j){
                std::cout<<i<<"-->"<<j<<": ";
                int positive;
                // for situations as i-->i enter 0 and if you can't reach certain node with 1 leap enter negative number
                std::cin>>positive; 
                if(positive < 0){matrix_of_adjacency[i][j] = INF;continue;}
                matrix_of_adjacency[i][j] = positive;    
            }
        }
        std::cout<<std::endl;
    }

    void print(){
        std::cout<<"Your graph: \n";
        for(int i = 0; i < vertexes; ++i){
            for(int j = 0; j < edges; ++j){
                std::cout<<matrix_of_adjacency[i][j]<<"\t";                                         
            }
            std::cout<<std::endl;
        }
    }
};

int main(){
    Graph g;
    g.input();
    g.print();

}