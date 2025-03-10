#include <iostream>
#include <string>
using namespace std;

class Tile {
public:
    virtual void render() {
        cout << " ";
    }
    virtual bool isWalkable() const {
        return true;
    }
};

class Wall : public Tile {
    void render() override {
        cout << "#";
    }
    bool isWalkable()const override{
        return false;  
    }
};

class Floor : public Tile {
    void render() {
        cout << ".";
    }
};

class Player : public Tile {
public:
    void render() override {
        cout << "P";
    }
};



class Maze {
private:
    Tile*** title;
    int height;
    int width;
    int playerX, playerY;
public:
    Maze(int w, int h) : width(w), height(h), playerX(1), playerY(1) {
        title = new Tile **[height];
        for (int y = 0; y < height; ++y) {
            title[y] = new Tile *[width];
            for (int x = 0; x < width; ++x) {
                title[y][x] = nullptr;
            }
        }
    }

    ~Maze() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                delete title[y][x];
            }
            delete[] title[y];
        }
        delete[] title;
    }

    void setTile(int x, int y, Tile* tile) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            delete title[y][x];
            title[y][x] = tile;
        }
    }

    void PlayerPosition(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            playerX = x;
            playerY = y;
        }
    }

    bool CanMoveTo(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            return title[y][x]->isWalkable();  
        }
        return false;
    }

    void render() const {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == playerX && y == playerY) {
                    Player player;
                    player.render();  
                }
                else if (title[y][x]) {
                    title[y][x]->render();
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    void MovePlayer(int dx, int dy) {
        int newX = playerX + dx;
        int newY = playerY + dy;
        if (CanMoveTo(newX, newY)) {
            PlayerPosition(newX, newY);
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int width = 10;
    int height = 10;
    
    Maze maze(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                maze.setTile(x, y, new Wall());  
            }
            else {
                maze.setTile(x, y, new Floor());  
            }
        }
    }
    maze.render();
    maze.PlayerPosition(1, 1);

   
    string input;
    do {
        system("cls");  
        maze.render();   
        cout << "Управление: W (вверх), S (вниз), A (влево), D (вправо), Q (выход)" << endl;
        cout << "Введите команду: ";
        cin >> input;

        if (input.length() > 0) {
            switch (tolower(input[0])) {
            case 'w': maze.MovePlayer(0, -1); break;
            case 's': maze.MovePlayer(0, 1);  break;
            case 'a': maze.MovePlayer(-1, 0); break;  
            case 'd': maze.MovePlayer(1, 0);  break;
            }
        }
    } while (input != "q");

    return 0;
}
