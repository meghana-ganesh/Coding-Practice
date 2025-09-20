//TC: O(N1+N2) : O(N1) - nums1 itertion at the end + O(2N2) - (constant omitted, but stack operation also comes to O(N2) as an additive value instead of multiplicative
//mostly intuition, “amortized analysis” case
//Amortized view
//In the worst case for a single iteration, the while loop can run a lot (say you pop many items at once).
//But those pops “use up” stack elements — so future iterations won’t need to pop them again. -MOST IMPORTANT LINE
//That’s why you don’t multiply n2 * n2. You sum the total number of pushes and pops over the whole execution.
//Thus:
//Total stack operations ≤ 𝑛2 pushes + 𝑛2 pops = 𝑂(𝑛2)
  
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int> nextGreater;
        stack<int> st;
        for(int i=n2-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int num : nums1)
        {
            res.push_back(nextGreater[num]);
        }
        return res;
    }
};
