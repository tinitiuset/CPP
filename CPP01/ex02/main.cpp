#include "iostream"

using namespace std;

int main() {

	string str = "HI THIS IS BRAIN";
	string *strPTR = &str;
	string &strREF = str;

	cout << "str address: " << &str << endl;
	cout << "str_ptr address: " << strPTR << endl;
	cout << "str_ref address: " << &strREF << endl;

	cout << "str: " << str << endl;
	cout << "str_ptr value: " << *strPTR << endl;
	cout << "str_ref value: " << strREF << endl;

	return 0;
}