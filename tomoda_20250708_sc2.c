#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024
#define MAX_TASKS 100

// 前後の空白を除去する関数
char* trim(char *str) {
    while (isspace((unsigned char)*str)) str++;  // 先頭の空白をスキップ
    if (*str == '\0') return str;  // 全て空白だった場合

    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;  // 末尾の空白をスキップ
    *(end + 1) = '\0';

    return str;
}

// タスクをカンマで分割し、空白を除去しつつ動的確保して配列に格納
int parseTasks(char *input, char **tasks, int maxTasks) {
    int count = 0;
    char *token = strtok(input, ",");

    while (token != NULL) {
        char *clean = trim(token);
        size_t len = strlen(clean);

        if (len == 0) {  // 空タスクはスキップ
            token = strtok(NULL, ",");
            continue;
        }

        if (count >= maxTasks) {
            fprintf(stderr, "タスク数が上限（%d）を超えました。一部のタスクは無視されます。\n", maxTasks);
            break;
        }

        tasks[count] = malloc(len + 1);
        if (tasks[count] == NULL) {
            fprintf(stderr, "メモリ確保に失敗しました\n");
            // これまでに確保したメモリを解放
            for (int i = 0; i < count; i++) {
                free(tasks[i]);
            }
            return -1;
        }

        strcpy(tasks[count], clean);
        count++;
        token = strtok(NULL, ",");
    }

    return count;
}

int main() {
    char input[MAX_INPUT];
    char *tasks[MAX_TASKS];

    printf("タスクをカンマ区切りで入力してください: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "入力エラーです\n");
        return 1;
    }

    // 改行除去
    input[strcspn(input, "\n")] = '\0';

    int taskCount = parseTasks(input, tasks, MAX_TASKS);
    if (taskCount < 0) {
        return 1;  // エラー終了
    }

    // FIFO順で出力
    for (int i = 0; i < taskCount; i++) {
        printf("%s\n", tasks[i]);
        free(tasks[i]);  // メモリ解放
    }

    return 0;
}
