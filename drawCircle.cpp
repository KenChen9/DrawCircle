#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
using namespace std;

double distance(int x, int y, int ox, int oy)
{
	return sqrt(pow(x-ox, 2) + pow(y-oy, 2));
}

int main()
{
	int RANGE; // 50
	cout << "輸入畫布大小 Canvas Size" << endl;
	cin >> RANGE;

	int RADIUS; // 15
	cout << "輸入圓的半徑 Radius" << endl;
	cin >> RADIUS;

	int OriginX; // 25
	cout << "輸入圓心 x 座標 Origin x-coordinate" << endl;
	cin >> OriginX;

	int OriginY; // 25
	cout << "輸入圓心 y 座標 Origin y-coordinate" << endl;
	cin >> OriginY;
	OriginY = RANGE - OriginY;

	// 0 空心 1 填滿 2 反轉
	int Empty_Filled_Inverted = 0;
	cout << "0 空心(Empty) 1 填滿(Filled) 2 反轉(Inversed)" << endl;
	cin >> Empty_Filled_Inverted;

	double tweak = 0.4398; // 最少 0.4398...
	cout << "輸入線條粗細 Thickness（最少 0.4398... 才會形成完整的圓）" << endl;
	cin >> tweak;

	char c1[] = "* ";
	char c2[] = "- ";
	char axisX[] = "--";
	char axisY[] = "| ";

	for (int row = 0; row <= RANGE; row++)
	{
		for (int col = 0; col <= RANGE; col++)
		{
			if (row == RANGE)
			{
				if (row == RANGE && col == 0) cout << "0 ";
				cout << axisX;
			}
			else if (col == 0)
			{
				cout << axisY;
			}
			else
			{
				cout << c2;
			}
			if (Empty_Filled_Inverted == 0)
			{
				if ((distance(col, row, OriginX, OriginY) >= RADIUS - tweak && distance(col, row, OriginX, OriginY) <= RADIUS + tweak) || (col == OriginX && row == OriginY))
				{
					cout << "\b\b" << c1;
				}
			}
			else if (Empty_Filled_Inverted == 1)
			{
				if (distance(col, row, OriginX, OriginY) <= RADIUS + tweak)
				{
					cout << "\b\b" << c1;
				}
			}
			else
			{
				if (distance(col, row, OriginX, OriginY) >= RADIUS - tweak)
				{
					cout << "\b\b" << c1;
				}
			}
		}
		cout << endl;
	}
	system("pause");
}