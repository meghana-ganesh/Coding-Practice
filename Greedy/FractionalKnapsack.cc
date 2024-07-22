//TC:O(NlogN) + O(N)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool comp(Item val1,Item val2)
    {
        if((double)val1.value/val1.weight >= (double)val2.value/val2.weight)
            return true;
        return false;
    }
    double fractionalKnapsack(int w, Item arr[], int n) 
    {
        // Your code here
        double totVal = 0;
        sort(arr,arr+n,comp);
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight <= w)
            {
                totVal += (double)arr[i].value;
                w = w - arr[i].weight;
            }
            else
            {
                totVal += ((double)arr[i].value/arr[i].weight)*w;
                break;
            }
        }
        return totVal;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
