class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int , int> mp;
        mp[0] = 1;
        int sum = 0;
        int cnt = 0;
        for(auto n : nums)
        {
            sum = ((sum + n) % k + k)%k;
            if(mp.count(sum))cnt += mp[sum];
            mp[sum]++;
        }
        return cnt;
    }
};