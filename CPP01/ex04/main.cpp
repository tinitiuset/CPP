#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

	if (argc != 4)
		return (1);

	ifstream	infile;
	ofstream	outfile;

	string file_name =	argv[1];
	string replacee =	argv[2];
	string replacer =	argv[3];

	unsigned long	index;
	stringstream	str;
	string			file_content;

	infile.open(file_name);
	outfile.open(file_name + ".replace");

	str << infile.rdbuf();

	file_content = str.str();

	while (file_content.find(replacee) != string::npos)
	{
		index = file_content.find(replacee);
		file_content.erase(file_content.find(replacee), replacee.length());
		file_content.insert(index, replacer);
	}

	outfile << file_content;

	infile.close();
	outfile.close();

	return 0;
}