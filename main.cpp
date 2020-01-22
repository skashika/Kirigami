#include "kirigami.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	kirigami kgami;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	while (fin >> kgami)
	{
		cout << kgami;
		fout << kgami;
		kgami.unfold_Right();
		cout << kgami;
		fout << kgami;
		kgami.unfold_Down();
		cout << kgami;
		fout << kgami;

	}
	fout.close();
	return 0;
}