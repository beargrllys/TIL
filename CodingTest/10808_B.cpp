
#include <bits/stdc++.h>
using namespace std;

int alpha[26];
string word;

//입력
//순서대로 char단위 접근후 인덱스 계산
//int 올리기

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        alpha[word[i] - 'a'] += 1;
    }

    
    for (int i = 0; i < 26; i++) {
        cout << alpha[i]  << " ";
    }
}
