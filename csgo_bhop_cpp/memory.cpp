#include "memory.h"
#include <TlHelp32.h>
#include <cwchar>   // For wcscmp

Memory::Memory(const wchar_t* processName)
{
	PROCESSENTRY32W entry;
	entry.dwSize = sizeof(PROCESSENTRY32W);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (snapShot == INVALID_HANDLE_VALUE)
		return;

	while (Process32NextW(snapShot, &entry))
	{
		if (!wcscmp(processName, entry.szExeFile))
		{
			this->id = entry.th32ProcessID;
			this->process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->id);
			break;
		}
	}

	CloseHandle(snapShot);
}

Memory::~Memory()
{
	if (this->process)
		CloseHandle(this->process);
}

DWORD Memory::GetProcessId()
{
	return this->id;
}

HANDLE Memory::GetProcessHandle()
{
	return this->process;
}

uintptr_t Memory::GetModuleAddress(const wchar_t* moduleName)
{
	MODULEENTRY32W entry;
	entry.dwSize = sizeof(MODULEENTRY32W);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->id);
	if (snapShot == INVALID_HANDLE_VALUE)
		return 0;

	uintptr_t result = 0;

	while (Module32NextW(snapShot, &entry))
	{
		if (!wcscmp(moduleName, entry.szModule))
		{
			result = reinterpret_cast<uintptr_t>(entry.modBaseAddr);
			break;
		}
	}

	CloseHandle(snapShot);
	return result;
}
