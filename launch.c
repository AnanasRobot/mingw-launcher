#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH_LEN 255

int main()
{
	printf("Launching MinGW console...\n");

	char path_entry[MAX_PATH_LEN];		// Absolute path to the MinGW binaries
	getcwd(path_entry, MAX_PATH_LEN);	// Start with the current working dir
	strcat(path_entry, "\\mingw\\bin");	// Assume a standard directory structure

	printf("MinGW binaries path: %s\n", path_entry);

}
