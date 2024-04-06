class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<int>vis(n , 0);
        int l_1 = 0 , r_1 = 0 , l_2 = 0 , r_2 = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')l_1++;
            if(s[i] == ')')r_1++;
            if(s[n-1-i] == '(')l_2++;
            if(s[n-1-i] == ')')r_2++;
            if(l_1 < r_1)
            {
                r_1-- , vis[i] = 1; 
            }
            if(l_2 > r_2)
            {
                l_2--;
                vis[n-1-i] = 1;
            }
        }
        string ans = "";
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i]) ans += s[i];
        }
        return ans;
    }
};