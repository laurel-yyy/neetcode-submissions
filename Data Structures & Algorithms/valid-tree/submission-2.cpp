class Solution {
public:
    bool ans = true;
    vector<bool> visited;
    unordered_map<int, vector<int>> graph;
    void dfs(int cur, int prev){
            if(visited[cur]){ans = false; return;}
            visited[cur] = true;
            for(auto next: graph[cur]){
                if(next != prev){
                    dfs(next, cur);
                }
            }
    };
    bool validTree(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, false);
        for(int i=0; i<edges.size(); ++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, -1);
        if(!ans)return false;
        for(auto v : visited){
            if(!v)return false;
        }
        return true;

    
    }
};
