class Solution {
public:
    int numSteps(string s) {
        s = "0" + s;
        int n = s.size();
        int cnt = 0;
        int ones = count(s.begin() , s.end() , '1');
        while(true)
        {
            if(s[n-1] == '1')
            {
                if(ones == 1) break;
                for(int i = n-1 ; i >= 0 ; i--)
                {
                    if(s[i] == '1')s[i] = '0' , ones--;
                    else
                    {
                        s[i] = '1' , ones++;
                        break;
                    }
                }
            }
            else
            {
                for(int i = n-2 ; i >= 0 ; i--)
                {
                    if(s[i] == '1')s[i+1] = '1' , s[i] = '0';
                }
            }
            cnt++;
        }
        return cnt;
    }
};