class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int cnt = 0;
        for(int i = 0 ; tickets[k] > 0 ; i++)
        {
            if(tickets[i%n] != 0)
            {
                tickets[i%n]--;
                cnt++; 
            }
            if(tickets[k] == 0) break;
        }
        return cnt;
    }
};