class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long ans = 0;
        for(auto n : nums) ans += (1LL * n);
        vector<pair<int ,int>> vp1 , vp2;
        long long res = 0;
        for(auto n : nums)
        {
            int xor_val = n^k;
            if(xor_val > n)vp1.push_back({xor_val , n});
            else vp2.push_back({xor_val , n});
            res += (1LL * max(xor_val ,n));
        }
        int mini = 0;
        if(vp1.size()&1)
        {
            mini = INT_MAX;
            for(auto v : vp1)mini = min(mini , v.first - v.second);
            for(auto v : vp2)mini = min(mini , v.second - v.first);
        }
        return max(ans , res-mini);
        
    }
};