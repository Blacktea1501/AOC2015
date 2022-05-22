#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ifstream file;
	file.open("input.txt", ios::in);
	if(file.is_open()){
		string input;
		string le, wi, hi;
		int l, w, h;
		int totalRibbon = 0;
		while(getline(file, input)){
			if(input != ""){
				stringstream ss(input);
				getline(ss, le, 'x');
				l = stoi(le);
				getline(ss, wi, 'x');
				w = stoi(wi);
				getline(ss, hi, 'x');
				h = stoi(hi);
				totalRibbon += 2 * (l + w + h - max({l, w, h})) + l * w * h; 	
			}
		}
		file.close();
		cout << totalRibbon << endl;
	}
}
