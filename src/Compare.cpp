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
	inningLog[inning][3] = inning + 1;
	inningLog[inning][4] = ball;
	inningLog[inning][5] = strike;
	
	inning++;
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
		for(int j = 0; j<6; j++){
			if(j == 3){cout << inningLog[i][j] << "회";} 			else if(j == 4){cout << "볼 : " << inningLog[i][j] << "\t";} 
			else if(j == 5){cout << "스트라이크 : " << inningLog[i][j] << "\t";}
			else{cout << inningLog[i][j] << "\t";}
		}
		cout << endl;
	}
}