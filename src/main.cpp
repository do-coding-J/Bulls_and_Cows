#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include "Com.h"
#include "Player.h"
#include "Compare.h"

using namespace std;

int main(){
	
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