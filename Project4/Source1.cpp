#include<iostream>
using namespace std;

class Flat {
	int* flatone;
	int flattwo;
public:
	Flat() {

		flatone = nullptr;
		flattwo = 0;
	}
	Flat(int s)
	{
		flattwo = s;
		flatone = new int[flattwo] {0};
	}
	Flat(const Flat& obj)
	{
		flattwo = obj.flattwo;
		flatone = new int[flattwo];
		for (int i = 0; i < flattwo; i++)
		{
			flatone[i] = obj.flatone[i];
		}
	}





};