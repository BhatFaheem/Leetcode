class Solution {
public:
int f(vector<int>& nums , int k)
{
    int n = nums.size();
    int i = 0 , j = 0 , ans = 0;
    map<int , int> mp;
    for(i = 0 ; i < n ; i++)
    {
        mp[nums[i]]++;
        while(mp.size() > k)
        {
            mp[nums[j]]--;
            if(mp[nums[j]] == 0) mp.erase(nums[j]);
            j++;
        }
        ans += (i-j+1);
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = f(nums , k) - f(nums , k-1);
        return ans;
    }
};