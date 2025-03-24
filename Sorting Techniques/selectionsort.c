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
