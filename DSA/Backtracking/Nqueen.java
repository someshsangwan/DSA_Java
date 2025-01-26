package Backtracking;

public class Nqueen {
    // Function to print the chessboard
    private static void printBoard(int[][] board, int N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    System.out.print("Q ");
                } else {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }

    // Function to check if a queen can be placed at board[row][col]
    private static boolean isSafe(int[][] board, int row, int col, int N) {
        // Check the row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 1) {
                return false;
            }
        }

        // Check the upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check the lower-left diagonal
        for (int i = row, j = col; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    // Recursive function to solve the N-Queens problem
    private static boolean solveNQueens(int[][] board, int col, int N) {
        // Base case: If all queens are placed, return true
        if (col >= N) {
            printBoard(board, N); // Print the solution
            return true;
        }

        boolean foundSolution = false;

        // Try placing a queen in each row of the current column
        for (int row = 0; row < N; row++) {
            if (isSafe(board, row, col, N)) {
                // Place the queen
                board[row][col] = 1;

                // Recur to place the rest of the queens
                foundSolution = solveNQueens(board, col + 1, N) || foundSolution;

                // Backtrack: Remove the queen
                board[row][col] = 0;
            }
        }

        return foundSolution;
    }

    // Main function to solve the N-Queens problem
    public static void solveNQueens(int N) {
        int[][] board = new int[N][N]; // Initialize the chessboard
        if (!solveNQueens(board, 0, N)) {
            System.out.println("No solution exists for N = " + N);
        }
    }

    // Main method
    public static void main(String[] args) {
        int N = 8; // Change this value for different board sizes
        solveNQueens(N);
    }
}
