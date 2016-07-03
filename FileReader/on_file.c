#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	// Puntero a descriptor de fichero.
	FILE *fd = NULL;
	
	if(argc < 2) {
		printf("Use: %s file_name", argv[0]);
		return -1;
	}
	
	fd = fopen(argv[1], "r");
	if(fd == NULL) {
		fprintf(stderr, "[!] Error opening file: '%s' (r)\n", argv[1]);
		return -1;
	}
	
	// Recorrer todo el contenido del fichero.
	while(fgetc(fd) != EOF) {
		int a = fgetc(fd);
		ungetc(a, fd), a = 0;
	}
	
	fclose(fd);
	return 0;
}