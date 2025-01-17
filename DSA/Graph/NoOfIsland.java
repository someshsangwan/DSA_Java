package Graph;

import java.util.*;

class Solution {
    public int numIslands(char[][] grid) {
        int islands = 0;
        int rows = grid.length;
        int cols = grid[0].length;
        boolean [][] vis=new boolean[rows][cols];
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && vis[r][c]==false) {
                    islands++;
                    bfs(grid, r, c, vis, directions, rows, cols);
                }
            }
        }

        return islands;        
    }

    private void bfs(char[][] grid, int r, int c, boolean [][] vis, int[][] directions, int rows, int cols) {
        Queue<int[]> q = new LinkedList<>();
        vis[r][c]=true;
        q.add(new int[]{r, c});

        while (!q.isEmpty()) {
            int[] point = q.poll();
            int row = point[0], col = point[1];

            for (int[] direction : directions) {
                int nr = row + direction[0], nc = col + direction[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && vis[nr][nc]==false) {
                    q.add(new int[]{nr, nc});
                    vis[nr][nc]=true;
                }
            }
        }
    }    
}