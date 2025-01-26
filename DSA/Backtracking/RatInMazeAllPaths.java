package Backtracking;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RatInMazeAllPaths {
    // Size of the maze
    static int N;

    // Utility function to check if x, y is valid index for N*N maze
    boolean isSafe(int[][] maze, int x, int y) {
        // Check if x and y are within bounds and the cell is not a wall
        return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
    }

    // Function to find all paths from (0, 0) to (N-1, N-1)
    List<String> findPaths(int[][] maze) {
        List<String> paths = new ArrayList<>();
        if (maze[0][0] == 0 || maze[N - 1][N - 1] == 0) {
            return paths; // No paths if start or end is blocked
        }

        boolean[][] visited = new boolean[N][N];
        findPathsUtil(maze, 0, 0, "", visited, paths);

        // Sort the paths lexicographically
        Collections.sort(paths);
        return paths;
    }

    // A recursive utility function to find all paths
    void findPathsUtil(int[][] maze, int x, int y, String path, boolean[][] visited, List<String> paths) {
        // If (x, y) is the destination, add the path to the list
        if (x == N - 1 && y == N - 1) {
            paths.add(path);
            return;
        }

        // Mark x, y as visited
        visited[x][y] = true;

        // Move Down
        if (isSafe(maze, x + 1, y) && !visited[x + 1][y]) {
            findPathsUtil(maze, x + 1, y, path + 'D', visited, paths);
        }

        // Move Left
        if (isSafe(maze, x, y - 1) && !visited[x][y - 1]) {
            findPathsUtil(maze, x, y - 1, path + 'L', visited, paths);
        }

        // Move Right
        if (isSafe(maze, x, y + 1) && !visited[x][y + 1]) {
            findPathsUtil(maze, x, y + 1, path + 'R', visited, paths);
        }

        // Move Up
        if (isSafe(maze, x - 1, y) && !visited[x - 1][y]) {
            findPathsUtil(maze, x - 1, y, path + 'U', visited, paths);
        }

        // Unmark x, y as visited (backtrack)
        visited[x][y] = false;
    }

    public static void main(String[] args) {
        RatInMazeAllPaths rat = new RatInMazeAllPaths();
        int[][] maze = {
                { 1, 0, 0, 0 },
                { 1, 1, 0, 1 },
                { 0, 1, 0, 0 },
                { 1, 1, 1, 1 }
        };

        N = maze.length;
        List<String> paths = rat.findPaths(maze);

        if (paths.isEmpty()) {
            System.out.println("No paths found");
        } else {
            System.out.println("All possible paths:");
            for (String path : paths) {
                System.out.println(path);
            }
        }
    }
}
