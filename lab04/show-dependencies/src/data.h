/**
 * @file
 * @brief  Access to the GCC produced dependency data (via gcc -H command line option).
 */

// begin of include guard
// BEGIN-STUDENTS-TO-ADD-CODE
#ifndef _DATA_H_
#define _DATA_H_

// END-STUDENTS-TO-ADD-CODE


// includes which are needed in this header file
// BEGIN-STUDENTS-TO-ADD-CODE
#include <stdio.h>

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief  Directory container for file entries of the dependency file.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {
	const char *name; /// < @brief the path name of the directory as given gcc
} dir_t;

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief  File container for the file entries of the dependency file.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {
	const char *name;
	size_t dir;
	size_t level;
} file_t;

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief  Overall container for all directories and all files from the dependency file.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {
	size_t n_dirs;
	dir_t *dirs;
	size_t n_files;
	file_t *files;
} data_t;

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief            Entry function to read the deendency data from stdin.
 * @param root [IN]  The name of the root file (the deoendency file does not mention the root file, so, it has to be passed from outside).
 * @return           The container of the read data from stdin. See the documentation on gcc -H for details on the dependencies, etc.
 */
// BEGIN-STUDENTS-TO-ADD-CODE
const data_t data_read_all(const char *root);

// END-STUDENTS-TO-ADD-CODE



// end of include guard
// BEGIN-STUDENTS-TO-ADD-CODE
#endif

// END-STUDENTS-TO-ADD-CODE
