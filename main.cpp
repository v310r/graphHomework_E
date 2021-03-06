#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>

#define INF 10000

typedef int weight;
typedef int vertex;

class Graph{

private:

    std::vector<std::vector<weight>> matrix_of_adjacency;
    int vertexes;
    int edges;
    std::fstream file;

public:

    Graph():file("data.txt",std::fstream::in | std::fstream::out | std::fstream::app) {

    }

    void input(){
        file >> vertexes;
        std::cout<<"Enter number of vertexes: "<<vertexes<<"\n";
        file >> edges;
        std::cout<<"Enter number of edges: "<<edges<<"\n";
        matrix_of_adjacency.resize(vertexes);
        for(auto& line: matrix_of_adjacency){
            line.resize(edges);
        }
        std::cout<<"Enter weights according to your graph.\n";
        int temp;
        for(int i = 0; i < vertexes; ++i){
            for(int j = 0; j < edges; ++j){
                file>>temp;
                std::cout<<i<<"-->"<<j<<": "<<temp<<"  ";
                // for situations as i-->i enter 0 and if you can't reach certain node with 1 leap enter negative number
                if(temp < 0){matrix_of_adjacency[i][j] = INF;continue;}
                matrix_of_adjacency[i][j] = temp;    
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

    int getUnusedMinElement_andHisIndex(std::vector<weight>& L,std::vector<bool>& used,vertex& n){
        int temp{INF};
        for(int i = 0;i<vertexes;++i){
            if((L[i]<temp) && (!used[i])){
                temp = L[i];
                n = i;
            }
        }

        return temp;
    }

    bool neighbour_Approved(int currentNode, int neighbour){
        return matrix_of_adjacency[currentNode][neighbour] != INF;
    }

    void print_Dijkstra(vertex beginning, vertex end){
        std::vector<weight> Lengths(vertexes);
        for(auto& distance:Lengths){
            distance = INF;
        }
        Lengths[beginning] = 0;
        std::vector<vertex> path(vertexes);
        std::vector<bool> used(vertexes,false);
        vertex currentNode = beginning;
        for(int i = 0; i<vertexes; ++i){
            int minLength = getUnusedMinElement_andHisIndex(Lengths,used,currentNode);
            used[currentNode] = true;
            for(int neighbour = 0; neighbour<edges;++neighbour){
                // useless to do something with the same node
                if(currentNode == neighbour)continue;

                if(!neighbour_Approved(currentNode,neighbour)) continue;

                //update path
                if( (minLength+matrix_of_adjacency[currentNode][neighbour]) < Lengths[neighbour]) path[neighbour] = currentNode;

                Lengths[neighbour] = std::min(Lengths[neighbour],minLength+matrix_of_adjacency[currentNode][neighbour]);

            }
        }
        std::cout<< "\nShortest distance from node "<<beginning<<" to node "<<end<<" is: "<<Lengths[end];
        std::cout<<"\nThe path is: ";
        std::cout<<end<<"<--";
        int current;
        for(current = path[end];current>beginning;current = path[current]){
            std::cout<<current<<"<--";
        }
        std::cout<<current<<"\n";
    }
};

int main(){
    Graph g;
    g.input();
    g.print();
    g.print_bfs(1);
    g.print_dfs(1);
    g.print_Dijkstra(0,4);
}