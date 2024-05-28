class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        int curr_cost = 0;
        int i = 0 , j = 0;
        while(j < n)
        {
            int req = abs(s[j] - t[j]);
            if(req + curr_cost <= maxCost)
            {
                ans = max(ans , j-i+1);
                curr_cost += req;
                j++;
            }
            else
            {
                if(i == j)i++ , j++;
                else curr_cost -= abs(s[i] - t[i]) , i++;
            }
        }
        return ans;
    }
};