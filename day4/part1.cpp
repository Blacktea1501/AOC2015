#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main(){
	ifstream file("input.txt");
	string line;

	if(file.is_open()){
		getline(file, line);
		cout << line << endl;
		file.close();
	}

	return 0;
}
