import java.util.*; 
import java.io.*; 

public class Solution {
    
    private static boolean checkWinner(char[][] board, char player) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true;
            }
        }
        
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }
        
        return false;
    }

    public static String ticTacToeWinner(ArrayList<ArrayList<Integer>> moves, int n) {
        char[][] board = new char[3][3];
        for (int i = 0; i < 3; i++) {
            Arrays.fill(board[i], '_');
        }
        
        char currentPlayer = 'X';
        
        for (int i = 0; i < moves.size(); i++) {
            ArrayList<Integer> move = moves.get(i);
            int row = move.get(0);
            int col = move.get(1);
            
            board[row][col] = currentPlayer;
            
            if (checkWinner(board, currentPlayer)) {
                return (currentPlayer == 'X') ? "player1" : "player2";
            }
            
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        
        boolean movesLeft = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    movesLeft = true;
                    break;
                }
            }
        }
        
        if (movesLeft) {
            return "uncertain";
        }
        
        return "draw";
    }
}
