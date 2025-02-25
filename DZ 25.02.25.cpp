#include <iostream>
using namespace std;
struct Piece {
    char symbol;
    bool isWhite;
};

class ChessBoard {
private:
    int size; 
    Piece** board; 

public:
    ChessBoard(int boardSize = 8) : size(boardSize) {
        board = new Piece * [size];
        for (int i = 0; i < size; ++i) {
            board[i] = new Piece[size];
        }

        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                board[i][j] = { '.', false };
            }
        }
    }

    
    ~ChessBoard() {
        for (int i = 0; i < size; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    void placePiece(int row, int col, char symbol, bool isWhite) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            board[row][col] = { symbol, isWhite };
        }
    }

    void printBoard() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if ((i + j) % 2 == 0) {
                    cout << "#";
                }
                else {
                    cout << " ";
                }

                cout << board[i][j].symbol;
            }
            cout << std::endl;
        }
    }
};

int main() {
    ChessBoard chessBoard(10); 
    

    chessBoard.printBoard();

    return 0;
}
