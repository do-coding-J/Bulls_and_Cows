#pragma once

class Com{
	public:
		Com();
		~Com();
		int* getMCNum();
	private:
		int mCNum[3] = {1,2,3};
};