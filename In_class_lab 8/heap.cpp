#include <iostream>
using namespace std;
  
// function to heapify the tree
void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root; 
   int left = 2*root+1;
   int right = 2*root+2;
   /*While representing a heap as an array, assuming the index starts at 0, the root element is stored at 0. In general, if a parent node is at the position i, then the left child node is at the position (2*i + 1) and the right node is at (2*i +2). */
    
    // Find the largest value from root, left node and the right node.If there is a new largest number, swap them.
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest!=root)
    {    
        swap(&arr[root], &arr[largest]); 
        heapify(arr,n,largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i-- )
        heapify(arr, n, i);
   // extracting elements from heap one by one
   for (int j = n - 1; j >= 0; j--)
    {
        swap(&arr[0], &arr[j]);
        heapify(arr, j, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6,11,25,1,35,-1,89,-2,10,-3,-1,-8,49,111,12,35};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}