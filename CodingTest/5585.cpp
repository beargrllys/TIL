#include <iostream>

using namespace std;

int main(){
	int save_price, count=0;
	cin >> save_price;
	save_price = 1000-save_price;
	count += save_price/500;
    save_price = save_price%500;

	count += save_price/100;
    save_price = save_price%100;

	count += save_price/50;
    save_price = save_price%50;

	count += save_price/10;
    save_price = save_price%10;

	count += save_price/5;
    save_price = save_price%5;

	count += save_price;
	cout << count <<endl;

}
