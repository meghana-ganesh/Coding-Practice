//TC:O(N)
//SC:O(1)
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if (n == 0) return 0;

        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int total = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= leftMax) {
                    leftMax = height[l];
                } else {
                    total += leftMax - height[l];
                }
                l++;
            } else {
                if (height[r] >= rightMax) {
                    rightMax = height[r];
                } else {
                    total += rightMax - height[r];
                }
                r--;
            }
        }
        return total;
    }
};


//TC:O(N)
//SC:O(N)
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int total = 0;
        int n = height.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMax(n,0);
        prefixMax[0] = height[0];
        for(int i=1;i<n;i++)
        {
            prefixMax[i] = max(prefixMax[i-1],height[i]);
        }
        suffixMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }
        for(int i=0;i<height.size();i++)
        {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            total += min(leftMax,rightMax) - height[i];
        }
        return total;
    }
};
