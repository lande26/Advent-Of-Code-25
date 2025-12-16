#include <bits/stdc++.h>
using namespace std;

long long mx(const string &s, int k) {
    int n = s.size();
    int rem = n - k;
    string res;

    for (char c : s) {
        while (!res.empty() && rem > 0 && res.back() < c) {
            res.pop_back();
            rem--;
        }
        res.push_back(c);
    }

    while (rem-- > 0) res.pop_back();
    res = res.substr(0, k);
    return stoll(res);
}

void print128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x > 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file) {
        cerr << "input.txt not found\n";
        return 1;
    }

    string s;
    __int128 sum = 0;

    while (getline(file, s)) {
        sum += mx(s, 12);
    }

    print128(sum);
    cout << endl;
}
