#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;



//array starts at arr, first part ends at l_end, right part starts at l_end+1 and ends at r_end
long long merge_and_count(int *arr, int l_end, int r_end, int size)
    {
    
    
    int* temp  = new int[size];
    
    int l_c=0, r_c=0, idx=0;
    long long count = 0;
    
    while( idx != size)
        {
        
        if( l_c==l_end )
            {
            while( r_c != r_end)
                {
                temp[idx] = arr[r_c];
                r_c++; idx++;
            }
        }
         else if( r_c==r_end )
            {
            while( l_c != l_end)
                {
                temp[idx] = arr[l_c];
                l_c++; idx++;
                
               }
              }
          else if( arr[l_c] <= arr[r_c] )
              {
              temp[idx] = arr[l_c];
              l_c++; idx++;
          }
          else 
              {
              temp[idx] = arr[r_c];
              r_c++; idx++;
              
              count += l_end-l_c;
          }
          }
        
       for(int i=0; i<size; i++)
           {
           arr[i] = temp[i];
       }
    delete[] temp;
    return count;
}
              
  

long long count_inversions(int* arr, int size) {
        
    if(size==1)
     {
       return 0;      
     }
    
    long long inv_count = 0;
    int mid = size/2;
    
    cout<<"count_inv";
    
    
    inv_count  = count_inversions(arr, mid);
    inv_count += count_inversions(arr+mid, size-mid);
    
    //what do i need. array (comes with starting point), array middle (mid), array end ()
    inv_count += merge_and_count(arr, mid, size-1, size);
    
    
    return inv_count;
    
    
    
}
