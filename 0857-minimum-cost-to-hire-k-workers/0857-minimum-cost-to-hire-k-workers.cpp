class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = 1e9;
        int n = quality.size();
        vector<pair<double , int>>vp;
        for(int i = 0 ; i < n ; i++)
        {
            vp.push_back({1.00000 * wage[i] / quality[i] , quality[i]});
        }
        sort(vp.begin() , vp.end());
        priority_queue<int>pq;
        double val = 0.0;
        for(int i = 0 ; i < n ; i++)
        {
            pq.push(vp[i].second);
            val += vp[i].second;
            if(pq.size() > k) val -= pq.top() , pq.pop();
            if(pq.size() == k)
            {
                ans = min(ans , val*vp[i].first);
            }
        }
        return ans;
    }
};