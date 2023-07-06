// Quick Sort
// Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
// Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).
// Note: The low and high are inclusive.
// Implement the partition() and quickSort() functions to sort the array.
void quickSort(int arr[], int low, int high)
    {
     
        if(low<high)
        {
            int p=partition(arr,low,high);
            
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int p=low;
       int pivot=arr[high];
       
       for(int i=low;i<high;i++)
       {
           if(arr[i]<pivot)
           {
               swap(arr[i],arr[p]);
               p++;
           }
       }
       
       swap(arr[p],arr[high]);
       return p;
    }