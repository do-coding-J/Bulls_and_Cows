#include "Player.h"
#include <iostream>

using namespace std;

void Player::setMPNum(){
	cout << "플레이어의 숫자 세개를 입력하시오 1~9" << endl;
	while(true){
		retry: // 중복 검사 후 중복시 이쪽으로 이동
		for(int i=0; i<3;i++){
			cout << i+1 << "번째 : "; // 무한 루프
			cin >> mPNum[i];
			if(mPNum[i] > 10 || mPNum[i] == 0){
				cout << "다시 입력하세요" << endl;
			}
		}
		if((mPNum[0] == mPNum[1]) || (mPNum[1] == mPNum[2]) || (mPNum[0] == mPNum[2])){
				cout << "중복되는 수 입니다. 다시 입력해주세요" << endl;
				goto retry; // 중복시 while 의 첫번째로 이동
			}
		if(mPNum[0] < 10 && mPNum[0] > 0){
			if((mPNum[1] < 10) && (mPNum[1] > 0) &&
			   (mPNum[1] < 10) && (mPNum[1] > 0) &&
			   (mPNum[1] < 10) && (mPNum[1] > 0) &&
			   (mPNum[0] != mPNum[1]) && 
			   (mPNum[1] != mPNum[2]) && 
			   (mPNum[0] != mPNum[2])){ break;}
		}
	}		
}
int* Player::getMPNum(){
	return mPNum;
}