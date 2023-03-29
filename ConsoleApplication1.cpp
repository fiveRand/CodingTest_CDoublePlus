#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/161989

*/


int solution(int n, int m, vector<int> section) 
{
    int answer = 0;

    vector<bool> arr(n);
    for (int i = 0; i < section.size() ; i++)
    {
        int arrIndex = section[i] - 1;
        arr[arrIndex] = true;

    }
    /*
    for (auto i : arr)
    {
        cout << i << endl;
    }
    */
    // 기본값으로 초기화된 n개의 원소를 지닌 vector를 생성

    while (!section.empty())
    {
        //cout << "INDEX" << endl;
        int index = section.front() - 1;
       // cout << index << endl;
        
        if (arr[index])
        {

            answer++;
           // cout << "ARRINDEX" << endl;
            for (int i = 0; i < m; i++)
            {
                int arrIndex = index + i;
               // cout << arrIndex << endl;
                arr[arrIndex] = false;
                if (arrIndex >= n - 1)
                {
                    break;
                }
            }
        }
        else
        {
            section.erase(section.begin());
        }
    }
    /*
    cout << "After" << endl;
    for (auto i : arr)
    {
        cout << i << endl;
    }
    */
    return answer;
}

int main() 
{
    int n = 4;
    int m = 1;
    vector<int> section = {1,2,3,4 };

    cout << solution(n, m, section); 
}






