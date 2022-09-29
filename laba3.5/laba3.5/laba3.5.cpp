#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

bool IsSimple(int x)
{
	if (x == 1)
		return false;

	for (int i = 2; i <= x / 2; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	string code;
	string strS = "";
	string strNs = "";
	int change = 0;
	int quantitySimple = 0;
	int strLength;

	ifstream in("input.txt");

	if (in.is_open()) {
		in >> change;
		getline(in, code);
		getline(in, code);
	}

	in.close();
	strLength = code.length();

	for (int i = 1; i <= code.length(); i++)
		if (IsSimple(i))
			quantitySimple++;

	for (int c = 0; c < change; c++)
	{
		strS = "";
		strNs = "";

		for (int i = 0; i < quantitySimple; i++)
			strS.push_back(code[i]);

		for (int i = quantitySimple; i < code.length(); i++)
			strNs.push_back(code[i]);

		int iS = 0;
		int iNs = 0;
		code = "";

		for (int i1 = 1; i1 <= strLength; i1++)
		{
			if (IsSimple(i1))
			{
				code.push_back(strS[iS]);
				iS++;
			}
			else
			{
				code.push_back(strNs[iNs]);
				iNs++;
			}
		}
	}
	fstream out("output.txt");
	out << code;
}