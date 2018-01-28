#include <stdio.h>
#include <Windows.h>

#define FILE_ACCESS FILE_MAP_READ | FILE_MAP_WRITE
#define MAP_FILE_NAME "mMapFile"

int main(int argc, char **argv)
{
	if (argc < 2) 
	{
		printf("use as <Program> <P> (P - The path to a file to map)\n");
		return 0; 
	}

	HANDLE hMapFile = OpenFileMapping(
		FILE_ACCESS,						// access 
		TRUE,								// inherit on/off
		MAP_FILE_NAME						// map name
	);


	if (NULL == hMapFile)
	{
		// file is not mapped yet...

		HANDLE hFile = CreateFile(
			argv[1],						// file path
			GENERIC_READ | GENERIC_WRITE,	// Access
			FILE_SHARE_READ,				// Shared mode
			NULL,							// Security Attributes
			OPEN_EXISTING,					// On File exists 
			NULL,							// FlagsAndAttributes
			NULL							// TemplateFile
		);

		if (NULL == hFile) 
		{
			printf("Error, File could not be opened");
			return 0;
		}

		hMapFile = CreateFileMapping(
			hFile,							// file handle 
			NULL,							// security attributes
			PAGE_READWRITE,					// page protection
			0,								// msb max size
			0,								// lsb max size
			MAP_FILE_NAME					// map name
		);

		DWORD error = GetLastError();
		if (error)
		{
			printf("Error %d: ", error);
			switch (error)
			{
			case ERROR_ACCESS_DENIED:
				printf("Access Denied!\n");
			default:
				break;
			}
			
		}
	}

	char *lpMMFile = (char *)MapViewOfFile(
		hMapFile,							// map file handle
		FILE_MAP_WRITE,						// access
		0,									// file offset high
		0,									// file offset low
		0									// bytes to map
	);

	printf("File begining: %#010x\n", lpMMFile);

	printf("Press Enter to release file mapping...");
	getchar();

	UnmapViewOfFile(lpMMFile);
	CloseHandle(hMapFile);

	return 0;
}