#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

int sums(const int n,...){
	int i, sum = 0 ;
	va_list args;

	if (args == 0) {
		return 0;
	}

	va_start(args, n);

	for(i = 0; i < n; ++i) {
		sum += va_arg(args, int);
	}

	va_end(args);
	return sum;
}

void Output() {
    std::cout<<std::endl;
}

template<typename First, typename ... Strings>
void Output(First arg, const Strings&... rest) {
    std::cout<<arg<<" ";
    Output(rest...);
}

int main() {
    Output("I","am","a","sentence");
    Output("Let's","try",1,"or",2,"digits");
    return 0;
}
int main(){
	int a=10, b=5, c=3, d=8;
	cout<<sums(4,a,b,c,d)<<endl;

	cin.get();
	return 0;
}