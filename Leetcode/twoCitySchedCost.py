class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda cost: cost[1]-cost[0], reverse=True)

        min_cost = 0
        costs_count = len(costs)
        half_count = int(costs_count/2)

        for idx in range(0,half_count):
            min_cost += costs[idx][0]

        for idx in range(half_count,costs_count):
            min_cost += costs[idx][1]

        return min_cost




            
