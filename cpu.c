#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), f) != NULL) {
        printf("%s", line);
    }

	char words[100][100];
	int i = 0;
	int count = 0;

	char *p = strtok(line, " ");

	while (p != NULL) {
    	strcpy(words[i], p);
    	i++;
		count++;
    	p = strtok(NULL, " ");
	}

    int R0 = 0;
    int R1 = 0;
    int R2 = 0;
    int R3 = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], "SET") == 0) {
			if (strcmp(words[i + 1], "R0") == 0) {
				R0 = atoi(words[i + 2]);
			} else if (strcmp(words[i + 1], "R1") == 0) {
				R1 = atoi(words[i + 2]);
			} else if (strcmp(words[i + 1], "R2") == 0) {
				R2 = atoi(words[i + 2]);
			} else if (strcmp(words[i + 1], "R3") == 0) {
				R3 = atoi(words[i + 2]);
			}
        }
    }

	for (int i = 1; i < count; i++) {
        if (strcmp(words[i], "ADD") == 0) {
			if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R2 = R0 + R1;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R2 = R1 + R0;
			}else if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R2 = R0 + R0;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R2 = R1 + R1;
			}
        }
    }
	
    printf("\nR0 = %d\n", R0);
    printf("R1 = %d\n", R1);
    printf("R2 = %d\n", R2);
    printf("R3 = %d\n", R3);

    return 0;
}