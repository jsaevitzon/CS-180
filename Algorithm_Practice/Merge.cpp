/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    
     int arr_size = r-l+1;
     int *left_p  = &arr[l];
     int *right_p = &arr[m+1];
     
     //use this to store the sorted temp array
     int *temp = new int[arr_size];
    
     // i is left count, j is right, idx is temp
     int i=0, j=0, idx=0;
     int left_size  = m-l+1;
     int right_size = r-m;
     
     //go until temp is full
     while(idx != arr_size)
     {
         //if left subarray is full, add rights values until done
         if(i==left_size)
         {
             while(j!=right_size)
             {
                 temp[idx] = *right_p;
                 idx++; right_p++; j++;
             }
         }
         //if right subarray is full, do opposite for left
         else if(j==right_size)
         {
             while(i!=left_size)
             {
                 temp[idx] = *left_p;
                 idx++; left_p++; i++;
             }
         }
          
         //compare and add smaller value
         else if(*left_p <= *right_p)
         {
            temp[idx] = *left_p;
            idx++; left_p++; i++;
         }
         else
         {
             temp[idx] = *right_p;
             idx++; right_p++; j++;
         }
     }
     
     //copy from temp to array
     for(i = l, j = 0; i <= r; i++, j++)
     {
         arr[i] = temp[j];
     }
     //deallocate memory
     delete[] temp;
}
