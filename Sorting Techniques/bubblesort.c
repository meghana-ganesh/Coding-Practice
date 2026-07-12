//pushes largest element to the end by doing adjacent swaps
//TC: Best case O(n) , worst case O(n^2)
void bubbleSort(int arr[], int n) 
{
    //write your code here
    int didSwap = 0; //for optimised bubble sort
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                int didSwap = 1;
            }
        }
        //optimised bubble sort
        if(didSwap == 0)
            break;
            
    }
}
