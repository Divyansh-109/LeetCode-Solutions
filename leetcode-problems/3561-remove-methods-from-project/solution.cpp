class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector <vector<int>> graph(n);

        for (auto &edge: invocations){
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
        }

        vector <bool> suspicious(n);
        queue <int> q;

        q.push(k);
        suspicious[k] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for (int v : graph[u]){
                if (!suspicious[v]){
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        for (auto &edge: invocations){
            int a = edge[0];
            int b = edge[1];

            if (!suspicious[a] && suspicious[b]){
                vector <int> ans;

                for (int i = 0; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector <int> ans;
        for (int i = 0; i < n; i++){
            if(!suspicious[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
