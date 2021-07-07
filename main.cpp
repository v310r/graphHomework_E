#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 10000

typedef int weight;
typedef int vertex;

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
        std::cout<<std::endl;
    }

    void print_bfs(vertex start){
        std::vector<bool> used(vertexes,false);
        std::queue<vertex> q;
        q.push(start);
        used[start] = true;
        std::cout<<"bfs traverse: "<<start<<" ";
        while(!q.empty()) {
            vertex current = q.front();
            q.pop();
            vertex v{};
            for(auto weight:matrix_of_adjacency[current]) {
                if((weight < INF) && (!used[v])){
                    std::cout<<v<<" ";
                    used[v] = true;
                    q.push(v);
                }
                ++v;
            }
        }
        std::cout<<std::endl;
    }

        void print_dfs(vertex start){
        std::vector<bool> used(vertexes,false);
        std::stack<vertex> s;
        s.push(start);
        used[start] = true;
        std::cout<<"dfs traverse: "<<start<<" ";
        while(!s.empty()) {
            vertex current = s.top();
            s.pop();
            vertex v{};
            for(auto weight:matrix_of_adjacency[current]) {
                if((weight < INF) && (!used[v])){
                    std::cout<<v<<" ";
                    used[v] = true;
                    s.push(v);
                }
                ++v;
            }
        }
        std::cout<<std::endl;
    }
};

int main(){
    Graph g;
    g.input();
    g.print();
    g.print_bfs(1);
    g.print_dfs(1);
}