//#include <iostream>
//#include <fstream>
#include "pixel.cpp"

using namespace std;

int main(){
	ofstream file;
	file.open("output.ppm");
	file << "P3\n";
	file << "500 500\n";
	file << 255 << "\n";
	//file << "\n";

	pixel history[4];

	pixel p1(255, 0, 0);
	history[0] = p1;
	pixel p2(0, 255, 0);
	history[1] = p2;
	pixel p3(155, 17, 155);
	history[2] = p3;
	pixel p4(0, 0, 0);
	history[3] = p4;

	int place = 3;

	for (int i = 0; i < 500; i++){
		for (int j = 0; j < 500; j++){
			for (int k = 0; k < 4; k++){
				if (k != place){
					history[place] += history[k];
				}
			}

			//history[place] /= 4;

			//if ((i % 2 == 0 && j % 2 == 0)
			//		|| (i % 2 == 1 && j % 2 == 1))
			//	history[place] += 30;
			//else
			//	history[place] -= 25;
			
			file << (history[place]);

			if (j != 499)
				file << " ";
		
			if (place == 3)
				place = 0;
			else
				place++;	
		}
		if (i != 499)
			file << "\n";
	}
	file.close();
}
