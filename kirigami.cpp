#include "kirigami.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream& operator >> (ifstream& fin, kirigami& kiri)
{
	fin >> kiri.row >> kiri.col;
	kiri.o_col = kiri.col;
	kiri.o_row = kiri.row;
	kiri.p = new char* [kiri.row];
	for (int i = 0; i < kiri.row; i++)
	{
		kiri.p[i] = new char[kiri.col];
	}

	for (int i = 0; i < kiri.row; i++) {
		for (int j = 0; j < kiri.col; j++) {

			fin >> kiri.p[i][j];
		}
	}

	return fin;
}

void operator << (ostream& out, kirigami& kiri)
{
	char dum;
	if (kiri.col == kiri.o_col)
	{
		out << "Input " << kiri.row << " * " << kiri.col << endl;
	}
	else {
		out << "Resized to " << kiri.row << " * " << kiri.col << endl;
	}
	for (int r = 0; r < kiri.row; r++)
	{
		for (int c = 0; c < kiri.col; c++) {
			out << kiri.p[r][c];
		}
		out << "\n";
	}
}


// void operator << (ofstream& ft, kirigami& kiri)
// {
// 	if (kiri.col == kiri.o_col)
// 	{
// 		ft << "Input " << kiri.row << " * " << kiri.col << "\n";
// 	}
// 	else {
// 		ft << "Resized to " << kiri.row << " * " << kiri.col << "\n";
// 	}
// 	for (int r = 0; r < kiri.row; r++)
// 	{
// 		for (int c = 0; c < kiri.col; c++) {
// 			ft << kiri.p[r][c];
// 		}
// 		ft << "\n";
// 	}
// }

void kirigami::unfold_Right()
{
	int col_before = col;
	col *= 2;
	int c = col;
	int r = row;
	int count;
	char** temp;

	temp = new char* [r];
	for (int i = 0; i < r; i++)
	{
		temp[i] = new char[c];
	}

	for (int i = 0; i < r; i++) {
		count = 1;
		for (int j = 0; j < c; j++) {
			if (j > col_before - 1) {
				temp[i][j] = kirigami::p[i][j - count];
				count = count + 2;
			}
			else
			{
				temp[i][j] = kirigami::p[i][j];
			}

		}
	}
	kirigami::p = temp;
}

void kirigami::unfold_Down()
{
	int old_row = row;
	row *= 2;
	int c = col;
	int r = row;
	int count = 1;
	char** temp;

	temp = new char* [r];
	for (int i = 0; i < r; i++)
	{
		temp[i] = new char[c];
	}

	for (int i = 0; i < r; i++) {
		int temp1 = i;
		if (i >= old_row)
		{
			temp1 = temp1 - count;
			count += 2;
		}
		for (int j = 0; j < c; j++)
		{
			temp[i][j] = kirigami::p[temp1][j];
		}
	}

	kirigami::p = temp;
}
/*
	for (int i = 0; i < o_row; i++)
	{
		delete[] p[i];

	}
	delete[] p;*/