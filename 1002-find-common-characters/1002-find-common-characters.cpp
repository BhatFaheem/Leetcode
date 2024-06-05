class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>f(26 , 1e5);
        for(auto w : words)
        {
            vector<int>temp(26 , 0);
            for(auto x : w)temp[x-'a']++;
            for(int i = 0 ; i < 26 ; i++) f[i] = min(f[i] , temp[i]);
        }
        vector<string> ans;
        for(int i = 0 ; i < 26 ; i++)
        {
            for(int j = 0 ; j < f[i] ; j++)
            {
                string str;
                str.push_back(('a' + i));
                ans.push_back(str);
            }
        }
        return ans;
    }
};