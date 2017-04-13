#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH_LEN 255

void prepend_to_env(const char*, const char*);

int main()
{
	printf("Launching MinGW console...\n");

	char mingw_bin_dir[MAX_PATH_LEN];       // Absolute path to the MinGW binaries
	getcwd(mingw_bin_dir, MAX_PATH_LEN);    // Start with the current working dir
	strcat(mingw_bin_dir, "\\bin");         // Assume a standard directory structure

	printf("MinGW binaries path: %s\n", mingw_bin_dir);

	prepend_to_env(mingw_bin_dir, "PATH");

	system("cmd /k cd \\");

	return 0;
}

void prepend_to_env(const char* item, const char* var)
{
	// Get the previous value of the environment variable
	char* old_value = getenv(var);

	// Format is <var>=<new item>;<previous value>
	// Length of variable name
	// 1 for =
	// Length of item
	// 1 for ;
	// Length of previous value
	// 1 for null terminator
	const size_t putenv_arg_len = strlen(var) + 1 + strlen(item) + 1 + strlen(old_value) + 1;

	// Allocate space for the putenv argument
	char putenv_arg[putenv_arg_len];

	// Put a null terminator on
	putenv_arg[0] = 0;

	// Build up the argument
	strcat(putenv_arg, var);
	strcat(putenv_arg, "=");
	strcat(putenv_arg, item);
	strcat(putenv_arg, ";");
	strcat(putenv_arg, old_value);

	// Set the environment variable
	putenv(putenv_arg);
}
