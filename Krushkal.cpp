#include<iostream>
#include<vector>
#include<map> 
#include <set>


using namespace std; 



class Edge{

public:
    int src;
    int dest;
    int cost;

    public:
        void scanEdge(){
            cout<<"Enter SRc Dest Cost";
            cin>>src>>dest>>cost; 
        }

        int getSrc(){
            return src;
        }

        int getDest(){
            return dest; 
        }

        int getCost(){
            return cost;
        }
};

class Graph{
    int totalVertex;
    int totalEdges; 
   public:
    vector<Edge> list;// list[5] list[10] 
    public:
        Graph(int v,int e){
            totalVertex = v;//5
            totalEdges = e; //6 
        
        }

        void addEdge(Edge e){
            list.push_back(e);//push 3 time  - allocate 3 time 
        } 

        ~Graph()
        {
              //
        }

        void display(){
            for(auto x:list){

            }

            for(auto i = list.begin();i != list.end(); i++){

            }
        }

        

         
};

 
void krushkal(Graph g){
      vector<Edge> visitedEdges;// 
      map<int,int> visited; 

    //sort 
      for(int i=0;i<g.list.size();i++){
        for(int j=0;j<g.list.size()-1;j++){
            if(g.list[j].cost > g.list[j+1].cost){
                Edge tmp; 
                tmp = g.list[j]; 
                g.list[j] = g.list[j+1]; 
                g.list[j+1] = tmp; 
            }
        }
      }


      for(int i=0;i<g.list.size();i++){
            int src = g.list[i].src;//2
            int dest = g.list[i].dest; //3 

            if(visited[src] != 1 &&  visited[dest] != 1){
                visitedEdges.push_back(g.list[i]); 
                visited.insert(src,1); 
                visited.insert(dest,1); 
            } else{

            }

        
      }


}
int main(){
    int v,e;
    cout<<"How many vertext and edges? ";
    cin>>v>>e; //5 , 6 
    Graph g(v,e);

    for(int i=1;i<=e;i++){
        Edge e; //src dest cost 
        e.scanEdge();
        g.addEdge(e);
    }

    krushkal(g);

    return 0;
}