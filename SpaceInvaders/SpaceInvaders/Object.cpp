#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::DestroyObj(std::vector<Object*> &obj) 
{
	delete obj[0];
}

