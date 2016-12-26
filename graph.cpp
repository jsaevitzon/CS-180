#include <stack>
#include <queue>
#include <iostream>

using namespace std;


class graph
{
public:
  graph(int nodes)
  {
    numNodes = nodes; 
    
    matrix = new int* [numNodes];
    
    for(int i=0; i<numNodes; i++)
      {
	matrix[i] = new int [numNodes];
	
	for(int j=0; j<numNodes; j++)
	  {
	    matrix[i][j] = 0;
	  }
      }
   
  }
  
  void add_Edge(int origin, int destin)
  {
    if( origin > numNodes || destin > numNodes 
	|| origin<=0 || destin <= 0)
      {
	std::cout<<"out of bounds";
      }
    else
      {
	matrix[origin-1][destin-1] = 1;
	matrix[destin-1][origin-1] = 1;
      }
  }

  void display()
  {
    int i,j;
    for(i = 0; i < numNodes;i++)
      {
	for(j = 0; j < numNodes; j++)
	  cout<<matrix[i][j]<<"  ";
	cout<<endl;
      }
  }


private:
  int numNodes;
  //this allows us to input size when graph is ceated
  int **matrix;
  bool *visited; 
};


int main()
{
  int nodes, max_edges, origin, destin;
  cout<<"Enter number of nodes: ";
  cin>>nodes;
  graph am(nodes);
  max_edges = nodes * (nodes - 1);
  for (int i = 0; i < max_edges; i++)
    {
      cout<<"Enter edge (-1 -1 to exit): ";
      cin>>origin>>destin;
      if((origin == -1) && (destin == -1))
	break;
      am.add_Edge(origin, destin);
    }
  am.display();
  return 0;
}
