#include "Body.h"


Body::Body(Semantic type)
{
	this->type = type;
	this->posX = rand()%800;
	this->posY = rand()%800;
}



Body::~Body(void)
{
}
