#pragma once
class cDerived;
class cBase
{
private:
	cDerived * m_ptrDerived;	///< Pointer of dervied class

private:
	/**Disable default constructor
	*/
	cBase();

public:
	/**Parameterized constructor
	*\param p_ptrDerived: Pointer of dervied class
	*/
	cBase(cDerived *p_ptrDerived);

	/**Destructor
	*/
	~cBase();

public:
	/**Pure virtual function named function
	*/
	virtual void function(void) = 0;
};