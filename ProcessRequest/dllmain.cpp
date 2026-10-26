#include <Windows.h>

#include "MinHook.h"
#include "Memcury.h"

#include "Curl/CurlHttp.h"

void* FMemory::Malloc(SIZE_T Count, uint32 Alignment)
{
	static void* (*FMemory__Malloc)(SIZE_T, uint32) = nullptr;

	if (!FMemory__Malloc)
		FMemory__Malloc = Memcury::Scanner::FindPattern("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 83 EC ? 4C 8B 25 ? ? ? ? 33 ED").GetAs<decltype(FMemory__Malloc)>();

	return FMemory__Malloc(Count, Alignment);
}

void* FMemory::Realloc(void* Original, SIZE_T Count, uint32 Alignment)
{
	static void* (*FMemory__Realloc)(void*, SIZE_T, uint32) = nullptr;

	if (!FMemory__Realloc)
		FMemory__Realloc = Memcury::Scanner::FindPattern("40 53 56 41 56 41 57 48 83 EC ? 4C 8B 35").GetAs<decltype(FMemory__Realloc)>();

	return FMemory__Realloc(Original, Count, Alignment);
}

void FMemory::Free(void* Original)
{
	static void* (*FMemory__Free)(void*) = nullptr;

	if (!FMemory__Free)
		FMemory__Free = Memcury::Scanner::FindPattern("48 85 C9 0F 84 ? ? ? ? 57 48 83 EC ? 4C 89 74 24").GetAs<decltype(FMemory__Free)>();

	FMemory__Free(Original);
}

FString FCurlHttpRequest::GetURL() const
{
	return *reinterpret_cast<FString*>((uint8*)this + 0x278);
}

void FCurlHttpRequest::SetURL(const FString& InURL)
{
	*reinterpret_cast<FString*>((uint8*)this + 0x278) = InURL;
}

void FCurlHttpRequest::OnProcessRequest()
{
	FString URL = GetURL();

	if (URL.IsEmpty())
		return;

	const TCHAR* Scheme = FCString::Strstr(*URL, TEXT("://"));

	if (!Scheme)
		return;

	const TCHAR* PathAndQuery = FCString::Strchr(Scheme + 3, TEXT('/'));

	if (!PathAndQuery)
		return;

	SetURL(FString(TEXT("http://127.0.0.1:5595")) + PathAndQuery);
}

DWORD WINAPI MainThread(LPVOID lpParameter)
{
	if (AllocConsole())
	{
		FILE* Dummy;
		// freopen_s(&Dummy, "dump_out.log", "w", stdout);
		// freopen_s(&Dummy, "dump_err.log", "w", stderr);
	}

	if (MH_Initialize() == MH_STATUS::MH_OK)
	{
		LPVOID ProcessRequest = Memcury::Scanner::FindStringRef(TEXT("STAT_FCurlHttpRequest_ProcessRequest")).ScanFor({ 0x40, 0x55, 0x53, 0x56, 0x57, 0x41, 0x56, 0x41, 0x57 }, false).GetAs<LPVOID>();

		MH_CreateHook(ProcessRequest, FCurlHttpRequest::ProcessRequest, (LPVOID*)&FCurlHttpRequest__ProcessRequest);
		MH_EnableHook(ProcessRequest);
	}

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
	}

	return TRUE;
}
