#include<iostream>
#include<list> 

using namespace std; 


class Graph{
    int v;
    int e; 
   list<int> *adjlist; // list =new LinkedList(10); 
    //linked-> node { data | next* }

    public:
        Graph(int totalVertex,int totalEdges)
        {
            v=totalVertex;
            e = totalEdges; 
            adjlist = new list<int>[totalVertex]; //4 {0 1 2 3}
        }

        ~Graph(){
            delete adjlist; 
        }

        void addEdge(int src,int dest){
            adjlist[src].push_back(dest);//1 3 
            adjlist[dest].push_back(src); 
        }

        void display(){
                    
            for(int i=0;i<v;i++){ //v => totalVertex 
                cout<<"\n"<<i<<" is Connected with Node : ";         
                for(auto x = adjlist[i].begin();x!=adjlist[0].end();x++){
                    cout<<*x<<" ";
                }//head -> next -> 
            
                // for(auto x:adjlist[0]){
                //       cout<<x<<" ";  
                // }
            }
        }

};

int main(){
    int totalEdges; 
    int totalVertex; 
    int src,dest; 

    cout<<"How many vertex you want to add?";
    cin>>totalVertex;//4 {0 1 2 3  }
    cout<<"How many Edges you want to add? ";
    cin>>totalEdges;  ;//4 {8} 

    Graph g(totalVertex,totalEdges); 

    for(int i=1;i<=totalEdges;i++){
        cout<<"\nEnter Source and Destination?";
        cin>>src>>dest;//0 1 
        g.addEdge(src,dest);//0 1  , 0 3 

    }
    //0 -> 1 3  


    return 0;
}