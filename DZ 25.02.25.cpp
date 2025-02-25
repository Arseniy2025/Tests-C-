#include <iostream>
struct Piece {
    char symbol; 
    bool isWhite; 
};

class ChessBoard {
private:
    static const int size = 8;
    Piece board[size][size];

public:
    ChessBoard() {
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                board[i][j] = { '.', false }; 
            }
        }
    }

    void placePiece(int row, int col, char symbol, bool isWhite) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            board[row][col] = { symbol, isWhite };
        }
    }

    void printBoard() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if ((i + j) % 2 == 0) {
                    std::cout << "#"; 
                }
                else {
                    std::cout << " "; 
                }

                
                std::cout << board[i][j].symbol;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    ChessBoard chessBoard;
    chessBoard.placePiece(0, 4, 'K', true);

    chessBoard.placePiece(7, 3, 'Q', false);

    chessBoard.printBoard();

    return 0;
}
