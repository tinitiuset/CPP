#ifndef WEAPON_H
#define WEAPON_H

#include "iostream"

class Weapon {
private:
	std::string type;

public:
	Weapon(std::string type);
	~Weapon();

	const std::string &getType() const;
	void setType(const std::string &type);
};


#endif
