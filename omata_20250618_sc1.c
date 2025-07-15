#include <stdio.h>
#include <string.h>

int main(void) {
    
    // 標準入力から1行（最大100文字）を読み込む
    char input[101];
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    // 改行があった場合、改行を取り除く
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0'; 
        len--;
    }

    // フレーム全体の幅を計算
    size_t len = strlen(input);

    int frame_width = (int)len + 4; // フレーム全体の幅（文字列＋両側スペース2＋両側アスタリスク2）

    // 上部の枠（星）を出力
    for (int i = 0; i < frame_width; i++) {
        putchar('*');
    }
    putchar('\n');

    // 中央の行を出力
    printf("* %s *\n", input);

    // 下部の枠（星）を出力
    for (int i = 0; i < frame_width; i++) {
        putchar('*');
    }

    return 0;
}