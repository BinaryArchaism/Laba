/************************************************************************************
*Project name :Lab3                                                                  *
*Project type :Win32 Console Application                                             *
*File name :Lab3.cpp                                                                 *
*Language :CPP, GCC 5.0 and above                                                    *
*Programmer :Кочкин Михаил Алексеевич, Дмитриев Дмитрий Константинович, М3О-110Б-19  *
*Modifiedby : Дмитриев Дмитрий Константинович                                        *
*Created :18.11.2019                                                                 *
*Lastrevision :18.11.2019                                                            *
*Comment :Одномерные массивы                                                         *
************************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	system("color f0");
	ifstream file;
	file.open("input.txt");
	if (!file)
	{
		cout << "Error! File 'input.txt.' doesn't exist" << endl;
		return -1;
	}
	double n; 
	file >> n;
	if ( (n - int(n) != 0) | !(n > 0 && n < 7))
	{
		cout << "First element should be natural and = [0, 6]" << endl;
		return -1;
	}
	int count = 1;
	double temp;
	while (!file.eof())
	{
		file >> temp;
		count++;
	}
	if (count < 13) 
	{
		cout << "Not enough elements";
		return -1;
	}
	file.seekg(0, ios::beg);
	double VEC[6];
	file >> temp;
	for (int i = 0; i < 6; i++)
	{
		file >> VEC[i];
	}
	int KOL[6];
	for (int i = 0; i < 6; i++)
	{
		file >> temp;
		if (temp - int(temp) != 0 || !(temp > 0 && temp < 7))
		{
			cout << "The KOL elements should be natural and = [0,6]" << endl;
			return -1;
		}
		KOL[i] = int(temp);
	}
	if (count > 13)
	{
		cout << "Program took only 13 elements" << endl;
	}

	
	
	return 0;
}

void print(double VEC[6], int KOL[6]) {
	for (int i = 0; i < 6; i++)
		cout << VEC[i] << endl;
	for (int i = 0; i < 6; i++)
		cout << KOL[i] << endl;
}