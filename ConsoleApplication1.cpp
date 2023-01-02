#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


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






