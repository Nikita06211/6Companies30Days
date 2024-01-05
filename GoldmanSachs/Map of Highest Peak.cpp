class Solution {
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, -1));
        std::queue<std::pair<int, int>> q;

        // Initialize water cells and push them to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            // Check neighbors
            std::vector<std::pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (const auto& neighbor : neighbors) {
                int ni = i + neighbor.first;
                int nj = j + neighbor.second;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && ans[ni][nj] == -1) {
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return ans;
    }
};
