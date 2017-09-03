#include <iostream>
#include "cCrashHandler.h"
#include "cDerived.h"
#include <vector>
#include <assert.h>
using namespace std;
void crashInvalidParameterFunctionCall()
{
	// Disable the message box for assertions.
	_CrtSetReportMode(_CRT_ASSERT, 0);

	// Call printf_s with invalid parameters.
	char* formatString = NULL;
	printf(formatString);
}

void crashPureVirtualFunctionCall()
{
	{
		cDerived objDerived;
	}
}

void unHandledException()
{
	//Case 1: Divide any number with zero
	int x = 0;
	int y = 24;
	int z = y / x;

	//Case 2: Throw exception explicity
	//throw exception("Exception - Message");

	//Case 3: Throw message
	//throw "Exception - Message";
}

void crashSegmentViolation()
{
	int *p = NULL;
	*p = 13;
}

void crashMemoryDepletion()
{
	int iTotalSize = 999999999;
	int *pi = new int[iTotalSize];
}

void crashTerminateFunctionCall()
{
	terminate();
}

void crashAbortFunctionCall()
{
	abort();
}

void main()
{
	//Register all handlers
	cCrashHandler::registerHandlers();

	const int i = 6;
	switch (i)
	{
	case 1:
		crashInvalidParameterFunctionCall();
		break;
	case 2:
		crashPureVirtualFunctionCall();
		break;
	case 3:
		unHandledException();
		break;
	case 4:
		crashMemoryDepletion();
		break;
	case 5:
		crashTerminateFunctionCall();
		break;
	case 6:
		crashAbortFunctionCall();
		break;
	case 7:
		crashSegmentViolation();
		break;
	}
}