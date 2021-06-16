#include "Com.h"
#include <time.h>
#include <stdlib.h>

Com::Com(){
	srand (time(NULL)); // 랜덤 시드 시작
	for(int i = 0; i< 3; i++){
		mCNum[i] = rand() % 9+1;
	}
	while(true){
		if(mCNum[0] == mCNum[1]){mCNum[1] = rand() % 9+1;}
		if(mCNum[0] == mCNum[2]){mCNum[2] = rand() % 9+1;}
		if(mCNum[1] == mCNum[2]){mCNum[2] = rand() % 9+1;}

		if(mCNum[0] != mCNum[1]){
			if(mCNum[1] != mCNum[2]){
				break;
			}
		}
	}
}
Com::~Com(){}

int* Com::getMCNum(){
	return mCNum;
}