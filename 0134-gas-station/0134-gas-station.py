class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        if sum(gas)<sum(cost):
            return -1
        n=len(gas)
        g=0
        startind=0
        for i in range(n):
            g=g+gas[i]-cost[i]
            if g<0:
                g=0
                startind=i+1
        return startind
        