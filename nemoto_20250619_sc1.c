#include <stdio.h>
#include <string.h>


int main(void) {

    char str[101];
    int str_cnt,i;

    // 標準入力から1行（最大100文字）を読み込む
    scanf("%100s",str);

    // フレーム全体の幅を計算
    str_cnt=strlen(str);

    // 上部の枠（星）を出力
    for(i=1;i<=str_cnt+4;i++){
        printf("*");
    }

    // 中央の行を出力
    printf("\n* %s *\n",str);

    // 下部の枠（星）を出力
    for(i=1;i<=str_cnt+4;i++){
        printf("*");
    }
    return 0;
}