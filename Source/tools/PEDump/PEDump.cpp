#include "PEDump.h"


//void log_info(const char* info, ...);

bool FixHeader(char* pLocalImage)
{
	auto pNtHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<uint64_t>(pLocalImage) + reinterpret_cast<PIMAGE_DOS_HEADER>(pLocalImage)->e_lfanew);

	// fix alignment
	pNtHeaders->OptionalHeader.FileAlignment = pNtHeaders->OptionalHeader.SectionAlignment;

	// fix_image_base
	PIMAGE_SECTION_HEADER pSectionHeader = IMAGE_FIRST_SECTION(pNtHeaders);
	printf("base: %p\n", pLocalImage);
	printf(" ptr: %p\n", &pSectionHeader->SizeOfRawData);
	for (int i = 0; i < pNtHeaders->FileHeader.NumberOfSections; ++i, ++pSectionHeader)
	{
		printf("%s:\n", pSectionHeader->Name);
        printf("  size_of_rawData:%lx=>%lx\n", pSectionHeader->SizeOfRawData, pSectionHeader->Misc.VirtualSize);
		printf("  ptr_to_rawData :%lx=>%lx\n", pSectionHeader->PointerToRawData, pSectionHeader->VirtualAddress);
		pSectionHeader->SizeOfRawData = pSectionHeader->Misc.VirtualSize;
		pSectionHeader->PointerToRawData = pSectionHeader->VirtualAddress;
	}
	return 1;
}

void pedump(HMODULE mod, const std::string& name)
{
	MODULEINFO mi{ 0 };
	DWORD ri;

	HANDLE file = CreateFileA(name.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file != INVALID_HANDLE_VALUE) {
		if (!GetModuleInformation(GetCurrentProcess(), mod, &mi, sizeof(mi)))
			return;
		std::vector<BYTE> buf(mi.SizeOfImage);
		CopyMemory(buf.data(), mi.lpBaseOfDll, mi.SizeOfImage);
		FixHeader((char*)buf.data());
		WriteFile(file, buf.data(), mi.SizeOfImage, &ri, NULL);
		CloseHandle(file);
	}
}
