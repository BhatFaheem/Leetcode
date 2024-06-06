class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        multiset<int>st(hand.begin() , hand.end());
        while(st.size() > 0)
        {
            int sz = k;
            int num = -1;
            int cnt = 0;
            while(sz-- && st.size() > 0)
            {
                if(num == -1)
                {
                    cnt++;
                    num = *(st.begin());
                    st.erase(st.lower_bound(num));
                }
                else
                {
                    if(st.count(num+1))
                    {
                        cnt++;
                        num++;
                        st.erase(st.lower_bound(num));
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(cnt < k) return false;
        }
        return true;
    }
};