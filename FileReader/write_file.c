#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	// Iterador para bucle for y tamaño en MBs de fichero.
	int i_l, size = 64;
	// File descriptor.
	FILE *fd = NULL;
	
	if(argc < 2) {
		printf("Use: %s file_name [size_on_mb = 64]", argv[0]);
		return -1;
	} else if(argc > 2) {
		size = atoi(argv[2]);
	}
	
	fd = fopen(argv[1], "w+");
	if(fd == NULL) {
		fprintf(stderr, "[!] Error opening file: '%s' (w+)\n", argv[1]);
		return -1;
	}
	
	for(i_l = size << 20; i_l > 0; i_l--) {
		fputc(0x61, fd);
	}	
	
	fclose(fd);
	return 0;
}