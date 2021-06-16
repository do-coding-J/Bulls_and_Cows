#include "Compare.h"
#include <iostream>

using namespace std;

void Compare::compare(int com[], int player[]){
	strike = 0;
	ball = 0;
	
	if(com[0] == player[0]){strike++;}
	if(com[1] == player[1]){strike++;}
	if(com[2] == player[2]){strike++;}
	
	//strike 3 == homerun
				
	if(com[0] == player[1]){ball++;}
	if(com[0] == player[2]){ball++;}
	if(com[1] == player[0]){ball++;}
	if(com[1] == player[2]){ball++;}
	if(com[2] == player[0]){ball++;}
	if(com[2] == player[1]){ball++;}
	
	for(int i = 0; i<3 ; i++){
		inningLog[inning][i] = player[i];
	}
	
	inningLog[inning][3] = ball;
	inningLog[inning][4] = strike;
	
	inning++;
	cout << inning << "회" << endl
		 << "결과 : " << ball << "볼 " << strike << "스트라이크" << endl;
}

int Compare::getStrike(){
	return strike;
}

int Compare::getBall(){
	return ball;
}

int Compare::getInning(){
	return inning;
}

void Compare::getInningLog(){
	for(int i = 0 ; i < inning ; i++){
		for(int j = 0; j<5; j++){
			if(j == 3){cout << inning << "회,\t 볼 : " << inningLog[i][j] << "\t";} // 볼이 두번 출력됨?
			if(j == 4){cout << "스트라이크 : " << inningLog[i][j] << "\t";}
			else{cout << inningLog[i][j] << "\t";}
		}
		cout << endl;
	}
}