//TC: O(K-n) * log base 10 n, where K = 1666666
class Solution {
public:
    int nextBeautifulNumber(int n) 
    {
        for(int i=n+1;i<=1666666;i++)
        {
            vector<int> frequencyMap(10,0);
            int num = i;
            while(num > 0)
            {
                frequencyMap[num%10]++;
                num = num/10;
            }
            bool flag = true;
            if(frequencyMap[0] != 0)
                flag = false;
            for(int d=1;d<10;d++)
            {
                if(frequencyMap[d] != 0 && frequencyMap[d] != d)
                    flag = false;
            }
            if(flag)
                return i;
        }
        return -1;
    }
};
