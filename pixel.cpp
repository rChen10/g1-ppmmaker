#include <iostream>
#include <fstream>
#include <string>
//using namespace std;

class pixel{
	public:
		int r, g, b;
		pixel(int red, int green, int blue){
			r = red;
		       	g = green;
		       	b = blue;
		}
		pixel(){
			r = 0;
		       	g = 0;
		       	b = 0;
		}

		//std::string to_string(){ 
		//	return std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b);
		//}

		std::ostream& operator<<(std::ostream& fs){
			fs << r << " " << g << " " << b;
			return fs;
		}

		pixel& operator+=(int i){
			r = (r + i) % 256;
			g = (g + i) % 256;
			b = (b + i) % 256;
			return *this;
		}

		pixel& operator+=(pixel p){
			r = (r + p.r) % 256;
			g = (g + p.g) % 256;
			b = (b + p.b) % 256;
			return *this;
		}

		pixel& operator-=(int i){
			r -= i % 256;
			g -= i % 256;
			b -= i % 256;

			if (r < 0){
				r += 256;
			}
			if (g < 0){
				g += 256;
			}
			if (b < 0){
				b += 256;
			}
			return *this;
		}

		pixel& operator-=(pixel p){
			r -= p.r % 256;
			g -= p.g % 256;
			b -= p.b % 256;

			if (r < 0){
				r += 256;
			}
			if (g < 0){
				g += 256;
			}
			if (b < 0){
				b += 256;
			}
			return *this;
		}

		pixel& operator/=(int i){
			r = (int) r / i;
			g = (int) g / i;
			b = (int) b / i;
			return *this;
		}
};


std::ostream& operator<<(std::ostream& fs, const pixel& p){
	fs << p.r << " " << p.g << " " << p.b;
	return fs;
}
