#ifndef SEMANTIC_H_
#define SEMANTIC_H_

#include "Tags.h"

/*
*   A Semantic is a type definition for a PhysicalObject.
*/

class Semantic
{
private:
    string semantic;
public:
	Semantic(string semantic);

	~Semantic(void);
	string getSemantic() {return this->semantic;}
	void setSemantic(string semantic) {this->semantic = semantic;}


};

#endif
