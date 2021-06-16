#pragma once

class Player{
	public:
		Player(){};
		~Player(){};
		void setMPNum();
		int* getMPNum();
	
	private:
		int mPNum[3] = {};
	};