class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int left = 0 , right = 0;
        int maxi = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')left++;
            if(s[i] == ')')right++;
            maxi = max(maxi , left-right);
        }
        return maxi;
    }
};