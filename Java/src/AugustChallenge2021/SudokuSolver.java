package AugustChallenge2021;

public class SudokuSolver {
    static int n = 3;
    static int N = n*n;
    static int[][] rows = new int[N][N+1];
    static int[][] columns = new int[N][N+1];
    static int[][] boxes = new int[N][N+1];

    static char[][] board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}};
    static boolean sudokuSovled = false;
    static public void placeNumber(int d, int row, int col){
        int idx = (row/n)*n + col/n;
        rows[row][d]++;
        columns[col][d]++;
        boxes[idx][d]++;
        board[row][col] = (char)(d+'0');
    }
    public static boolean countPlace(int d, int row, int col){
        int idx = (row/n)*n + col/n;
        return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
    }

    public static void placeNextNumbers(int row, int col){
        if(row == N-1 && col == N-1){
            sudokuSovled = true;
        } else {
            if(col == N-1) backtrack(row+1, 0);
            else backtrack(row, col+1);
        }
    }
    public static void removeNumber(int d, int row, int col){
        int idx = (row/n)*n + col/n;
        rows[row][d]--;
        columns[col][d]--;
        boxes[idx][d]--;
        board[row][col] = '.';
    }
    public static void backtrack(int row, int col){
        if(board[row][col] == '.'){
            for(int d = 1; d < 10; d++){
                if(countPlace(d, row, col)){
                    placeNumber(d, row, col);
                    placeNextNumbers(row, col);
                    if(!sudokuSovled) removeNumber(d, row, col);
                }
            }
        }
        else placeNextNumbers(row, col);
    }
    public static void solveSudoku(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] != '.'){
                    int d = Character.getNumericValue(board[i][j]);
                    placeNumber(d, i, j);
                }
            }
        }
        backtrack(0, 0);
    }


    public static void main(String[] args) {
        solveSudoku();
        for(int i = 0; i < board.length; i++){
            if(i%3 == 0 && i != 0)
                System.out.println("___________________");
            for(int j = 0; j < board[i].length; j++){
                if(j%3 == 0) System.out.print("|");
                if(j%3 == 2) System.out.print(board[i][j]);
                else System.out.print(board[i][j] + " ");
            }
            System.out.print("|");
            System.out.println();
        }
    }
}
