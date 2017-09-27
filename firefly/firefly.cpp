// firefly.cpp
// Christian Ellison
#include <iostream>
#include <fstream>
// Other include files?
using namespace std;

void main() {
	ifstream fin("firefly.in");
	if (fin.is_open()) {
		ofstream fout("firefly.out");
		float fX, fY, x, y, jump, distance;
		int n = 0;
		bool fireflyCaught = false;
		fin >> jump >> x >> y >> fX >> fY;
		n++;
		while (!(x == 0 && jump == 0 && y == 0))
		{
			while (fX != -1 && fY != -1)
			{
				if (!fireflyCaught)
				{
					distance = sqrt(((fX - x)*(fX - x)) + ((fY - y)*(fY - y)));

					if (distance - jump <= 1)
					{
						fout << "Firefly " << n << " caught at (" << fX << "," << fY << ")" << endl;
						fireflyCaught = true;
					}
					x = x + ((jump / distance) * (fX - x));
					y = y + ((jump / distance) * (fY - y));

				}
				fin >> fX >> fY;

			}
			if (!fireflyCaught)
			{
				fout << "Firefly " << n << " not caught" << endl;
			}
			fin >> jump >> x >> y >> fX >> fY;
			n++;
			fireflyCaught = false;
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}