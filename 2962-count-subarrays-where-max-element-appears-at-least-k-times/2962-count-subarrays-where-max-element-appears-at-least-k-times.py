class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        temp = []
        n = len(nums)
        maxi = max(nums)
        for i in range(n):
            if nums[i] == maxi : temp.append(i)
        ans , m = 0 , len(temp)
        for i in range(0 ,m-k+1):
            l , r  = temp[i] , n
            if i is not 0: l = l - temp[i-1]-1
            l += 1
            r -= temp[i+k-1]
            ans = ans + (l * r)
        return ans
            
                
    
                
        