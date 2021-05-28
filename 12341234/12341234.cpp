#include <iostream>
#include <vector>
using namespace std;
// 0 북
// 1 동
// 2 남
// 3 서

//   북0
// 서3   동1
//    남2
void changeDirection(int d)
{
    // y = -1 0 1, 0
    // x = 0, 1, 0, -1
    if (d == 0)
    {
        d = 3;
    }
    else if (d == 1)
    {
        d = 0;
    }
    else if (d == 2)
    {
        d = 1;
    }
    else if (d == 3)
    {
        d = 2;
    }
}
// 북 동 남 서
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void moveRobot(int& r, int& c, int& d)
{
    r = r + dy[d];
    c = c + dx[d];
}

bool checkIndex(int ny, int nx, int r, int c)
{
    bool nyF = ny >= 0 && ny < r;
    bool nxF = nx >= 0 && nx < c;
    return nyF && nxF;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int r, c, d;
    int nx, ny;
    int ans = 0;
    bool game = true;

    cin >> n >> m;
    cin >> r >> c >> d;

    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    changeDirection(d);
    if (map[r][c] == 0) ans++;
    while (game) {
        ny = r + dy[d];
        nx = c + dx[d];
        if (checkIndex(ny, nx, r, c) && map[ny][nx] == 0)
        {
            ans++;
            moveRobot(r, c, d);
            map[r][c] = 9;
            changeDirection(d);
        }
        else
        {
            int count = 0;
            for (int i = 0; i < 3; i++)
            {
                changeDirection(d);
                ny = r + dy[d];
                nx = c + dx[d];
                if (checkIndex(ny, nx, r, c) && map[ny][nx] == 0) {
                    ans++;
                    moveRobot(r, c, d);
                    map[r][c] = 9;
                    break;
                }
                count++;
            }
            if (count == 3) // 세방향 모두 청소되있을떄
            {
                changeDirection(d); // 한번더 돌려서 원래상태로
                if (d == 0)
                {
                    int temp = r;
                    while (1)
                    {
                        if (map[temp][c] == 0)
                        {
                            moveRobot(r, c, d);
                            map[r][c] = 9;
                            ans++;
                            changeDirection(d);
                            break;
                        }
                        temp++;
                        if (temp == r)
                        {
                            game = false;
                            break;
                        }

                    }
                }
                else if (d == 1)
                {
                    int temp = c;
                    while (1)
                    {
                        if (map[r][temp] == 0)
                        {
                            moveRobot(r, c, d);
                            map[r][c] = 9;
                            ans++;
                            changeDirection(d);
                            break;
                        }
                        temp--;
                        if (temp == -1)
                        {
                            game = false;
                            break;
                        }

                    }
                }
                else if (d == 2)
                {
                    int temp = r;
                    while (1)
                    {
                        if (map[temp][c] == 0)
                        {
                            moveRobot(r, c, d);
                            map[r][c] = 9;
                            ans++;
                            changeDirection(d);
                            break;
                        }
                        temp--;
                        if (temp == -1)
                        {
                            game = false;
                            break;
                        }

                    }
                }
                else if (d == 3)
                {
                    int temp = c;
                    while (1)
                    {
                        if (map[r][temp] == 0)
                        {
                            moveRobot(r, c, d);
                            map[r][c] = 9;
                            ans++;
                            changeDirection(d);
                            break;
                        }
                        temp++;
                        if (temp == c)
                        {
                            game = false;
                            break;
                        }

                    }

                }
            }
        }
        break;
    }

    cout << ans;
    return 0;
}