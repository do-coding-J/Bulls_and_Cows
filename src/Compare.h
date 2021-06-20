#pragma once

class Compare{
	public:
		void compare(int com[], int player[]);
		int getStrike();
		int getBall();
		int getInning();
		void getInningLog();
		public:
			int strike;
			int ball;
			int inning = 0;
			int inningLog[9][6] = {0};
	};