#include <stdio.h>
#include <string.h>

/* 定数 */
#define MAX_INPUT_SIZE      100                          // 最大入力文字数
#define MAX_TASKS   10                                   // 最大10個まで格納できる配列用（分割したタスクを格納する）

/* プロトタイプ宣言 */
void clear_input_buffer();
int parseTasks(char *input, char tasks[][MAX_INPUT_SIZE]);


int main() {
    char input[MAX_INPUT_SIZE];                          // 入力値を格納する配列
    char tasks[MAX_TASKS][MAX_INPUT_SIZE];               // タスクを格納する配列
    int taskCount = 0;

    // 入力値を取得
    printf("文字列をカンマで区切って入力してください。");
    fgets(input, MAX_INPUT_SIZE, stdin);

    if (strchr(input, '\n')) {
        input[strcspn(input, "\n")] = '\0';              // 入力値に改行があった場合、終端文字に置き換え       
    } else {
        clear_input_buffer();                            // 入力値に改行が無い場合、バッファを削除
    }

    // タスクをパースして配列に格納
    taskCount = parseTasks(input, tasks);

    // FIFO順にタスクを出力
    for (int i = 0; i < taskCount; i++) {
        printf("%s\n", tasks[i]);
    }

    return 0;

}

// ★バッファ削除関数
void clear_input_buffer() {
    while (getchar() != '\n') {
    // 何もしない（残りの入力を消費）
    }
}

// カンマで文字列を分割して配列に格納する関数
int parseTasks(char *input, char tasks[][MAX_INPUT_SIZE]) {
    int count = 0;
    char *string;                                        // 分割した文字列のポインタ
    
    string = strtok(input, ",");                         // 入力値の文字列をカンマ区切りで分割
    
    // 文字列毎に分割して配列に格納
    while (string != NULL) {
        // 余分な空白を取り除く
        while (*string == ' ') {
            string++;
        }

        strncpy(tasks[count], string, MAX_INPUT_SIZE);    // 分割した文字列を配列に格納
        //tasks[count][strcspn(tasks[count], "\n")] = '\0'; // 改行を取り除く
        count++;
        string = strtok(NULL, ",");
    }
    return count;
}