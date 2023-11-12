#ifndef DATA_H
#define DATA_H

class Data {

public:
	Data(int data);
	~Data();

	int getData() const;

private:
	int data;

	Data();
	Data(const Data &src);
	Data &operator=(const Data &rhs);

};

#endif
