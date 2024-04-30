class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int N = word.length();
        unordered_map<int, int> freq;
        freq[0] = 1;
        int mask = 0;
        long long res = 0LL;
        for (int i = 0; i < N; i++) {
            char c = word[i];
            int bit = c - 'a';
            mask ^= (1 << bit);
            res += freq[mask];
            freq[mask]++;
            for (int odd_c = 0; odd_c < 10; odd_c++) {
                res += freq[mask ^ (1 << odd_c)];
            }
        }
        return res;
    }
};
