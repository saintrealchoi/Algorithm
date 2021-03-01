class Solution {
public:
    vector<vector<int>> answer;
    vector<int> v;
    int N;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        N = graph.size() - 1;
        BT(graph, 0);
        return answer;
    }

    void BT(vector<vector<int>> graph, int V) {
        v.emplace_back(V);
        if (V == N) answer.emplace_back(v);
        else for (auto node : graph[V]) BT(graph, node);
        v.pop_back();
    }
};