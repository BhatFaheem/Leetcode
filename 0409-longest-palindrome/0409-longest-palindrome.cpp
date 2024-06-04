class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        vector<int>cnt(52 , 0);
        for(auto x : s)
        {
            if(x >= 'a' && x <= 'z')cnt[x-'a']++;
            else cnt[26 + (x - 'A')]++;
        }
        int ans = 0 , odd = 0;
        for(auto c : cnt)
        {
            ans += (c - (c&1));
            if(c&1)odd = 1;
        }
        return ans + odd;
    }
};