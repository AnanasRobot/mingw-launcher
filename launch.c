#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH_LEN 255

int main()
{
	printf("Launching MinGW console...\n");

	char mingw_bin_dir[MAX_PATH_LEN];       // Absolute path to the MinGW binaries
	getcwd(mingw_bin_dir, MAX_PATH_LEN);    // Start with the current working dir
	strcat(mingw_bin_dir, "\\bin");         // Assume a standard directory structure

	printf("MinGW binaries path: %s\n", mingw_bin_dir);

	char* path = getenv("PATH");

	// Define the new path
	// new_path = mingw_bin_dir;path
	// Length is 5 (for "test=") + strlen(mingw_bin_dir) + 1 (for the colon) + strlen(path) + 1 (for terminator)
	const size_t new_path_len = 5 + strlen(mingw_bin_dir) + 1 + strlen(path) + 1;
	char new_path[new_path_len];
	new_path[0] = 0;	// Be sure the null terminator is there
	strcat(new_path, "path=");
	strcat(new_path, mingw_bin_dir);
	strcat(new_path, ";");
	strcat(new_path, path);

	putenv(new_path);

	system("cmd /k cd \\");

	return 0;
}
