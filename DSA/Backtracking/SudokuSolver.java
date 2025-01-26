package Backtracking;

public class SudokuSolver {
    // Function to print the Sudoku grid
    private static void printGrid(int[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Function to check if placing a number is valid
    private static boolean isSafe(int[][] board, int row, int col, int num) {
        // Check if the number is already in the row
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) {
                return false;
            }
        }

        // Check if the number is already in the column
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) {
                return false;
            }
        }

        // Check if the number is already in the 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    // Recursive function to solve the Sudoku
    private static boolean solveSudoku(int[][] board) {
        // Traverse the grid to find an empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == 0) { // Empty cell found
                    // Try placing numbers 1 to 9 in the empty cell
                    for (int num = 1; num <= 9; num++) {
                        if (isSafe(board, row, col, num)) {
                            // Place the number
                            board[row][col] = num;

                            // Recur to solve the rest of the grid
                            if (solveSudoku(board)) {
                                return true;
                            }

                            // Backtrack: Remove the number
                            board[row][col] = 0;
                        }
                    }

                    // If no number can be placed, return false
                    return false;
                }
            }
        }

        // If no empty cell is left, the Sudoku is solved
        return true;
    }

    // Main method
    public static void main(String[] args) {
        // Example Sudoku puzzle (0 represents empty cells)
        int[][] board = {
                { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
        };

        // Solve the Sudoku and print the result
        if (solveSudoku(board)) {
            System.out.println("Solved Sudoku:");
            printGrid(board);
        } else {
            System.out.println("No solution exists.");
        }
    }
}
