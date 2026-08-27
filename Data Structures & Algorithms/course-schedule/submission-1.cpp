class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<bool> visited(numCourses, false);
        unordered_map<int, vector<int>> graph;
        for(auto pre : prerequisites){
            indegree[pre[0]]++;
            graph[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(indegree[i] == 0){
                q.push(i);
                visited[i] = true;
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto next : graph[cur]){
                --indegree[next];
                if(indegree[next] == 0 && !visited[next]){
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        for(auto v: visited){
            if(v == false)return false;
        }
        return true;
    }
};
