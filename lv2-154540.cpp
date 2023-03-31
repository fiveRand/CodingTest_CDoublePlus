#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const vector<pair<int, int>> direction
{
    {1,0} ,
    {-1,0},
    {0,1},
    {0,-1}
};

bool isInBoundary(int x,int y,int Xmax,int Ymax)
{
    if (x < 0 || x >= Xmax || y < 0 || y >= Ymax)
    {
        return false;
    }
    return true;
}

/// <summary>
/// 문제 링크
/// https://school.programmers.co.kr/learn/courses/30/lessons/154540
/// 
/// 후기
/// dfs bfs 문제로 flood-fill 알고리즘이 생각나는 문제였다.
/// vector의 2차원 배열 초기화, 경계선 처리, char to int, 참조형 변수 &에 대해 배웠다
/// </summary>
/// <param name="maps"></param>
/// <returns></returns>

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    int yMax = maps.size();
    int xMax = maps[0].size();
    // 이차원 가변배열을 만들고
    // y축으로 maps의 원소 갯수, x축에서 maps[0].string의 원소 갯수 만큼 메모리를 할당했다. 
    vector<vector<bool>> visited (yMax, vector<bool>(xMax, false));


    for (int y = 0; y < yMax; y++)
    {
        for (int x = 0; x < xMax; x++)
        {
            // y축 위에서 아래로, x축 왼쪽에서 오른쪽으로 [0][0], [0][1], [0][2]... 식으로 루프한다.
            if (!visited[y][x] && isdigit(maps[y][x])) 
            {

                cout << 'X' << x << 'Y' << y << endl;
                int count = 0;
                queue<pair<int, int>> q;
                
                q.push({ y,x }); // make_pair 대신 이렇게 만들자
                visited[y][x] = true;
                count += maps[y][x] - '0';

                while (q.empty() == false)
                {
                    auto cur = q.front(); q.pop();

                    for (auto& dir : direction)
                    {
                        int nY = dir.first + cur.first;
                        int nX = dir.second + cur.second;

                        if (!isInBoundary(nX, nY, xMax, yMax) || visited[nY][nX])
                        {
                            continue;
                        }

                        if (isdigit(maps[nY][nX]))
                        {
                            q.push({ nY,nX });
                            visited[nY][nX] = true;
                            count += maps[nY][nX] - '0';
                        }

                    }
                }
                answer.push_back(count);
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(),answer.end());
    }


    return answer;
}

int main() 
{
    vector<string> maps = { "X591X","X1X5X","X231X", "1XXX1" };
    auto result = solution(maps);

    cout << "RESULT" << endl;
    for (auto i : result)
    {
        cout << i << endl;
    }
}






