//select minimums and swap
//TC : Best case,worst case, avg case O(n^2)
void selectionSort(vector<int> &arr) {
        // code here
        int i,j;
        for(i=0;i<arr.size();i++){
            int min = i;
            for(j=i+1;j<=arr.size()-1;j++){
                if(arr[j]<arr[min]){
                    min = j;
                }
            }
            swap(arr[i],arr[min]);
        }
    }
