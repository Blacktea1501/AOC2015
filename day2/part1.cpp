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
		int totalpaper = 0;
		while(getline(file, input)){
			if(input != ""){
				stringstream ss(input);
				getline(ss, le, 'x');
				l = stoi(le);
				getline(ss, wi, 'x');
				w = stoi(wi);
				getline(ss, hi, 'x');
				h = stoi(hi);
				int s1, s2, s3, slack;
				s1 = l*w;
				s2 = w*h;
				s3 = h*l;
				slack = min({s1, s2, s3});
				totalpaper += 2 *(s1 + s2 +s3) + slack;
			}
		}
		file.close();
		cout << totalpaper << endl;
	}
}
