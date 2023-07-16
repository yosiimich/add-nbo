#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>



int main(int argc, char* argv[]) {
    FILE* file1;
    FILE* file2;

    file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        printf("argv[1] 파일을 열 수 없습니다.\n");
        return 1;
    }

    file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        printf("argv[2] 파일을 열 수 없습니다.\n");
        return 1;
    }

    uint32_t value1, value2;

    if (fread(&value1, sizeof(uint32_t), 1, file1) != 1) {
        printf("file1.txt 파일에서 값을 읽어오는데 오류가 발생했습니다.\n");
        return 1;
    }

    if (fread(&value2, sizeof(uint32_t), 1, file2) != 1) {
        printf("file2.txt 파일에서 값을 읽어오는데 오류가 발생했습니다.\n");
        return 1;
    }

    fclose(file1);
    fclose(file2);

    uint32_t value3 = ntohl(value1);
    uint32_t value4 = ntohl(value2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", value3, value3, value4, value4, value3+value4, value3+value4);
	
    return 0;
}


