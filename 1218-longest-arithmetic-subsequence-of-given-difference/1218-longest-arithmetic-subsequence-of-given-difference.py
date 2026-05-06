class Solution(object):
    def longestSubsequence(self, arr, difference):
        max_l=1
        dp={}
        for i in arr:
            if i-difference in dp:
                dp[i]=dp[i-difference]+1
            else:
                dp[i]=1
            max_l=max(max_l,dp[i])
        return max_l

        