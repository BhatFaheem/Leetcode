class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ans = 0;
        int n = words.size();
        for(int mask = 1 ; mask < (1 << n) ; mask++)
        {
            bool flag = true;
            int m = letters.size();
            vector<int>temp(26 , 0);
            for(auto l : letters) temp[l -'a']++;
            int res = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if((mask >> j)&1)
                {
                    for(auto w : words[j])
                    {
                        if(temp[w-'a'] > 0) res += score[w-'a'] , temp[w-'a']--;
                        else flag &= false;
                    }
                }
            } 
            if(flag) ans = max(ans , res);
        }
        return ans;
    }
};