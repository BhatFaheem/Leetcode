class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        set<pair<int ,int>>st;
        for(int i = 0 ; i < n ; i++) st.insert({score[i] , i});
        int cnt = 1;
        while(!st.empty())
        {
            pair<int , int> p = *(st.rbegin());
            st.erase(p);
            if(cnt == 1)ans[p.second] = "Gold Medal";
            else if(cnt == 2)ans[p.second] = "Silver Medal";
            else if(cnt == 3)ans[p.second] = "Bronze Medal";
            else ans[p.second] = to_string(cnt);
            cnt++;
        }
        return ans;
    }
};