#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_STR 1024

int main()
{
	char *reverseStr;	            // 入力された文字列を逆順表示する文字列
	char *inputStr;					// 入力文字列
	int count;						// 文字列の数
	int i;	                        // 入力された文字列を数えるための変数
    int j;	                        // 逆順の文字列を数えるための変数

    // メモリ確保
    inputStr = (char *)malloc((MAX_INPUT_STR) * sizeof(char));
	if (inputStr == NULL) {
		printf("メモリ確保失敗.\n");
		return -1;
	}

    // 文字列の初期化
    memset(inputStr, 0, MAX_INPUT_STR);
    
    // 文字列の入力
    printf("文字列を入力してください \n");
	fgets(inputStr, MAX_INPUT_STR, stdin);



    //改行をNULLにする

    i = 0;
    while (*(inputStr +i) != '\0') {
        if (*(inputStr +i) == '\n') {
            *(inputStr +i) = '\0';
            break;
        }
        i++;
    }
    
    // 入力長さを求める
    count = 0;
     while (*(inputStr + count) != '\0') {
        count++;
      }

    // コピー先のメモリ確保
    reverseStr = (char *)malloc((count + 1) * sizeof(char));
	if (reverseStr == NULL) {
		printf("メモリ確保失敗.\n");
		return -1;
	}

    // 文字列を逆順でコピー
    j=0;
    for (i = count -1 ; i >= 0; i--) {
       *(reverseStr + j) = *(inputStr + i);
       j++;
    }
    *(reverseStr + j) = '\0';

    // 結果を表示
    printf("Reversed:%s\n", reverseStr);


    // メモリ解放
    free(inputStr);
    free(reverseStr);
    return 0;

}