class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        map<int , int> mp;
        for(auto a : arr1)mp[a]++;
        for(auto a : arr2)
        {
            while(mp[a] > 0)
            {
                ans.push_back(a);
                mp[a]--;
            }
            mp.erase(a);
        }
        for(auto m : mp)
        {
            int val = m.second;
            while(val--)
            {
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};