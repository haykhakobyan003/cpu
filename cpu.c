#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int R0 = 0;
    int R1 = 0;
    int R2 = 0;
    int R3 = 0;

	FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

	if (fgetc(f) == EOF) {
    	printf("File is empty");
	} else {
    	rewind(f);
	}

    char line[100];

    while (fgets(line, sizeof(line), f) != NULL) {
        // printf("%s \n", line);
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
				R0 = R0 + R1;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R1 = R1 + R0;
			}else if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R0 = R0 + R0;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R1 = R1 + R1;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R2 = R2 + R3;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R3 = R3 + R2;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R2 = R2 + R2;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R3 = R3 + R3;
			}else if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R0 = R0 + R2;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R1 = R1 + R2;
			}else if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R0 = R0 + R3;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R1 = R1 + R3;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R2 = R2 + R0;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R2 = R2 + R1;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R3 = R3 + R0;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R3 = R3 + R1;
			}
        }
    }

	for (int i = 1; i < count; i++) {
        if (strcmp(words[i], "SUB") == 0) {
			if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R0 = R0 - R1;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R1 = R1 - R0;
			}else if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R0 = R0 - R0;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R1 = R1 - R1;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R2 = R2 - R3;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R3 = R3 - R2;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R2 = R2 - R2;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R3 = R3 - R3;
			}else if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R0 = R0 - R2;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R2") == 0) {
				R1 = R1 - R2;
			}else if (strcmp(words[i + 1], "R0") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R0 = R0 - R3;
			}else if (strcmp(words[i + 1], "R1") == 0 && strcmp(words[i + 2], "R3") == 0) {
				R1 = R1 - R3;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R2 = R2 - R0;
			}else if (strcmp(words[i + 1], "R2") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R2 = R2 - R1;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R0") == 0) {
				R3 = R3 - R0;
			}else if (strcmp(words[i + 1], "R3") == 0 && strcmp(words[i + 2], "R1") == 0) {
				R3 = R3 - R1;
			}
        }
    }

	for (int i = 0; i < count; i++) {
		if (strcmp(words[i], "PRINT") == 0) {
			if (strcmp(words[i + 1], "R0") == 0) {
				printf("%d\n", R0);
			} else if (strcmp(words[i + 1], "R1") == 0) {
				printf("%d\n", R1);
			} else if (strcmp(words[i + 1], "R2") == 0) {
				printf("%d\n", R2);
			} else if (strcmp(words[i + 1], "R3") == 0) {
				printf("%d\n", R3);
			}
		}
	}

	for (int i = 0; i < count; i++) {
		if (strcmp(words[i], "HALT") == 0) {
			exit(0);
		}
	}
	
    return 0;
}