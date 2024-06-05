//TC:O(N) + O(logN) - for sorting first
string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}


//TC:O(NlogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more) != mpp.end())
            {
                ans.push_back(mpp[more]);
                ans.push_back(i);
                return ans;
            }
            mpp[a] = i;
        }
        return ans;
    }
};



//TC:O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();i++)
            {
                if(i == j)
                    continue;
                if(nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
