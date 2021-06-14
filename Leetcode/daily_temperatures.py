class Solution(object):
    def dailyTemperatures(self, temperatures):
        res = [0] * len(temperatures)
        stack = []
        
        for i in range(len(temperatures)-1, -1, -1):
            while stack and temperatures[stack[-1]] <= temperatures[i]:
                stack.pop()
            if not stack:
                stack.append(i)
            else:
                res[i] = stack[-1] - i
                stack.append(i)
        return res