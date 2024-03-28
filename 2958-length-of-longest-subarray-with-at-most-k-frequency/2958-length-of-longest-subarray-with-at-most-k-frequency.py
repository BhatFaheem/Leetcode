class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        ans = 0
        i , j = 0 , 0
        n = len(nums)
        while j < n:
            mp[nums[j]] += 1
            if mp[nums[j]] > k:
                while i <= j :
                    mp[nums[i]] -= 1
                    i += 1
                    if mp[nums[j]] <= k:
                        break
            ans = max(ans , j-i+1)
            j += 1
        return ans
            
        