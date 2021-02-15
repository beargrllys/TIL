/*
    개발 파트: 공항 항공기 게이트 배정 프로세스
    업무 시나리오: 공항의 항공기 이착륙 일정 데이터를 받아 시간대별 항공기 이착륙 시간을 정렬하고 검색하는 기능을 제작한다.
    입력: 항공기 이착륙 일정
    출력: 공항 이착륙 일정


*/
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>


using namespace std;

struct airLineSch
{
    string name;
    string departure;
    int ETD;
    string arrival;
    int ETA;
};

struct airPortSch
{
    string name;
    string place;
    string inOut;
    int time;
};

void quickSort(airPortSch** data, int left, int right);
int partitionBlock(airPortSch** data, int left, int right);
void swap(airPortSch** data ,int x, int y);

clock_t start_quick,end_quick, start_insert, end_insert;
bool time_start = false;

int get_ALSData(airLineSch** dataPoint){
    char line[200];
    int line_Count=0;
    ifstream is;
    is.open("airLineData.txt");
    if(is.is_open()){//텍스트 파일의 데이터 수를 카운트합니다.
        while(!is.eof()){
            is.getline(line, sizeof(line));
            line_Count++;
        }
    }
    is.close();
    *dataPoint = new airLineSch[line_Count];//데이터수만큰 배열을 할당합니다.

    line_Count = 0;
    is.open("airLineData.txt");
    if(is.is_open()){//텍스트 파일의 데이터 수를 카운트합니다.
        while(is.getline(line, sizeof(line))){
            (*dataPoint+line_Count)->name=strtok(line, " ");
            (*dataPoint+line_Count)->departure=strtok(NULL, " ");
            (*dataPoint+line_Count)->ETD=atoi(strtok(NULL, " "));
            (*dataPoint+line_Count)->arrival=strtok(NULL, " ");
            (*dataPoint+line_Count)->ETA=atoi(strtok(NULL, " "));
            line_Count++;
        }
    }
    is.close();

    return line_Count;
}

airPortSch* filterData(airLineSch* ALSData, int size){
    int i=0;
    airPortSch* APSData = new airPortSch[size];
    while(i < size)
    {
        if((ALSData+i)->departure == "인천")//이륙스케줄
        {
            (APSData+i)->name = (ALSData+i)->name;
            (APSData+i)->place = (ALSData+i)->arrival;
            (APSData+i)->inOut = "출발";
            (APSData+i)->time = (ALSData+i)->ETD;
        }
        else//착륙스케줄
        {
            (APSData+i)->name = (ALSData+i)->name;
            (APSData+i)->place = (ALSData+i)->departure;
            (APSData+i)->inOut = "도착";
            (APSData+i)->time = (ALSData+i)->ETA;
        }
        i++;
    }
    return APSData;
}

void quickSort(airPortSch** data, int left, int right)
{
    if(!time_start)
    {
        start_quick = clock();
    }
    if(left < right)
    {
        int pivot = partitionBlock(data, left, right);
        quickSort(data, left, pivot-1);
        quickSort(data, pivot+1, right);
    }
    end_quick = clock();
}

int partitionBlock(airPortSch** data, int left, int right)
{
    int pivot,low,high;
    low = left;
    high = right+1;
    pivot = (*data+left)->time;
    do{
        do{
            low++;
        }while(low<=right && (*data+low)->time<pivot);

        do{
            high--;
        }while(high>=left && (*data+high)->time>pivot);

        if(low<high)
        {
            swap(data, low, high);
        }
    } while(low<high);
    swap(data, left, high);

    return high;
}

void swap(airPortSch** data ,int x, int y)
{
    airPortSch temp;
    temp.name = (*data+x)->name;
    temp.place = (*data+x)->place;
    temp.inOut = (*data+x)->inOut;
    temp.time = (*data+x)->time;
    (*data+x)->name = (*data+y)->name;
    (*data+x)->place = (*data+y)->place;
    (*data+x)->inOut = (*data+y)->inOut;
    (*data+x)->time = (*data+y)->time;
    (*data+y)->name = temp.name;
    (*data+y)->place = temp.place;
    (*data+y)->inOut = temp.inOut;
    (*data+y)->time = temp.time;
}

void insertSort(airPortSch** data, int size)
{
    start_insert = clock();
    int i,j;
    airPortSch* key;
    for(i=1; i< size; i++)
    {
        memcpy(key , *data+i, sizeof(airPortSch));
        for(j=i-1; j>=0 && (*data+j)->time > key->time; j--)
        {
            memcpy(*data+j+1 , *data+j, sizeof(airPortSch));
        }
        memcpy(*data+j+1 , key, sizeof(airPortSch));
    }
    end_insert = clock();
}

string changeTime(int timeCode){
    int hour,min;
    string timeText, hourStr, minStr;
    hour = (timeCode-10000)/100;
    min = timeCode%100;
    hourStr = hour<10 ? "0"+to_string(hour) : to_string(hour);
    minStr = min<10 ? "0"+ to_string(min) : to_string(min);
    timeText = hourStr + "시 " + minStr+ "분";
    return timeText;
}

void printTimetable(airPortSch** data, int size)
{
    int  choice,count=0;
    cout << "1. 출발 시간표  2. 도착시간표  3. 이착륙시간표" << endl;
    cout << "원하는 시간표를 선택하세요: ";
    cin >> choice;
    if(choice == 3){
        cout << "-------이착륙 시간표-------" << endl;
        cout << "번호 항공편   " << "출발/도착  " <<  "시간        "<< "도시    " << endl;
        for(int j=0; j<size; j++){
            string number = j+1<10 ? "0"+ to_string(j+1) : to_string(j+1);
            string inOut = (*data+j)->inOut == "출발" ? (*data+j)->inOut+"     " : "     " + (*data+j)->inOut;
            cout << number << "   " << (*data+j)->name << "   " << inOut << "  " <<changeTime((*data+j)->time) << "   " << (*data+j)->place << endl;
        }
    }
    else if(choice == 2)
    {
        cout << "-------도착 시간표-------" << endl;
        cout << "번호 항공편   " <<  "시간        "<< "도시    " << endl;
        for(int j=0; j<size; j++){
            if((*data+j)->inOut == "도착")
            {
            string number = count+1<10 ? "0"+ to_string(count+1) : to_string(count+1);
            cout << number << "   " << (*data+j)->name << "  " << changeTime((*data+j)->time) << "   " << (*data+j)->place << endl;
            count++;
            }
        }
    }
    else if(choice == 1)
    {
        cout << "-------출발 시간표-------" << endl;
        cout << "번호 항공편   "<<  "시간        "<< "도시    " << endl;
        for(int j=0; j<size; j++){
            if((*data+j)->inOut == "출발")
            {
                string number = count+1<10 ? "0"+ to_string(count+1) : to_string(count+1);
                cout << number << "   " << (*data+j)->name << "   " << changeTime((*data+j)->time) << "   " << (*data+j)->place << endl;
                count++;
            }
        }
    }
    else
    {
        cout << "잘 못 고르셨습니다. 다시 선택해 수제요." << endl;
    }
}


int main()
{
    airLineSch *ALS;
    airPortSch *APS_quickSort;
    airPortSch *APS_insertSort;
    int size=0;
    double quick_Time, insert_Time;


    size = get_ALSData(&ALS);
    APS_quickSort = filterData(ALS, size);
    APS_insertSort = new airPortSch[size];
    copy(APS_quickSort, APS_quickSort+size, APS_insertSort);
    //start_quick = clock();
    quickSort(&APS_quickSort, 0, size-1);
    //end_quick = clock();
    insertSort(&APS_insertSort, size);
    quick_Time = (double)(end_quick-start_quick);
    insert_Time = (double)(end_insert-start_insert);

    cout << "퀵정렬 실행시간: " << quick_Time << endl;
    cout << "삽입정렬 실행시간: " << insert_Time << endl;
    printTimetable(&APS_insertSort, size);
}