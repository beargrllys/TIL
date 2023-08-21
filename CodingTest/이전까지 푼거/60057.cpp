#include <iostream>
#include <string>

using namespace std;

int main() {
    string piece, result, bePiece;
    int repeat=1, min=100000;
    string s;
    cin >> s;
   
    for(int i=1; i < s.length()/2; i++){
         bePiece = s.substr(i*0, i);
        for(int j=1; j < s.length()/i; j++){
            piece = s.substr(i*j, i);
            if(bePiece.compare(piece) == 0){
                repeat++;
            }
            else{
                if(repeat == 1){
                    result.append(bePiece);
                    piece="";
                }
                else{
                    result.append(to_string(repeat));
                    result.append(bePiece);
                    piece="";
                    repeat = 1;
                }
            }
            bePiece = piece;
        }
        result.append(s.substr((s.length()/i)*i, s.length()%i));
        min = (min > result.length()) ? result.length() : min;
        std::cout << to_string(i) << " / " << result << endl;
        result = "";
    }
    std::cout << min << endl;
}