#include <stdio.h>

int main(int argc, char *argv[]) {
    // Cek apakah ada argumen yang diberikan (selain nama program)
    if (argc < 2) {
        printf("Usage: %s <parameter1> <parameter2> ...\n", argv[0]);
        return 1;
    }

    // Menampilkan semua argumen yang diberikan
    printf("Daftar Argumen yang Diberikan:\n");
    for (int i = 1; i < argc; i++) {
        printf("Argumen %d: %s\n", i, argv[i]);
    }

    return 0;
}
