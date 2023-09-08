/*
N(<=7)명의 팀원이 있을때 총 M번의 회의 일정이 기일정되어있다. 팀원들은 각자 회의 일정을 가지고 있다. 팀원들의 회의 시간을 침해하지 않고 팀장이 원하는 요일중 호출팀원들이 모두 모일수 있는 요일이 언제인지 출력하는 프로그램 회의 호출 횟수(Q <= 1000)을 제작하시오. (9:00~18:00 - 10분단위)
5 a b c d e 25
Mon 10 0 13 10 a,b
Tue 14 10 15 30 e,c
Wed 13 40 16 40 a,c
Tur 9 20 11 50 a,b,d
Fri 10 30 12 0 b,d
Tue 15 40 17 30 b,d,e
Mon 16 50 18 20 b,c
Wed 10 50 11 0 a,c,d
Wed 17 20 18 0 a,e
Tue 16 40 17 10 b,c
Fri 11 20 14 10 a,b,c,e
Fri 12 10 12 50 a,b
Tue 9 10 11 50 b,c
Wed 10 20 14 40 b,d
Wed 13 30 14 50 c
Wed 10 10 12 20 d,e
Mon 16 50 17 20 b,d
Fri 14 10 16 30 c,d
Mon 17 30 18 0 a,c
Tur 15 50 17 30 b,e
Tue 10 40 12 50 b,c,e
Mon 12 20 13 10 c,d
Fri 16 40 17 30 c,e
Tur 9 40 11 50 a,c
Tue 10 20 13 0 b,d
b,c,e Tue,Wed,Fri
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, cnt;
vector<string> nameList;
vector<string> days = {"Mon", "Tue", "Wed", "Tur", "Fri"};

vector<string> targetNamelist;
vector<string> targetDaylist;

string targetName, targetDay;

map<string, map<string, vector<bool>>> table;

void check_table(string day, int starth, int startm, int endh, int endm, string tlist)
{
	vector<string> l;
	int pos;
	while((pos = tlist.find(',')) != string::npos)
	{
		string token = tlist.substr(0,pos);
		l.push_back(token);
		tlist.erase(0, pos + 1); 
	}

	int startT 	= (starth 	* 6) + (startm/10);
	int endT 	= (endh 	* 6) + (endm/10);

	vector<string>::iterator beginIter 	= l.begin();
	vector<string>::iterator endIter 	= l.end();
	for(vector<string>::iterator iter = beginIter; iter != endIter; iter++)
	{
		for(int i = startT; i < endT; i++)
			table[*iter][day][i] = true;
	}
}

int main()
{
	string strTmp;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> strTmp;
		table[strTmp] = {
				{days[0], vector<bool>(24*6)},
				{days[1], vector<bool>(24*6)},
				{days[2], vector<bool>(24*6)},
				{days[3], vector<bool>(24*6)},
				{days[4], vector<bool>(24*6)}
			};
	}
	cin >> cnt;

	string day, list;
	int starth, startm, endh, endm; 
	for(int i = 0; i < cnt; i++)
	{
		cin >> day >> starth >> startm >> endh >> endm >> list;
		check_table(day, starth, startm, endh, endm, list);
	}

	cin >> targetName >> targetDay;

	int pos;
	while((pos = targetName.find(',')) != string::npos)
	{
		string token = targetName.substr(0, pos);
		targetNamelist.push_back(token);
		targetName.erase(0, pos+1);
	}
	while((pos = targetDay.find(',')) != string::npos)
	{
		string token = targetDay.substr(0, pos);
		targetDaylist.push_back(token);
		targetDay.erase(0, pos+1);
	}

	int workStart 	= 9*6;
	int workEnd		= 18*6;
	vector<int>  ableLength;

	int maxT = -1;
	string maxDay;
	for(int tday = 0; tday < targetDaylist.size(); tday++)
	{
		int cnt  = 0;
		for(int chkT = workStart; chkT < workEnd; chkT++)
		{
			bool isable = true;
			for(int tname = 0; tname < targetNamelist.size(); tname++)
			{
				string td = targetDaylist[tday];
				string tn = targetNamelist[tname];
				isable = isable && table[tn][td][chkT];
			}
			if(isable == false)
			{
				if(maxT < cnt)
				{
					maxT = cnt;
					maxDay = targetDaylist[tday];
				}
				cnt = 0;
			}
			else
				cnt += 1;
		}
	}

	cout << maxDay << ", " << maxT << "\n";

	return 0;
}