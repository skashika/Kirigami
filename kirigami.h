#include <ostream>
#include <fstream>
using namespace std;

class kirigami {

public:
	int row, col, o_row, o_col;
	char** p;
	char** temp;
	string value;
	void unfold_Right();
	void unfold_Down();
	friend void operator << (ostream& out, kirigami& kkk);
	friend ifstream& operator >> (ifstream& file, kirigami& kkk);
	//kirigami operator = (kirigami& target);

};