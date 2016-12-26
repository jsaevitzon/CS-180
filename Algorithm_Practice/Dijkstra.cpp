#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int numCases;
    cin >> numCases;
    
    for(int i = 0; i<numCases; i++)
        {
        int v;
        int e;
        cin >> v >> e;
        
        list<pair<int,int>> *g = new list<pair<int,int>>[v];
        
        for(int j = 0; j<e; j++)
            {
            int firstN, secondN, length;
            cin >> firstN >> secondN >> length;
            
            pair<int,int> edge;
            edge = make_pair(secondN, length)
            
            g[firstN].push_back(edge);
        }
        
        for()
        
    }
    
    
    return 0;
}
