class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0ll;
        sort(happiness.begin() , happiness.end());
        int n = happiness.size();
        for(int i = 0 ; i < n && k > 0 ; i++, k--)
        {
            ans += max(0ll , 1LL * (happiness[n-1-i] - i));
        }
        return ans;
    }
};