#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <libgen.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char *argv[]) {
	
	int x = 0;
	int y = 0;
	int channels = 0;
	char filename[256];
	
	uint8_t *image = stbi_load(argv[1], &x, &y, &channels, STBI_rgb_alpha);
	
	int bytes = x * y * 4;
	
	// Set name based on the path
	snprintf(filename, sizeof(filename), "%s", basename((char*)argv[1]));
	
	// Strip the file extension off
	for (int i = strlen(filename) - 1; i > 0; i--) {
		if (filename[i] == '.') {
			filename[i] = '\0';
			break;
		}
	}
	
	// Output the contents to the console
	printf("static unsigned char %s[] = {\n", filename);
	for (int i = 0; i < bytes; i++) {
		if ((i) % 8 == 0) { printf("\t0x%02x, ", image[i]); }
		else if ((i + 1) % 8 == 0) { printf("0x%02x,\n", image[i]); }
		else { printf("0x%02x, ", image[i]); }
	}
	printf("};\n");
	
	stbi_image_free(image);
	
	return 0;
}
