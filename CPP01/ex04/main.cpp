#include <sstream>
#include "iostream"
#include "fstream"

using namespace std;

int main(int argc, char *argv[]) {

	if (argc != 4)
		return (1);

	stringstream str;
	string file_content;
	string file_name = argv[1];
	ifstream infile;
	ofstream outfile;

	infile.open(file_name);
	outfile.open(file_name + ".replace");

	str << infile.rdbuf();

	file_content = str.str();
//	size_t found = file_content.find(argv[2]);
//	if (found != string::npos)
//	{
//		cout << "Found occurrence in: " << found << endl;
//	}

	outfile << file_content;

	infile.close();
	outfile.close();

	return 0;
}