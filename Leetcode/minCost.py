class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        if len(cost) <= 1:
            return 0

        answer = 0
        maxcost = 0
        ptr = ""

        for i,ch in enumerate(cost):
            if s[i] != ptr:
                ptr = s[i]
                maxcost = ch
            else :
                if maxcost < ch:
                    answer += maxcost
                    maxcost = ch
                else:
                    answer += ch
        return answer
        
