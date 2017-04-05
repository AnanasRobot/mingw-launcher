#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH_LEN 255

int main()
{
	printf("Launching MinGW console...\n");

	char mingw_bin_dir[MAX_PATH_LEN];		// Absolute path to the MinGW binaries
	getcwd(mingw_bin_dir, MAX_PATH_LEN);	// Start with the current working dir
	strcat(mingw_bin_dir, "\\bin");	// Assume a standard directory structure

	printf("MinGW binaries path: %s\n", mingw_bin_dir);

	char* path = getenv("PATH");

	printf("\nCurrent path is: %s\n", path);

	const int new_path_len = strlen(mingw_bin_dir) + strlen(path);

	char new_path[new_path_len];

	strcat(new_path, mingw_bin_dir);
	strcat(new_path, ";");
	strcat(new_path, path);

	printf("\nNew path is: %s\n", new_path);

	system("cmd");
}
