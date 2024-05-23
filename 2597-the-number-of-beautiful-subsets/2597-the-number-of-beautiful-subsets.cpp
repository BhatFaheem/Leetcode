class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int K) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int mask = (1 << n);
        int cnt = 0;
        vector<int>vis(2001 , 0);
        for(int i = 1 ; i < mask ; i++)
        {
            vector<int>temp;
            for(int j = 0 ; j < n ; j++)
            {
                if((i >> j)&1)vis[nums[j]]++;
            }
            bool flag = true;
            for(int j = 0 ; j < n ; j++)
            {
                if(vis[nums[j]] && vis[nums[j] + K])flag &= false;
                if(vis[nums[j]])vis[nums[j]]--;
            }
            cnt += (flag);
        }
        return cnt;
    }
};