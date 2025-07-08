#include <stdio.h>
#include <string.h>
#define STR_TOKEN ","
#define MAX_TOKEN 100
#define MAX_TOKEN_LEN 101
#define MAX_INPUT_STR 1024

int splitString(char* str, char* tokens[MAX_TOKEN]);

int main()
{
	char *arryTokens[MAX_TOKEN];	// カンマ区切りした文字列格納用
	char *inputStr;					// 入力文字列
	int count;						// カンマ区切りした文字列の数
	int i;							// ループ用

	// メモリ確保
	inputStr = (char *)malloc((MAX_INPUT_STR) * sizeof(char));
	if (inputStr == NULL) {
		printf("メモリ確保失敗.\n");
		return -1;
	}

	// 文字列の初期化
	memset(inputStr, 0, MAX_INPUT_STR);

	printf("文字列を入力してください（カンマで区切ってください）: \n");
	fgets(inputStr, MAX_INPUT_STR, stdin);

	// 改行をNULLにする
	inputStr[strcspn(inputStr, "\n")] = '\0';
	
	// 入力した文字列を分割する
	count = splitString(inputStr, arryTokens);

    // メモリ確保失敗    
    if(count == -1)
    {
	    free(inputStr);
		return -1;
    }

	if(count != 0)
	{
		for(i = 0; i < count; i++)
		{
			printf("[%d]: %s\n", i, arryTokens[i]);
			free(arryTokens[i]);
		}
	}
	else
	{
		printf("文字が入力されませんでした。\n");
	}

	/* 入出力ストリームに残ったデータをクリア */
	while (((getchar()) != '\n') && !feof(stdin));
	free(inputStr);
	getchar();
	return 0;
}

/* 文字列分割関数                            */
/* 処理 : 文字列をカンマで分割し、           */
/*        各トークンをtokens配列に格納する。 */
/* input parameter  ：str                    */
/* output parameter : tokens                 */
/* return value     : count                  */
int splitString(char* str, char* tokens[MAX_TOKEN])
{
	int count = 0;
	char* token;

	if(str != NULL)
	{
		// 最初のトークンを取得
		token = strtok(str, STR_TOKEN);	

		// トークンがNULL且つ、countがMAX_TOKENより小さい間、ループする
		while (token != NULL && count < MAX_TOKEN)
		{
			tokens[count] = (char *)malloc(MAX_TOKEN_LEN);
			if (tokens[count] == NULL)
			{
				printf("トークンのメモリ確保失敗.\n");
				count = -1;
				break;
			}
			strncpy(tokens[count], token, (MAX_TOKEN_LEN - 1));
			tokens[count][MAX_TOKEN_LEN - 1] = '\0'; // 終端文字
			count++;
			
			// 次のトークンを取得
			token = strtok(NULL, STR_TOKEN);
		}
	}
	return count;
}
