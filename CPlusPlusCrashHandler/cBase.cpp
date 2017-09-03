#include "cBase.h"
#include "cDerived.h"

cBase::cBase(cDerived *p_ptrDerived) : m_ptrDerived(p_ptrDerived)
{
}


cBase::~cBase()
{
	m_ptrDerived->function();
}
