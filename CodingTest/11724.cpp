#include <iostream>
using namespace std;

void space_combine(int array[], int point_num, int point_A, int point_B){
	int small = (point_A < point_B) ? point_A : point_B;
	int big = (point_A < point_B) ? point_B : point_A;
	for(int i=0; i<point_num; i++){
		if(array[i]==big){
			array[i]=small;
		}
	}
}

int main(int argc, const char * argv[]){
	int point, line, start_po, end_po;
	int point_array[1010];
	cin >> point >> line;
	for(int i=0; i<point; i++){
		point_array[i]=0;
	}//정점의 개수만큼 배열 열어주기

	int count=point, connect_count=0;
	//		cout << "\n";
	for(int j=0; j<line; j++){
		cin >> start_po >> end_po;
		start_po--; 
		end_po--;
		if(point_array[start_po]==0 && point_array[end_po]==0){
			count--;
			connect_count++;
			point_array[start_po]=connect_count;
			point_array[end_po]=connect_count;
		}
		else if(point_array[start_po]==0 || point_array[end_po]==0){
			count--;
			int format = (point_array[start_po]==0) ? point_array[end_po] : point_array[start_po];
			int format_pos = (point_array[start_po]==0) ? start_po : end_po;
			point_array[format_pos]=format;

		}
		else{
			space_combine(point_array, point,point_array[start_po],point_array[end_po]);
		}

		//for(int i=0; i<point; i++){
		//	cout << point_array[i] << " ";
		//}
		//cout << "\n";
	}
	int result=0, max=0;
	bool there = false;
	for(int i=0; i<point; i++){
		there=false;
		if (point_array[i]==0){
			result++;
		}
		else{
			if(point_array[i]>max){
				max=point_array[i];
			}
		}
	}
	result = result + max;
	cout << result;

}