#include <iostream>
#include <time.h>
#include <string>
#include <array>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
	
	class Com{
		public:
			Com(){
				srand (time(NULL)); // 랜덤 시드 시작
				const int NumNum = 3; // sizeof 써서 mCom 배열 크기로 넣기
				for(int i = 0; i< NumNum; i++){
					mCNum[i] = rand() % 9+1;
				}
				while(true){
					if(mCNum[0] == mCNum[1]){mCNum[1] = rand() % 9+1;}
					if(mCNum[0] == mCNum[2]){mCNum[2] = rand() % 9+1;}
					if(mCNum[1] == mCNum[2]){mCNum[2] = rand() % 9+1;}
//					cout << mCNum[0] << "\t" << mCNum[1] << "\t" << mCNum[2] << "\t" << endl;
					if(mCNum[0] != mCNum[1]){
						if(mCNum[1] != mCNum[2]){
							break;
						}
					}
				}
				
			}
			~Com(){}
			void setMCNum(){
				
			}
			int* getMCNum(){
				return mCNum;
			}
		private:
			int mCNum[3] = {1,2,3};
			
	};
	
	class Player{
		public:
			Player(){}
			~Player(){}
			void setMPNum(){
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
							   (mPNum[0] != mPNum[1]) && (mPNum[1] != mPNum[2]) && (mPNum[0] != mPNum[2])){ break;}
						}
				}
				
			}
			int* getMPNum(){
				return mPNum;
			}
		
		private:
			int mPNum[3] = {};
	};
	
	class Compare{
		public:
			void compare(int com[], int player[]){
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
			int getStrike(){
				return strike;
			}
			int getBall(){
				return ball;
			}
			int getInning(){
				return inning;
			}
			void getInningLog(){
				for(int i = 0 ; i < inning ; i++){
					for(int j = 0; j<5; j++){
						if(j == 3){
							cout << "볼 : " << inningLog[i][j] << "\t";
						}
						if(j == 4){
							cout << "스트라이크 : " << inningLog[i][j] << "\t";
						}
						else{
							cout << inningLog[i][j] << "\t";
						}
					}
					cout << endl;
				}
			}
		public:
			int strike;
			int ball;
			int inning = 0;
			int inningLog[9][5] = {0};
	};
	
	Com c1; 
/*	cout << "c1 생성" << endl;
	cout << c1.getMCNum()[0] << '\t' << c1.getMCNum()[1] << '\t' << c1.getMCNum()[2] << endl;
	cout << "종료" << endl;
*/
	
	Player p1;
/*	cout << "p1 생성" << endl;
	p1.setMPNum();
	cout << p1.getMPNum()[0] << '\t' << p1.getMPNum()[1] << '\t' << p1.getMPNum()[2] << endl;
	cout << "종료" << endl;
*/	
	
	Compare comp;
/*	cout << "comp 생성" << endl;
	comp.compare(c1.getMCNum(),p1.getMPNum());
	cout << "스트라이크 : " << comp.getStrike() << '\t'
		 << "볼 : " << comp.getBall() << endl;
	cout << "종료" << endl;
*/	
	
	while(true){
		comp.getInningLog();
		p1.setMPNum();
		comp.compare(c1.getMCNum(),p1.getMPNum());
		system("clear");
		if(comp.getInning() == 9){cout << "Game Over" << endl; break;}
		if(comp.getStrike() == 3){cout << "You Win" << endl; break;}
	}
	
	c1.~Com();
	p1.~Player();
	comp.~Compare();
}