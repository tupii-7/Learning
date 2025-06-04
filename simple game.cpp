#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int WIDTH = 45;
const int HEIGHT = 30;

struct Point {
    int x, y;
};

int main() {
    srand((unsigned)time(0));
    vector<Point> snake = { {WIDTH / 2, HEIGHT / 2} };
    Point food = { rand() % WIDTH, rand() % HEIGHT };
    int dx = 1, dy = 0; // Initial direction: right
    bool gameOver = false;
    int score = 0;

    while (!gameOver) {
        // Input
        if (_kbhit()) {
            char input = _getch();
            if ((input == 'w' || input == 'W') && dy != 1) { dx = 0; dy = -1; }
            if ((input == 's' || input == 'S') && dy != -1) { dx = 0; dy = 1; }
            if ((input == 'a' || input == 'A') && dx != 1) { dx = -1; dy = 0; }
            if ((input == 'd' || input == 'D') && dx != -1) { dx = 1; dy = 0; }
            if (input == 'q' || input == 'Q') break;
        }

        // Move snake
        Point newHead = { snake[0].x + dx, snake[0].y + dy };

        // Check collision with wall
        if (newHead.x < 0 || newHead.x >= WIDTH || newHead.y < 0 || newHead.y >= HEIGHT) {
            gameOver = true;
            break;
        }
        // Check collision with self
        for (const auto& s : snake) {
            if (s.x == newHead.x && s.y == newHead.y) {
                gameOver = true;
                break;
            }
        }
        if (gameOver) break;

        // Move snake forward
        snake.insert(snake.begin(), newHead);

        // Check food
        if (newHead.x == food.x && newHead.y == food.y) {
            score++;
            // Place new food
            bool valid;
            do {
                valid = true;
                food.x = rand() % WIDTH;
                food.y = rand() % HEIGHT;
                for (const auto& s : snake) {
                    if (s.x == food.x && s.y == food.y) {
                        valid = false;
                        break;
                    }
                }
            } while (!valid);
        } else {
            // Remove tail
            snake.pop_back();
        }

        // Draw
        system("cls");
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                if (i == food.y && j == food.x)
                    cout << "*";
                else {
                    bool printed = false;
                    for (size_t k = 0; k < snake.size(); ++k) {
                        if (snake[k].x == j && snake[k].y == i) {
                            cout << (k == 0 ? "O" : "o");
                            printed = true;
                            break;
                        }
                    }
                    if (!printed) cout << ".";
                }
            }
            cout << endl;
        }
        cout << "Score: " << score << " | Use W/A/S/D to move, Q to quit." << endl;
        Sleep(30);
    }

    cout << "Game Over! Final Score: " << score << endl;
    return 0;
}