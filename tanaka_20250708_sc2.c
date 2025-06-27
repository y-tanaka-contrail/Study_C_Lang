#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 1024
#define MAX_TOKENS 100

// 比較関数（ABC順）
int compare_abc(const void *a, const void *b) {
	return strcmp(*(const char **)a, *(const char **)b);
}

// 比較関数（文字数の少ない順）
int compare_length_asc(const void *a, const void *b) {
	return strlen(*(const char **)a) - strlen(*(const char **)b);
}

// 比較関数（文字数の多い順）
int compare_length_desc(const void *a, const void *b) {
	return strlen(*(const char **)b) - strlen(*(const char **)a);
}

int main() {
	char input[MAX_INPUT];
	char *tokens[MAX_TOKENS];
	int count = 0;
	int choice;

	// 並び替え方法の選択
	printf("並び替え方法を選んでください:\n");
	printf("1 : FIFO\n");
	printf("2 : LIFO\n");
	printf("3 : 文字数の少ない順\n");
	printf("4 : 文字数の多い順\n");
	printf("選択 (1-4): ");
	scanf("%d", &choice);
	getchar(); // 改行を読み飛ばす

	// 入力を取得
	printf("文字列を入力してください（カンマ区切り）: ");
	if (fgets(input, sizeof(input), stdin) == NULL) {
		fprintf(stderr, "入力エラー\n");
		return 1;
	}

	// 改行を除去
	input[strcspn(input, "\n")] = '\0';

	// カンマで分割
	char *token = strtok(input, ",");
	while (token != NULL && count < MAX_TOKENS) {
		tokens[count++] = token;
		token = strtok(NULL, ",");
	}

	// ソートまたは並び替え
	switch (choice) {
		case 1: // FIFO（そのまま）
			break;
		case 2: // LIFO（逆順）
			for (int i = count - 1; i >= 0; i--) {
				printf("%s\n", tokens[i]);
			}
			return 0;
		case 3: // 文字数の少ない順
			qsort(tokens, count, sizeof(char *), compare_length_asc);
			break;
		case 4: // 文字数の多い順
			qsort(tokens, count, sizeof(char *), compare_length_desc);
			break;
		default:
			printf("無効な選択です。\n");
			return 1;
	}

	// 出力
	for (int i = 0; i < count; i++) {
		printf("%s\n", tokens[i]);
	}

	return 0;
}
