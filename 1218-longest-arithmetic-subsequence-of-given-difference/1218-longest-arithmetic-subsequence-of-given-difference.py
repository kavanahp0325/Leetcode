class Solution(object):
    def longestSubsequence(self, arr, d):
        max_l=1
        dp={}
        for i in arr:
            if i-d in dp:
                dp[i]=dp[i-d]+1
            else:
                dp[i]=1
            max_l=max(max_l,dp[i])
        return max_l

        