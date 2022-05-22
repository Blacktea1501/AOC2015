#include <iostream>
#include <fstream>
using namespace std;
int main(){
        cout << "Reading in..." << endl;
        ifstream infile("input.txt");
        cout << "finished reading." << endl;
        int counter = 0;
        string a;
        while(infile >> a){
                for (int i = 0; i < a.length(); i++){
                        if (a[i] ==  '('){
                                counter++;
                        }else{
                                counter--;
                        }
			if(counter == -1){
			cout << i + 1 << endl;
			return 0;
			}
                }
        }
        return 0;
}

