#ifndef BRAIN_H
#define BRAIN_H

#include "iostream"

class Brain {

	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);

};


#endif
