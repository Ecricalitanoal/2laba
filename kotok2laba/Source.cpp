#include "Header.h"
#include <iostream>
#include <ctime>

void init(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[4];
	}
}
void filling(int** matrix, int size, int* codes)
{
	int random1, random2; 
	for (int i = 0; i < size; i++)
	{
		random2 = 10000 + rand() % (20000-10000+1);
		codes[i] = random2;
		for (int j = 0; j < 4; j++)
		{
			random1 = rand() % (100 - 30 + 1) + 30;
			matrix[i][j] = random1;
		}
	}
}
void write(int** matrix, int size, int* codes)
{
	int points = 0;
	for (int i = 0; i < size; i++)
	{
		std::cout << codes[i] << '|';
		for (int j = 0; j < 4; j++)
		{
			points += matrix[i][j];
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '|' << ' ' << points - matrix[i][3] << '\n';
		points = 0;
	}
	std::cout << "\n=================\n";
}
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void swap(int*& a, int*& b)
{
	int* c = a;
	a = b;
	b = c;
}
void swap(bool& a, bool& b)
{
	bool c = a;
	a = b;
	b = c;
}
void sort_cs_phys(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (matrix[i][2] < matrix[i][3]) swap(matrix[i][2], matrix[i][3]);
	}
}
void selection_amm(int** matrix, int size, int* codes, bool*& ver_mass, int*& points)
{
	int point = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4 - 1; j++)
		{
			point += matrix[i][j];
		}
		//матан 43 русский 45 физика 39 инфа 42
		if ((point >= 240) && (matrix[i][0] > 43) && (matrix[i][1] > 45) && (matrix[i][2] > 39))
		{
			ver_mass[i] = true;
		}
		else
		{
			ver_mass[i] = false;
		}
		points[i] = point;
		point = 0;
	}
}
void sort1(int**& matrix, int size, int*& codes, bool*& ver_mass, int*& points)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size- 1; j++)
		{
			if (ver_mass[j] < ver_mass[j + 1])
			{
				swap(ver_mass[j], ver_mass[j + 1]);
				swap(codes[j], codes[j + 1]);
				swap(matrix[j], matrix[j + 1]);
				swap(points[j], points[j + 1]);
			}
		}
	}
}
void sort2(int**& matrix, int size, int*& codes, int*& points)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (points[j] < points[j + 1])
			{
				swap(codes[j], codes[j + 1]);
				swap(matrix[j], matrix[j + 1]);
				swap(points[j], points[j + 1]);
			}
		}
	}
}
void print_final(int** matrix, int size, int* codes, int* points, bool* ver)
{
	for (int i = 0; i < size; i++)
	{
		if (ver[i]) {
			std::cout << codes[i] << '|';
			for (int j = 0; j < 4; j++)
			{
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << '|' << points[i] << " | ПММ " << '\n';
		}
		else break;
	}
	std::cout << "\n=================\n";
}
