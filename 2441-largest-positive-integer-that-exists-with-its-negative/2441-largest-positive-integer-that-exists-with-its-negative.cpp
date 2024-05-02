class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int , int> mp;
        int ans = -1;
        for(auto n : nums)
        {
                if(mp.count((-n)))
                {
                    ans = max(ans , abs(n));
                }
                mp[n]++;
        }
        return ans;
    }
};