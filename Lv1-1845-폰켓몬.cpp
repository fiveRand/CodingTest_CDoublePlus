#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/// 문제링크
/// https://school.programmers.co.kr/learn/courses/30/lessons/1845
///
/// 해쉬를 응용하는 문제이다. C++ 에서 중복을 허용하지 않는 데이터구조(set)를 응용했다.
///
int solution(vector<int> nums)
{
    int answer = 0;
    int count = nums.size() / 2;
    set<int> noDumplication;

    for (auto num : nums)
    {
        noDumplication.insert(num);
        answer = noDumplication.size();
        if (answer >= count)
        {
            
            break;
        }
    }

    cout << count << endl;
    
    return answer;
}


int main() 
{
    vector<int> nums = { 3,3,3,2,2,4};
    solution(nums);
}






