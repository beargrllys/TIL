#include <stdio.h>

int main(){
	int save_price, cal_price, count=0, i;
	scanf("%d", &save_price);
	cal_price = save_price;
	for(i=100; i!=25; i/=2){
		count += cal_price/i;
		cal_price = cal_price%i;
	}
	for(i=25; i!=0; i/=5){
		count += cal_price/i;
		cal_price = cal_price%i;
	}
	printf("%d\n", count+i);

}
