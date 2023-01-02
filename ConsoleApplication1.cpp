#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include<stack>
#include<queue>
using namespace std;

/// <summary>
/// 후기)
/// 처음시도했을때 예시는 다 맞았지만 제출해보니 (signal: aborted (core dumped)) 로 틀렸다.
/// 메모리관련 에러인데 질문글에 더 살펴보니 값이 int가 담을수 있는 값보다 클수도 있어 long으로 수정하니 맞았다.
/// </summary>
/// <param name="t"></param>
/// <param name="p"></param>
/// <returns></returns>
int solution(string t, string p) {
    int answer = 0;
    int tSize = t.size();
    int pSize = p.size();
    long pValue = stol(p);
    

    for (int i = 0; i < tSize; i++)
    {

        string newStr = t.substr(i, pSize);
        if (newStr.size() < pSize)
        {
            break;
        }
        long nValue = stol(newStr);

        if (nValue <= pValue)
        {
            answer++;
        }
    }
    return answer;
}


int main() 
{
    const char* t = "500220839878";
    const char* p = "7";
    auto answer = solution(t, p);
    cout << answer << endl;
}






