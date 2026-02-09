#include <iostream>
#include <vector>
#include <conio.h>   // _kbhit, _getch
#include <windows.h> // Sleep
using namespace std;

const int HEIGHT = 7;
const int WIDTH = 15;

// vector<string> map = {
//     "###############",
//     "#.............#",
//     "#.###.###.###..#",
//     "#.............#",
//     "#.###.#.#.###..#",
//     "#.............#",
//     "###############"
// };

    int px = 9, py = 1; // Pac-Man position
    int score = 0;
    int g1x = 1, g1y = 1;
    int g2x = 1, g2y = 3;
    int g3x = 1, g3y = 5;
    bool GhostRight = true;
    bool lost = false;

char map[7][15] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

void draw()
{
    system("cls");
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {

            if (x == g1x && y == g1y)
            {
                cout << 'G';
            }
            else if (x == g2x && y == g2y) {
                cout << 'G';
            }
            else if (x == g3x && y == g3y) {
                cout << 'G';
            }

            else if (x == px && y == py)
                cout << 'P';
            else
                cout << map[y][x];
        }
        cout << '\n';
    }
    cout << "Score: " << score << endl;
}

void movePacman(int dx, int dy)
{
    int nx = px + dx;
    int ny = py + dy;

    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && map[ny][nx] != '#')
    {
        if (map[ny][nx] == '.')
        {
            score++;
            map[ny][nx] = ' ';
        }
        px = nx;
        py = ny;
    }
}

bool checkGhostVsPac_Man()
{
    return (px == g1x && py == g1y) ||
        (px == g2x && py == g2y) ||
        (px == g3x && py == g3y);
}

int main()
{

    while (score < 49)
    {
        //GhostMove
        {
            if (GhostRight) {
                if (g1x == 12)
                {
                    GhostRight = !GhostRight;
                }
                g1x++;
                g2x++;
                g3x++;
            }
            else {
                if (g1x == 2)
                {
                    GhostRight = !GhostRight;
                }
                g1x--;
                g2x--;
                g3x--;
            }

        }
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'w')
                movePacman(0, -1);
            if (key == 's')
                movePacman(0, 1);
            if (key == 'a')
                movePacman(-1, 0);
            if (key == 'd')
                movePacman(1, 0);
        }

            if (checkGhostVsPac_Man())
            {
                draw();
                cout << "You Lost the Game";
                return 0;
            }
            draw();
        Sleep(400); // game speed
    }
    cout << "You Won The Game";
}