#pragma once
#include <Windows.h>    // Windows API
#include <iostream>     // Console output

class Memory
{
private:
	DWORD id = 0;            // Process ID
	HANDLE process = NULL;   // Process handle

public:
	Memory(const wchar_t* processName);
	~Memory();

	DWORD GetProcessId();
	HANDLE GetProcessHandle();

	uintptr_t GetModuleAddress(const wchar_t* moduleName);

	template <typename T>
	T Read(uintptr_t address)
	{
		T value;
		ReadProcessMemory(this->process, (LPCVOID)address, &value, sizeof(T), NULL);
		return value;
	}

	template <typename T>
	bool Write(uintptr_t address, T value)
	{
		return WriteProcessMemory(this->process, (LPVOID)address, &value, sizeof(T), NULL);
	}
};
