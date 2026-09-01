class Solution {
public:
    struct State{
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        int startRow = 0;
        int startCol = 0;
        int litterCount = 0;
        int litterBitPos[m][n];

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                litterBitPos[i][j] = -1;
                if (classroom[i][j] == 'S'){
                    startRow = i;
                    startCol = j;
                }else if(classroom[i][j] == 'L'){
                    litterBitPos[i][j] = litterCount;
                    litterCount++;
                }
            }
        }
        
        int allCollected = (1 << litterCount) - 1; // 2^litterCount - 1
        if(litterCount == 0){
            return 0;
        }
        
        VVVVB visited(m, VVVB(n, VVB(maxEnergy + 1, VB(1 << litterCount, false))));

        queue <State> que;
        que.push({startRow, startCol, maxEnergy, 0});
        visited[startRow][startCol][maxEnergy][0] = true;

        int moves = 0;
        while(!que.empty()){
            int currSize = que.size();

            while(currSize--){
                State curr = que.front();
                que.pop();

                if (curr.collectedMask == allCollected){
                    return moves;
                } else if(curr.energyLeft == 0){
                    continue;
                }

                for(auto &dir : directions){
                    int nextRow = curr.row + dir[0];
                    int nextCol = curr.col + dir[1];

                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n){
                        continue;
                    }

                    int nextCollectedMask = curr.collectedMask;
                    char cell = classroom[nextRow][nextCol];
                    int nextEnergy = curr.energyLeft - 1;

                    if (cell == 'X')
                        continue;
                    if (cell == 'R')
                        nextEnergy = maxEnergy;
                    if (cell == 'L'){
                        int p = litterBitPos[nextRow][nextCol];
                        nextCollectedMask |= 1 << p;
                    }
                    if(visited[nextRow][nextCol][nextEnergy][nextCollectedMask] == false){
                        visited[nextRow][nextCol][nextEnergy][nextCollectedMask] = true;
                        que.push({nextRow, nextCol, nextEnergy, nextCollectedMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
