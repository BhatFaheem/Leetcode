class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 1 , e = n-1;
        while(s < e)
        {
            int mid = s + (e-s)/2;
            int cnt = 0;
            for(int n : nums) cnt += (n <= mid);
            if(cnt <= mid) s = mid+1;
            else e = mid;
        }
        return s;
    }
};