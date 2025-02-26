#include <iostream>
#include <string>
using namespace std;

class fig {
protected:
    string name;
    int x;
    int y;
    bool Ismoved = false;
public:
    fig() {
        name = "";
        x = 0;
        y = 0;
    }
    fig(int x1, int y1, string name1) {
        name = name1;
        x = x1;
        y = y1;
    }

    virtual char getSymbol() const = 0; 
};

class hor : public fig {
public:
    hor(int x1, int y1, string name1) : fig(x1, y1, name1) {}

    char getSymbol() const override {
        return 'H';
    }

    void Go(int os) {
        switch (os) {
        case 1:
            y += 2;
            x++;
            break;
        case 2:
            x += 2;
            y++;
            break;
        case 3:
            x += 2;
            y--;
            break;
        case 4:
            y -= 2;
            x++;
            break;
        case 5:
            y -= 2;
            x++;
            break;
        case 6:
            x -= 2;
            y--;
            break;
        case 7:
            x -= 2;
            y++;
            break;
        case 8:
            y += 2;
            x--;
            break;
        }
    }
};

class que : public fig {
public:
    que(int x1, int y1, string name1) : fig(x1, y1, name1) {}

    char getSymbol() const override {
        return 'Q';
    }

    void Go(int num, int os) {
        if (x < y)
            y = x;
        else x = y;
        switch (os) {
        case 1:
            x += num;
            break;
        case 2:
            x += num;
            y -= num;
            break;
        case 3:
            y -= num;
            break;
        case 4:
            x -= num;
            y -= num;
            break;
        case 5:
            x -= num;
            break;
        case 6:
            x -= num;
            y += num;
            break;
        case 7:
            y += num;
            break;
        case 8:
            x += num;
            y += num;
            break;
        }
    }
};

class kin : public fig {
public:
    kin(int x1, int y1, string name1) : fig(x1, y1, name1) {}

    char getSymbol() const override {
        return 'K';
    }

    void Go(int os) {
        switch (os) {
        case 1:
            x++;
            break;
        case 2:
            x++;
            y--;
            break;
        case 3:
            y--;
            break;
        case 4:
            x--;
            y--;
            break;
        case 5:
            x--;
            break;
        case 6:
            x--;
            y++;
            break;
        case 7:
            y++;
            break;
        case 8:
            x++;
            y++;
            break;
        }
    }
};

class lad : public fig {
public:
    lad(int x1, int y1, string name1) : fig(x1, y1, name1) {}

    char getSymbol() const override {
        return 'L';
    }

    void Go(int num, int os) {
        switch (os) {
        case 1:
            x += num;
            break;
        case 2:
            x -= num;
            break;
        case 3:
            y += num;
            break;
        case 4:
            y -= num;
            break;
        }
    }
};

class elep : public fig {
public:
    elep(int x1, int y1, string name1) : fig(x1, y1, name1) {}

    char getSymbol() const override {
        return 'E';
    }

    void Go(int x1, int y1, int num) {
        if (x < y)
            y = x;
        else x = y;
        switch (num) {
        case 1:
            x += x1;
            y += y1;
            break;
        case 2:
            x -= x1;
            y += y1;
            break;
        case 3:
            x += x1;
            y -= y1;
            break;
        case 4:
            x -= x1;
            y -= y1;
            break;
        }
    }
};

class pesh : public fig {
public:
    pesh(int x1, int y1, string name1) : fig(x1, y1, name1) {}

    char getSymbol() const override {
        return 'P';
    }
    void Go() {
        if (Ismoved)
            y++;
        else y += 2;
        if (y == 8) {
           
        }
    }
};

struct Piece {
    fig* figura;
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
                board[i][j] = { nullptr, false };
            }
        }
    }

    ~ChessBoard() {
        for (int i = 0; i < size; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    void placePiece(int row, int col, fig* piece, bool isWhite) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            board[row][col] = { piece, isWhite };
        }
    }

    void printBoard() {
        cout << "  ";
        for (int j = 0; j < size; ++j) {
            cout << " " << char('A' + j) << " ";
        }
        cout << endl;

        for (int i = 0; i < size; ++i) {
            cout << size - i << " ";

            for (int j = 0; j < size; ++j) {
                if ((i + j) % 2 == 0) {
                    cout << "\033[100m"; 
                }
                else {
                    cout << "\033[40m"; 
                }

                if (board[i][j].figura) {
                    cout << " " << board[i][j].figura->getSymbol() << " ";
                }
                else {
                    cout << " . ";
                }
            }

            cout << "\033[0m" << " " << size - i << endl;
        }

        cout << "  ";
        for (int j = 0; j < size; ++j) {
            cout << " " << char('A' + j) << " ";
        }
        cout << endl;
    }
};

int main() {
    ChessBoard chessBoard(8);

    hor h(1, 1, "Knight");
    chessBoard.placePiece(0, 0, &h, true);

    chessBoard.printBoard();

    return 0;
}
