#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string toBinary(long long number) {
    string s = "";
    bool flag = false;
    while (number != 0) {
        int div = number % 2;
        s += to_string(div);
        number /= 2;
        if (div == 0)
            flag = true;
    }

    if (!flag)
        s += "0";

    reverse(s.begin(), s.end());

    return s;
}

long long binaryToNumber(string s) {

    long long res = 0;
    int count = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            res += pow(2, count);
        }
        count++;
    }
    return res;
}

long long findNextNumber(string s) {
    bool flag = false;
    int index = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0')
            index = i;
    }

    for (int i = index; i < s.length(); i++) {
        if (s[i] == '0' && !flag) {
            s[i] = '1';
            flag = true;
        }
        else if (flag && s[i] == '1') {
            s[i] = '0';
            break;
        }
    }
    return binaryToNumber(s);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++) {
        long long num = numbers[i];

        if (num % 2 == 0) { //礎熱檣 唳辦 
            answer.push_back(num + 1);
        }
        else { //�汝鶺� 唳辦 
            string s = toBinary(num);
            long long tmp = findNextNumber(s);
            answer.push_back(tmp);
        }
    }

    return answer;
}