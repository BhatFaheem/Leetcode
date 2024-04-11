class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char>st;
        for(int i = 0 ; i < n ; i++)
        {
            if(st.size() == 0)st.push(s[i]);
            else
            {
                if(k <= 0)st.push(s[i]);
                else
                {
                    while(k > 0 && st.size() > 0 && st.top() > s[i])
                    {
                        st.pop();
                        k--;
                    }
                    st.push(s[i]);
                }
            }
        }
        while(k > 0)st.pop() , k--;
        if(st.size() == 0) return "0";
        string ans = "";
        while(st.size() > 0) ans += st.top() , st.pop();
        while(ans.size() > 1 && ans.back() == '0')ans.pop_back();
        reverse(ans.begin() , ans.end());
        return ans;
    }
};