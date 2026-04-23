
#include <iostream>
#include <vector>
#include <string>

class TicTacToeValidator {
public:
    // Check if a player has won
    bool hasWon(const std::vector<std::string>& board, char player) {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;
            }
        }
        
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
                return true;
            }
        }
        
        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }
        
        return false;
    }
    
    // Count occurrences of a character
    int countChar(const std::vector<std::string>& board, char c) {
        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == c) {
                    count++;
                }
            }
        }
        return count;
    }
    
    // Check if board is full
    bool isFull(const std::vector<std::string>& board) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    return false;
                }
            }
        }
        return true;
    }
    
    std::string solve(const std::vector<std::string>& board) {
        int countX = countChar(board, 'x');
        int countO = countChar(board, 'o');
        
        bool xWins = hasWon(board, 'x');
        bool oWins = hasWon(board, 'o');
        
        // Check for invalid count
        if (countX < countO || countX > countO + 1) {
            return "invalid";
        }
        
        // Both players can't win
        if (xWins && oWins) {
            return "invalid";
        }
        
        // If x wins, must have one more x than o
        if (xWins && countX != countO + 1) {
            return "invalid";
        }
        
        // If o wins, must have same number of x and o
        if (oWins && countX != countO) {
            return "invalid";
        }
        
        // Valid win conditions
        if (xWins) {
            return "win";
        }
        if (oWins) {
            return "lose";
        }
        
        // Check for tie
        if (isFull(board)) {
            return "tie";
        }
        
        // Game is still ongoing
        return "ongoing";
    }
};

int main() {
    std::vector<std::string> board(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> board[i];
    }
    
    TicTacToeValidator validator;
    std::cout << validator.solve(board) << std::endl;
    
    return 0;
}
