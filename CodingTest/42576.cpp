#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct listNode {
    string Name;
    bool Done;
} node;

vector<node> nodeList;


string solution(vector<string> participant, vector<string> completion) {
    for (int i=0; i < participant.size(); i++ ){
        node tmpNode;
        tmpNode.Name = participant[i];
        tmpNode.Done = false;
        nodeList.push_back(tmpNode);
    }
    
    for (int i=0; i < completion.size(); i++ ){
        if(std::find(nodeList.begin(), nodeList.end(), completion[i]) == nodeList.end()){
        string answer = completion[i];
        return answer;   
        }
    }
}