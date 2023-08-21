#include <iostream>

using namespace std;

char doc[2525] = {'\0', };
char word[55] = {'\0', };
int chp = 0,j=0, cot =0;

int main(){
    cin.getline(doc,2525);
    cin.getline(doc,55);

    while(doc[chp] != '\0'){
        for(j=chp; word[j] != '\0'; j++){
            if(doc[chp] != word[j]){
                doc[j] = '\0'; 
                break;
            }
            else{
                chp++;
            }
        }
        if(word[j] == '\0'){
            cot++;
        }
    }

    cout << cot;
}