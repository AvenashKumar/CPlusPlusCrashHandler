#include "cCrashHandler.h"
#include <iostream>
#include <Windows.h>
#include <csignal>
#include <new.h>
#include <stdio.h>

using namespace std;

cCrashHandler::cCrashHandler()
{
}


cCrashHandler::~cCrashHandler()
{
}

LONG WINAPI cCrashHandler::unHandledExceptionHandler(PEXCEPTION_POINTERS p_ptrExcPointer)
{
	cout << "Un-handled exception caught." << endl;

	// Execute default exception handler next
	return EXCEPTION_EXECUTE_HANDLER;
}
void cCrashHandler::signalHandler(int p_iSignal)
{
	cout << "Interrupt signal (" << p_iSignal << ") received." << endl;

	//Cleanup and close stuff here

	//Terminate program
	exit(p_iSignal);
}
void cCrashHandler::terminateHandler()
{
	cout << "Abnormal program termination caught" << endl;

	//Cleanup and close stuff here

	//Terminate program
	exit(1);
}
void cCrashHandler::pureFuncCallHandler()
{
	cout << "Pure function call caugth" << endl;

	//Cleanup and close stuff here

	//Terminate program
	exit(1);
}
int cCrashHandler::memoryDepletionHandler(const size_t p_cSize)
{
	cout << "Memory depletion error caught" << endl;

	//Cleanup and close stuff here

	//Terminate program
	exit(1);
}
void cCrashHandler::invalidParameterHandler(const wchar_t* expression,
	const wchar_t* function,
	const wchar_t* file,
	unsigned int line,
	uintptr_t pReserved)
{
	wprintf(L"Invalid parameter detected in function %s."
		L" File: %s Line: %d\n", function, file, line);
	wprintf(L"Expression: %s\n", expression);

	//Terminate program
	exit(1);
}

void cCrashHandler::registerHandlers()
{
	//Register: Invalid parameter handler
	_set_invalid_parameter_handler(invalidParameterHandler);

	//Register: Memory depletion handler
	_set_new_handler(memoryDepletionHandler);

	//Register: Pure virtual function call handler
	_set_purecall_handler(pureFuncCallHandler);

	//Register: Unhandled exception handler
	SetUnhandledExceptionFilter(unHandledExceptionHandler);

	//Register: Abnormal termination handler
	set_terminate(terminateHandler);

	//Register: Signals
	signal(SIGABRT, signalHandler);
	signal(SIGINT, signalHandler);
	signal(SIGILL, signalHandler);
	signal(SIGFPE, signalHandler);
	signal(SIGSEGV, signalHandler);
	signal(SIGTERM, signalHandler);
	signal(SIGBREAK, signalHandler);
}