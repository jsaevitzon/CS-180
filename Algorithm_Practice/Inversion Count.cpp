#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;





//array starts at arr, first part ends at l_end, right part starts at l_end+1 and ends at r_end
long long merge_and_count(int *arr, int l_end, int r_end, int size)
    {
    
    
    int* temp  = new int[size];
    
    int l_c=0, r_c=l_end+1, idx=0;
    long long count = 0;
    
    while( idx < size)
        {
        
        if( l_c>l_end )
            {
            while( r_c <= r_end)
                {
                temp[idx] = arr[r_c];
                r_c++; idx++;
            }
        }
        
         else if( r_c>r_end )
            {
            while( l_c <= l_end)
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
              
             
              count += (l_end+1)-l_c;
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
        
    if(size<=1)
     {
       return 0;      
     }
    
    long long inv_count = 0;
    int mid = size/2;
    

    
    
    inv_count  = count_inversions(arr, mid);
    inv_count += count_inversions(arr+mid, size-mid);
    
    //what do i need. array (comes with starting point), array middle (mid), array end ()
    inv_count += merge_and_count(arr, mid-1, size-1, size);
    
    
    return inv_count;
    
    
    
}



int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int *arr = new int[n];
        int num;
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> num;
           arr[arr_i] = num;

        

        }
 
        cout << count_inversions(arr, n) << endl;
        delete[] arr;
    }
    

    return 0;
}
