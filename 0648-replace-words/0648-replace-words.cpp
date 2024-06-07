class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string , int> mp;
        for(auto d : dictionary)mp[d]++;
        int n = sentence.size();
        string ans = "";
        string word = "";
        string add = "";
        for(int i = 0 ; i < n ; i++)
        {
            if(sentence[i] == ' ')
            {
                if(add.size() > 0) ans += add;
                else ans += word;
                add = "";
                word = "";
                ans += " ";
            }
            else
            {
                word += sentence[i];
                if(mp.count(word) && add.size() == 0) add = word;
            }
        }
        if(add.size() > 0) ans += add;
        else ans += word;
        return  ans;
    }
};