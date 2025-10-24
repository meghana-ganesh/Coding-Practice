//O(n * m)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int res = 0;
        for(string s : operations)
        {
            if(s.find("+X") != string :: npos)
                ++res;
            else if(s.find("-X") != string :: npos)
                --res;
            else if(s.find("X+") != string :: npos)
                res++;
            else if(s.find("X-") != string :: npos)
                res--;
        }
        return res;
    }
};
