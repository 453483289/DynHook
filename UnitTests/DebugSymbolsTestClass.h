#include "stdafx.h"
#include "DebugSymbols.h"
#include <map>

class DebugSymbolsTestClass : public IEnumerateDebugSymbolsCallback
{
public:
	std::map<CString, CString> m_symbols;

	DebugSymbolsTestClass()
	{
		// read symbols for my own test code!
		CDebugSymbols symbolEngine;

		symbolEngine.Initialize();
		symbolEngine.EnumerateSymbols((LPCTSTR)g_DllLocation, this);
	}

	// IEnumerateDebugSymbolsCallback callback
	BOOL OnSymbol(LPCTSTR pszSymbolName, DWORD dwOrdinal, DWORD dwRVA, LPCTSTR pszParameters)
	{
		CString name(pszSymbolName);
		CString params(pszParameters);

		m_symbols.insert(std::map<CString, CString>::value_type(name, params));		

		return TRUE;
	}
};