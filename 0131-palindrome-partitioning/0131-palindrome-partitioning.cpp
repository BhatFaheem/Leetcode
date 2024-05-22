class Solution {
public:
    vector<vector<string>> ans;
    bool is_palin(string & s)
    {
        int i = 0 , j = s.size()-1;
        while(i <= j)
        {
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int ind , int n , string &s , vector<string> & path)
    {
        if(ind == n)
        {
            ans.push_back(path);
            return;
        }
        for(int i = ind ; i < n ; i++)
        {
            string str = s.substr(ind , i-ind+1);
            if(is_palin(str))
            {
                path.push_back(str);
                f(i+1 , n , s , path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string>path;
        f(0 , n , s , path);
        return ans;
    }
};