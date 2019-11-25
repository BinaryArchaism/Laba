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

	//Открытие файла
	ifstream file;
	file.open("input.txt");
	if (!file) //Проверка существования
	{
		cout << "Error! File 'input.txt.' doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//Ввод N
	double n; 
	file >> n;
	if ( (n - int(n) != 0) | !(n > 0 && n < 7)) //Проверка N
	{
		cout << "First element should be natural and = [0, 6]" << endl;
		system("pause");
		return -1;
	}
	int count = 1; //Количество вводимых элементов
	double temp;

	//Подсчёт количества элементов
	while (!file.eof())
	{
		file >> temp;
		count++;
	}
	if (count < 13) 
	{
		cout << "Not enough elements";
		system("pause");
		return -1;
	}
	file.seekg(0, ios::beg); //Переход к началу файла
	double VEC[6];
	file >> temp;
	for (int i = 0; i < 6; i++) //Ввод массива VEC
	{
		file >> VEC[i];
	}
	int KOL[6];
	for (int i = 0; i < 6; i++) //Ввод массива KOL
	{
		file >> temp;
		if (temp - int(temp) != 0 || !(temp > 0 && temp < 7)) //Проверка элементов массива KOL
		{
			cout << "The KOL elements should be natural and = [0,6]" << endl;
			system("pause");
			return -1;
		}
		KOL[i] = int(temp);
	}
	if (count > 13)
	{
		cout << "Program took only 13 elements" << endl;
	}

	//Печатьэлементов файла, принятых в программу
	cout << "N = " << n << endl;
	cout << "VEC: " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << VEC[i] << " ";
	}
	cout << endl;
	cout << "KOL: " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << KOL[i] << " ";
	}
	cout << endl;

	int NEWVEC[6] = { 0 };

	//Заполнение массива NEWVEC
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < KOL[i]; j++)
		{
			NEWVEC[i] += VEC[j];
		}
	}

	int s = 0; //Сумма абсолютных значений последних N элементов NEWVEC
	for (int i = 0; i < n; i++)
	{
		s += abs(NEWVEC[5 - i]);
	}
	cout << "NEWVEC:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << NEWVEC[i] << " ";
	}
	cout << endl;
	cout << "S = " << s << endl;

	//Поиск наименьшего и наибольшего элементов и их индексов
	int min = NEWVEC[0];
	int index_min = 0;
	int max = NEWVEC[1];
	int index_max = 1;

	if (min > max)
	{
		min = NEWVEC[1];
		index_min = 1;
		max = NEWVEC[0];
		index_max = 0;
	}

	for (int i = 2; i < n; i++)
	{
		if (NEWVEC[i] > max)
		{
			max = NEWVEC[i];
			index_max = i;
		}
		if (NEWVEC[i] < min)
		{
			min = NEWVEC[i];
			index_min = i;
		}
	}

	cout << "Max element: " << max << " with index: " << index_max << endl;
	cout << "Min element: " << min << " with index: " << index_min << endl;
	system("pause");
	return 0;
}