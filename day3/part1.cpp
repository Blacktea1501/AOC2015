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
	set.emplace(loc); // santa delivers present to the house at his starting point	
	if(file.is_open()){
		getline(file, line);
		for(char c : line){
			loc = getNewLocation(loc, c);
			set.emplace(loc);
		}
		cout << set.size() << endl;
		file.close();
	}
	return 0;
}
