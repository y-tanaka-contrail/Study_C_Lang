
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define TEMP_VAL_MIN 0
#define TEMP_VAL_MAX 1023
#define TEMP_LEVEL_RES 102.4f
#define LIGHT_VAL_MIN 0
#define LIGHT_VAL_MAX 1023
#define LIGHT_LEVEL_RES 102.4f

// 正規化関数：入力値をレベルに変換
int normalize_level(float value, float level_res) {
	return (int)(value / level_res);
}

// 入力値を検証して取得する関数
int get_valid_number(int min, int max) {
	int num;
	char buffer[16];
	char *endptr;

	while (1) {
		if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
			if ((buffer[0] == '\n') || (buffer[0] == '\0')) {
				printf("空の入力です。数値を入力してください。\n");
				continue;
			}

			num = strtol(buffer, &endptr, 10);

			if ((*endptr == '\n' || *endptr == '\0') && (num >= min && num <= max)) {
				return num;
			} else if (*endptr != '\n' && *endptr != '\0') {
				printf("無効な入力です。数値を入力してください。\n");
			} else {
				printf("範囲外の数値です。再度入力してください。\n");
			}
		} else {
			printf("入力エラーが発生しました。再度入力してください。\n");
		}
	}
}

// 温度レベルのメッセージ応答
const char* get_temperature_message(int level) {
	if (level >= 0 && level <= 3) {
		return "温度が低いです";
	} else if (level >= 4 && level <= 6) {
		return "温度が適切です";
	} else {
		return "温度が高いです";
	}
}

// 照度レベルのメッセージ応答
const char* get_light_message(int level) {
	if (level >= 0 && level <= 2) {
		return "照度が非常に低い -> LED ON";
	} else if (level >= 4 && level <= 6) {
		return "照度は標準です";
	} else {
		return "照度が明るい -> LED OFF";
	}
}

int main() {
	int temp_value;
	int temp_level;
	int light_value;
	int light_level;

	// 1回目の入力（温度）
	printf("温度センサの値を入力してください: ");
	temp_value = get_valid_number(TEMP_VAL_MIN, TEMP_VAL_MAX);
	temp_level = normalize_level((float)temp_value, TEMP_LEVEL_RES);

	// 2回目の入力（照度）
	printf("照度センサの値を入力してください: ");
	light_value = get_valid_number(LIGHT_VAL_MIN, LIGHT_VAL_MAX);
	light_level = normalize_level((float)light_value, LIGHT_LEVEL_RES);

	// 結果表示前の出力
	printf("Waiting ");
	for (int i = 0; i < 5; i++) {
		sleep(1);
		printf("・");
		fflush(stdout); // 出力を即座に反映
	}
	printf("\n");

	// 結果表示
	printf("[温度]レベル : %d -> %s\n", temp_level, get_temperature_message(temp_level));
	printf("[照度]レベル : %d -> %s\n", light_level, get_light_message(light_level));

	return 0;
}
