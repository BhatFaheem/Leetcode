class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int n = people.size();
        int i =0 , j = n-1;
        int boats = 0;
        while(i <= j)
        {
            int total = people[j];
            boats++;
            if(total + people[i] <= limit)i++;
            j--;
        }
        return boats;
    }
};