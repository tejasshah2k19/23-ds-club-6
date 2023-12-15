#include<iostream>
#include<list>
#include<map> 
#include<queue> 

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

        void setSrc(int s){
            src = s;
        }
        void setDest(int d){
            dest = d;
        }
        void setCost(int c){
            cost = c; 
        }
};

class Graph{
    int totalVertex;
    int totalEdges; 
    public:
    list<Edge> list;// list[5] list[10] 
   
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

        map<int,int> visited; 

        void dfs(int s){
 
            if(visited.size() != totalVertex){ 

                visited.insert({s,1});//1 2 6  3 
                cout<<s;

                for(Edge x:list){ //16
                    if(x.getSrc() == s  && visited.find(x.getDest()) == visited.end() ){
                        s = x.getDest();//2  6  3  5
                        
                        dfs(s);
                    }
                    if(visited.size() == totalVertex){
                        break; 
                    }
                }
                
            }

        }


    void bfs(int x){
        map<int,int> visited; //1 2 
        queue<int> q; 

        cout<<" "<<x; //1   
        visited.insert({x,x});//add key: 1 , value : 1 

    while( visited.size() != totalVertex){ 
        for(Edge e:list){
            if(visited.size() == totalVertex)
            break;
            if(e.getSrc() == x && visited.find(e.getDest()) == visited.end()){
                 visited.insert({e.getDest(),1}); //1 2 3 4 6 5  
                 q.push(e.getDest());   //2 3  4 
                 cout<<" "<<e.getDest(); //2 3  4 
            }
        }
        x = q.front();
        q.pop();
    }

    }
 
};


int main(){
    int v,e;
    cout<<"How many vertext and edges? ";
    cin>>v>>e;

    Graph g(v,e);

    for(int i=1;i<=e;i++){
        Edge e; //1 2 1  2 1 1  
        e.scanEdge();
        g.addEdge(e);

        Edge e2 ;
        e2.setSrc(e.getDest());
        e2.setDest(e.getSrc());
        e2.setCost(e.getCost());

        g.list.push_back(e);
        g.list.push_back(e2);    
    }

    //Src   Dest      Cost 


    //DFS BFS  
   // g.bfs(1);

    g.dfs(1);
    return 0;
}