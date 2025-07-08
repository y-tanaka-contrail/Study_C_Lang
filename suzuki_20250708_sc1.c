#include <stdio.h>

// 定数定義
#define STR_LEVEL "レベル"
#define STR_TEMP "[温度]"
#define STR_TEMP_LOW "温度が低いです"
#define STR_TEMP_PROP "温度が適切です"
#define STR_TEMP_HIGH "温度が高いです"
#define STR_LIGHT "[照度]"
#define STR_LIGHT_LOW "照度が非常に低い → LED_ON"
#define STR_LIGHT_PROP "照度は標準です"
#define STR_LIGHT_HIGH "照度が明るい → LED_OFF"

#define MIN_VALUE 0.0f
#define MAX_VALUE 1023.0f
#define NORMALIZE_VALUE 102.4f

enum
{
	LEVEL_0 = 0,
	LEVEL_1,
	LEVEL_2,
	LEVEL_3,
	LEVEL_4,
	LEVEL_5,
	LEVEL_6,
	LEVEL_7,
	LEVEL_8,
	LEVEL_9
};

// プロトタイプ宣言
int normalizeValue(float raw);

int main()
{
	float tempSensor;	// 温度センサ 生値
	float lightSensor;	// 照度センサ 生値
	int tempLevel;		// 温度センサ レベル
	int lightLevel;		// 照度センサ レベル

	printf("温度センサ値を入力してください: ");
	// 正しい値が入力されるまでループする
	while(1)
	{
		scanf("%f", &tempSensor);
		if((MIN_VALUE <= tempSensor) && (tempSensor <= MAX_VALUE))
		{
			break;
		}
		else
		{
			printf("温度センサ値は、0～1023の間で入力してください: ");
		}
	}

	printf("照度センサ値を入力してください: ");
	// 正しい値が入力されるまでループする
	while(1)
	{
		scanf("%f", &lightSensor);
		if((MIN_VALUE <= lightSensor) && (lightSensor <= MAX_VALUE))
		{
			break;
		}
		else
		{
			printf("照度センサ値は、0～1023の間で入力してください: ");
		}
	}

	// 温度センサ正規化
	tempLevel = normalizeValue(tempSensor);

	// レベル条件判定&出力
	if(LEVEL_0 <= tempLevel && tempLevel <= LEVEL_3)
	{
		printf("%s %s%d: %s\n", STR_TEMP, STR_LEVEL, tempLevel, STR_TEMP_LOW);
	}
	else if(LEVEL_4 <= tempLevel && tempLevel <= LEVEL_6)
	{
		printf("%s %s%d: %s\n", STR_TEMP, STR_LEVEL, tempLevel, STR_TEMP_PROP);
	}
	else if(LEVEL_7 <= tempLevel && tempLevel <= LEVEL_9)
	{
		printf("%s %s%d: %s\n", STR_TEMP, STR_LEVEL, tempLevel, STR_TEMP_HIGH);
	}

	// 照度センサ正規化
	lightLevel = normalizeValue(lightSensor);
	
	// レベル条件判定&出力
	if(LEVEL_0 <= lightLevel && lightLevel <= LEVEL_2)
	{
		printf("%s %s%d: %s\n", STR_LIGHT, STR_LEVEL, lightLevel, STR_LIGHT_LOW);
	}
	else if(LEVEL_3 <= lightLevel && lightLevel <= LEVEL_6)
	{
		printf("%s %s%d: %s\n", STR_LIGHT, STR_LEVEL, lightLevel, STR_LIGHT_PROP);
	}
	else if(LEVEL_7 <= lightLevel && lightLevel <= LEVEL_9)
	{
		printf("%s %s%d: %s\n", STR_LIGHT, STR_LEVEL, lightLevel, STR_LIGHT_HIGH);
	}
	return 0;
}

/* 正規化関数                  */
/* input ： 生値               */
/* output： レベル             */
int normalizeValue(float raw)
{
	int level = 0;
	level = raw / NORMALIZE_VALUE;
	return level;
}
