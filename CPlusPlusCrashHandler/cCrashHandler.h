#pragma once
#include <Windows.h>

/*This class is responsible for:
1. Providing handles for all un-caughted exceptions.
*/
class cCrashHandler
{
private:
	/** Un-handles exception handler
	*\param pExceptionPtrs: Exception point
	*\returns  next exception handler
	*/
	static LONG WINAPI unHandledExceptionHandler(PEXCEPTION_POINTERS pExceptionPtrs);

	/** Signal handler
	*\param p_iSignal: Signal number
	*/
	static void signalHandler(int p_iSignal);

	/** Signal handler
	*\param p_iSignal: Signal number
	*/
	static void terminateHandler();

	/** Pure virtual function call handler
	*/
	static void pureFuncCallHandler();

	/** Memory depletion handler
	*\param p_cSize: Memory size
	*/
	static int memoryDepletionHandler(const size_t p_cSize);

	/** Invalid parameter handler
	*\param p_chptrExpression: Expression
	*\param p_chptrFunction: Function
	*\param p_chptrFile: File
	*\param p_uiLine: Line
	*\param p_uiptrReserved: Reserved
	*/
	static void invalidParameterHandler(const wchar_t* p_chptrExpression,
										const wchar_t* p_chptrFunction,
										const wchar_t* p_chptrFile,
										unsigned int p_uiLine,
										uintptr_t p_uiptrReserved);
public:
	/**Register all exception handlers
	*/
	static void registerHandlers();

	/**Constructor
	*/
	cCrashHandler();

	/**Destructor
	*/
	~cCrashHandler();
};

