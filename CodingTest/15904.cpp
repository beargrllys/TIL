#include <iostream>
#include <string>

using namespace std;

int main(){
    string word, result="", ucpc = "UCPCCC";
    int YN =0, j=0;
    getline(cin,word);
    for(int i=0; i<word.length(); i++){
        if(word.at(i) - 'A' < 26 && word.at(i) != ' '){
            result += word.at(i);
        }
    }
    for(int i=0; i<result.length(); i++){
        if(result.at(i) == ucpc.at(j)){
            j++;
        }
    }
    if(j >= 4){
        cout << "I love UCPC" << endl;
    }
    else{
        cout << "I hate UCPC" << endl;
    }

}