#include <stdio.h>
#include <stdlib.h>

#include "file_io.h"
#include "parser.h"

int main(void) {
	char* contents = read_file("sample.toml");

	struct List** lists = parse_file(contents);

	// Ensure we free the lists
	for (size_t i = 0; lists[i] != NULL; ++i) {
		free_list(lists[i]);
	}

	free(lists);

	free(contents);

	return 0;
}
