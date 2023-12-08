#include<iostream>
#include<list>
#include<map> 

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

        void display(){
            for(auto x:list){

            }

            for(auto i = list.begin();i != list.end(); i++){

            }
        }

        void dfs(int s){
            map<int,int> visited; 

            cout<<"\nDFS\n";
            cout<<s;//1 

            visited.insert(1,1);

                while(visited.size() != totalVertex){ 
                    for(Edge x:list){
                        if(x.getSrc() == s  && visited[x.getDest()] != 1 ){
                            s = x.getDest();//2
                            cout<<s;
                            visited.insert(s,1);
                        }
                        if(visited.size() == totalVertex){
                            break; 
                        }
                    }
                }


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
    g.display();

    g.dfs(1);

    return 0;
}