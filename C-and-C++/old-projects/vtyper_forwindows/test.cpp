#include <iostream>
#include "virtual_typer.h"

using namespace std;

int main(){

	string type_this = "I am typing this without using my hand";

	cout<<"wait..."<<endl;
	int cnt = 6;
	for(unsigned long long int i=0; i<5000000000ull; ++i){
		if(cnt==0) break;
		if(i%100000000ull == 0){
			--cnt;
			cout<<"\nclick the area where you can type a text\nex: your notpad, an input text field or a text editor...\ntyping in "<<cnt<<endl;
		}
	}
	cout<<"typing..."<<endl;

	auto_type(type_this);

	return 0;
}