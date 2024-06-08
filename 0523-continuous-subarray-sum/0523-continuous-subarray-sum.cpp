class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n); pref[0] = nums[0];
        for(int i = 1 ; i < n ; i++) pref[i] = pref[i-1] + nums[i];
        map<int , int> mp;
        mp[0] = -1;
        for(int i = 0 ; i < n ; i++)
        {
            int val = pref[i] % k;
            if(mp.count(val))
            {
                if(i - mp[val] > 1) return true;
            }
            else
            {
                mp[val] = i;
            }
        }
        return false;
    }
};