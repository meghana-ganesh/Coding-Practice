//TC:O(NlogN + MlogM + M) - optimised solution,two pointer approach
//SC:O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cookieIndex = 0;
        int childIndex = 0;
        int satisfiedChildren = 0;
        while(childIndex < g.size() && cookieIndex < s.size())
        {
            if(s[cookieIndex] >= g[childIndex])
            {
                cookieIndex++;
                childIndex++;
                satisfiedChildren++;
            }
            else
                cookieIndex++;
        }
        return satisfiedChildren;
    }
};

//Brute force - O(MlogM + NlogN + M*N) - TLE
//SC:O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
       sort(g.begin(), g.end());
        sort(s.begin(), s.end());
 
        // This stores whether a cookie has already been assigned.
        vector<bool> used(s.size(), false);
 
        int satisfiedChildren = 0;
 
        for (int childIndex = 0; childIndex < g.size(); childIndex++) {
            for (int cookieIndex = 0; cookieIndex < s.size(); cookieIndex++) {
                if (!used[cookieIndex] && s[cookieIndex] >= g[childIndex]) {
                    used[cookieIndex] = true;
                    satisfiedChildren++;
                    break;
                }
            }
        }
 
        return satisfiedChildren;
    }
};
