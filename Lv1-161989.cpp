#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/161989
덧칠하기

한번에 풀었으나 vector를 잘 다루지 못한 본인의 미숙으로 시간이 걸렸다, 분발하자.



*/


int solution(int n, int m, vector<int> section) 
{
    int answer = 0;

    vector<bool> arr(n); // 초기화 bool 값(false)를 n개로 지닌 arr를 생성했다
    for (int i = 0; i < section.size() ; i++)
    {
        int arrIndex = section[i] - 1; 
        arr[arrIndex] = true;
    }
    // section의 원소을 arr에 대입하여 빈곳을 true값으로 줬다
    /*
    for (auto i : arr)
    {
        cout << i << endl;
    }
    */

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
    // section이 없어지거나 검색값이 n값을 넘어설 때까지
    // section를 루프해 arr이 거짓이면 section에서 지우고,
    // 참이면 answer라는 카운트를 증가하고 현재 인덱스에서 m까지 더한 값까지 루프해 거짓으로 바꾼다
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






