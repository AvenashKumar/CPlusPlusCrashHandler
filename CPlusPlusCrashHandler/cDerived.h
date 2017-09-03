#pragma once
#include "cBase.h"
class cDerived: public cBase
{
public:
	/*Default constructor
	*/
	cDerived();

	/*Destructor
	*/
	~cDerived();

public:
	/*virtual method
	*/
	virtual void function();
};

