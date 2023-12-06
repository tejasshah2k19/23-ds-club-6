#include<iostream>
#include<list>

using namespace std; 



class Edge{

    int src;
    int dest;
    int cost;

    public:
        void scanEdge(){
            cout<<"Enter SRc Dest Cost";
            cin>>src>>dest>>cost; 
        }
};

class Graph{
    int totalVertex;
    int totalEdges; 
    list<Edge> list;// list[5] list[10] 
    public:
        Graph(int v,int e){
            totalVertex = v;
            totalEdges = e*2; 
        
        }

        void addEdge(Edge e){
            list.push_back(e);//push 3 time  - allocate 3 time 
        } 

        ~Graph()
        {
              //
        }
};


int main(){
    int v,e;
    cout<<"How many vertext and edges? ";
    cin>>v>>e;

    Graph g(v,e);

    for(int i=1;i<=e*2;i++){
        Edge e; 
        e.scanEdge();
        g.addEdge(e);
         
    }

    //Src   Dest      Cost 


    //DFS BFS 
    


    return 0;
}
