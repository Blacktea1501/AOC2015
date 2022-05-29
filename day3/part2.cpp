#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;

pair<int, int> getNewLocation(pair<int, int> loc, char c){
	if (c == '^'){
		loc.second++;
	}
	else if (c == 'v'){
		loc.second--;
	}
	else if (c == '<'){
		loc.first--;
	}
	else if (c == '>'){
		loc.first++;
	}
	return loc;
}

struct pair_hash{
	inline size_t operator()(const pair<int, int> & v) const{
		return v.first*31+v.second;
	}
};


int main(){
	ifstream file("input.txt");
	string line;
	pair<int, int> loc(0, 0);
	unordered_set<pair<int, int>, pair_hash> set;
	set.emplace(loc); // santa and robo-santa deliver present to the house at their starting point	
	if(file.is_open()){
		getline(file, line);
		
		// santas route	
		for (int i = 0; i < line.size(); i += 2){
			char c = ' ';
			if (i < line.size()){
				c = line[i];
			}
			if(c != ' '){
				loc = getNewLocation(loc, c);
				set.emplace(loc);
			}
		}

		loc.first = 0;
		loc.second = 0;
		
		// robo-santas route
		for (int i = 1; i < line.size(); i += 2){
			char c = ' ';
			if (i < line.size()){
				c = line[i];
			}
			if(c != ' '){
				loc = getNewLocation(loc, c);
				set.emplace(loc);
			}
		}
			
		cout << set.size() << endl;
		file.close();
	}
	return 0;
}
