/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */

#include <stdlib.h>   // getenv, malloc, free, EXIT_SUCCESS, NULL
#include <string.h>   // strchr
#include <stdio.h>    // printf, sprintf
#include <sys/stat.h> // struct stat, S_ISDIR, S_ISREG
#include <unistd.h>   // stat, access
#include <dirent.h>   // opendir, closedir, readdir, DIR, struct dirent

/**
 * @brief  Creates a copy of the string on the heap.
 * @param  s [IN]  The original string.
 * @return Returns the allocated copy or NULL if s is NULL or if malloc failed.
 * @remark Suggestion: Use the functions malloc(), strcpy().
 */
static char *malloc_copy(const char *s)
{
    char *p = NULL;
    // BEGIN-STUDENTS-TO-ADD-CODE

	p = malloc(sizeof(char)*(strlen(s)));
	if (p == NULL) {
		return NULL;
	}
	strcpy(p,s);

    // END-STUDENTS-TO-ADD-CODE
    return p;
}

/**
 * @brief  Replaces inplace in the buffer all occurances of sep by '\0'.
 * @param  buffer [INOUT] The string which gets searched and modified.
 * @param  sep    [IN]    The separator for which all instances in buffer get replaced by '\0'.
 * @return Returns the number of fields which are separated by sep, or 0 if buffer is NULL.
 * @remark Empty fields are allowed and to be supported, i.e. given by ":..." or by "...::..." or by "...:".
 * @remark Suggestion: Use the function strchr() to search for the separator.
 */
static size_t split_buffer_inplace(char buffer[], char sep)
{
    size_t n = 1;
    // BEGIN-STUDENTS-TO-ADD-CODE

	char *part = buffer;
	while ((part = strchr(part, sep)) != NULL) {
		part[0] = '\0';
		++part;
		++n;
	}

    // END-STUDENTS-TO-ADD-CODE
    return n;
}

/**
 * @brief  If path is an executable directory, list all executable files located directly in that directory - each such file as i:path:file.
 * @param  i [IN]    The number of the path to report.
 * @param  path [IN] The directory path to search for executables.
 * @remark Suggestion: Use the function is_accessible_dir(), is_executable_file(), opendir(), readdir(), closedir().
 */
static void list_executables(size_t i, const char *path)
{
    // bash:
    //   [ -n "$p" ] || p="."
    //   if [ -d "$p" ] && [ -x "$p" ]
    //   then
    //      find -L "$p" -maxdepth 1 -type f -executable -printf "$i:%h:%f\n"
    //   fi
    const char *p = path && strlen(path) ? path : "."; // replace an empty path by "." as current directory to allow for appending /name
    // BEGIN-STUDENTS-TO-ADD-CODE

	// check if directory exist
	if (access(p, F_OK) < 0) return;

	// read dir stat
	struct stat dirStat;
	if (stat(p, &dirStat) < 0) return;

	// check if path is directory and has access rights allowed
	if (!S_ISDIR(dirStat.st_mode) || access(p, X_OK) < 0) return;

	// open directory
	DIR *pDirectory = opendir(p);
	if (pDirectory == NULL) return;

	// read directory
	struct dirent *pDirDirent;
	const char *slash = "/";
	while ((pDirDirent = readdir(pDirectory)) != NULL) {

		// allocate memory for fullpath containing extra space for potential slash and \0
		char *fullpath = malloc( sizeof(char) * (strlen(p) + strlen(pDirDirent->d_name)) + sizeof(char) + sizeof(char) );
		strcpy(fullpath, p);

		// check if slash exists at the end otherwise add it
		if (p[strlen(p)-1] != '/') strcat(fullpath, slash);

		strcat(fullpath, pDirDirent->d_name);

		struct stat fileStat;
		if (stat(fullpath, &fileStat) < 0) continue;

		if (S_ISREG(fileStat.st_mode) && access(fullpath, X_OK) == 0) {
			printf("%li:%s:%s\n", i, path, pDirDirent->d_name);
		}

		free(fullpath);
	}

	// close directory
	closedir(pDirectory);

    // END-STUDENTS-TO-ADD-CODE
}

// # from lab P01_Bash
// paths="$1"
// [ -n "$paths" ] || paths="$PATH"
// 
// # input-field-separator: tells the shell to split in the 'for' loop the $var by ":"
// IFS=":"
// 
// for p in $paths
// do
//   i=$((i+1))
//   [ -n "$p" ] || p="."
//   if [ -d "$p" ] && [ -x "$p" ]
//   then
//      find -L "$p" -maxdepth 1 -type f -executable -printf "$i:%h:%f\n" 2>/dev/null
//   fi
// done

int main(int argc, const char *argv[])
{
	char *paths = malloc_copy(argc > 1 && argv[1][0] ? argv[1] : getenv("PATH"));
	if (strlen(paths) == 0) {
		return EXIT_SUCCESS; // nothing to do
	}
	size_t n = split_buffer_inplace(paths, ':'); // replaces all ':' by '\0' and returns the number of the resulting fields
	char *p = paths;
	for(size_t i = 1; i <= n; i++) { // 1...n
	    list_executables(i, p);
	    p += strlen(p) + 1; // readover the field and the trailing '\0' to get to the next field
	}
	free(paths);
	return EXIT_SUCCESS;
}
