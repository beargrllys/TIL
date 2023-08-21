#include <iostream>

using namespace std;

int out_right(int num){
	if(num >= 10){
		int add = (num%10)*10+(((num/10)+(num%10))%10);
		return add;
	}
	else{
		return num*10+num;
	}
}

int main(){
	int num,count=0, process=100;
	cin >> num;
	process = out_right(num);
	count++;
	while(num != process){
		process = out_right(process);
		count++;
	}
	cout << count <<endl;

}
