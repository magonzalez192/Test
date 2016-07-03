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
	
	int file_size = 0;
	
	fseek(fd, 0, SEEK_END);
	file_size = ftell(fd);
	rewind(fd);
	if(!file_size) {
		fprintf(stderr, "[!] File looks empty\n");
		return -1;
	}
	
	char *file_content = (char *)malloc(file_size * sizeof(char));
	if(file_content == NULL) {
		printf("[!] Error reserving memory for %d MBs\n", file_size >> 20);
		return -1;
	}
	fread(file_content, file_size, 1, fd);
	
	// Recorrer todo el contenido del fichero, cargado ahora en memoria.
	int i_l;
	for(i_l = 0; i_l < file_size; i_l++) {
		int a = *file_content == 'a' ? 0 : 1;
	}
	
	free(file_content);
	fclose(fd);
	return 0;
}