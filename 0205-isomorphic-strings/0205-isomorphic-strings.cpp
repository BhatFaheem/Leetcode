class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char , char> mp , mp2;
        if(s.size() != t.size()) return false;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(mp.count(s[i]) || mp2.count(t[i]))
            {
                if(t[i] != mp[s[i]] || s[i] != mp2[t[i]]) return false;
            }
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};