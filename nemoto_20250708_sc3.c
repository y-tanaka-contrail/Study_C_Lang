
#include <stdio.h>
#include <string.h>

//　プロトタイプ宣言
int normalizeValue(int raw);


int main(void)
{
	int tempSensor;			// 温度データ入力用
	int lightSensor;		// 照度データ入力用
	int tempLevel;			// 温度センサレベル用
	int lightLevel;			// 照度センサレベル用


	// 温度データ値を入力
	printf("温度データ値を入力してください:");
	scanf("%d", &tempSensor);

	// 温度データ値が0～1023以外なら終了
	if(tempSensor < 0 || tempSensor > 1023){
		printf("0から1023の値を入力してください。\n");
		return -1;
	}
	// 照度データ値を入力
	printf("照度データ値を入力してください:");
	scanf("%d", &lightSensor);

	// 照度データ値が0～1023以外なら終了
	if(lightSensor < 0 || lightSensor > 1023){
		printf("0から1023の値を入力してください。\n");
		return -1;
	}

	// 温度レベル、照度レベルを求める
	tempLevel = normalizeValue(tempSensor);
	lightLevel = normalizeValue(lightSensor);

	// 温度センサの状態を表示
	if(tempLevel <= 3){
		printf("[温度]レベル%d→温度が低いです\n", tempLevel);
	}else if(tempLevel >= 4 && tempLevel <= 6){
		printf("[温度]レベル%d→温度は適切です\n", tempLevel);
	}else{
		printf("[温度]レベル%d→温度が高いです\n", tempLevel);
	}

	// 照度センサの状態を表示
	if(lightLevel<=3){
		printf("[照度]レベル%d→照度が非常に低い→LED ON\n", lightLevel);
	}else if(lightLevel >= 4 && lightLevel <= 6){
		printf("[照度]レベル%d→照度は標準です\n", lightLevel);
	}else{
		printf("[照度]レベル%d→照度が明るい→LED OFF\n", lightLevel);
	}

	return 0;
}


//正規化      
// input ： 温度センサ値、照度センサ値
// output：	温度レベル、照度レベル
int normalizeValue(int raw)
{
	float level;
	level = ((float)raw) / 102.4f;

	return (int)level;

}

