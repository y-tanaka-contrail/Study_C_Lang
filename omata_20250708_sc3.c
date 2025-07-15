#include <stdio.h>

/* プロトタイプ宣言 */
int normalizeValue(int raw);

/* 定数 */
#define SCALE_FACTOR 102.4f  // 正規化のスケール値

int main() {
    int tempSensor;   // 入力値の温度センサ
    int lightSensor;  // 入力値の照度センサ
    int tempLevel;    // 正規化後の温度センサレベル
    int lightLevel;   // 正規化後の照度センサレベル

    // 温度センサ値を入力
    printf("温度センサ値を入力してください: ");
    scanf("%d", &tempSensor);

    // 範囲外の値を補正
    if (tempSensor < 0) {
        tempSensor = 0;
    } else if (tempSensor > 1023) {
        tempSensor = 1023;
    }
    
    // 照度センサ値を入力
    printf("照度センサ値を入力してください: ");
    scanf("%d", &lightSensor);

    // 範囲外の値を補正
    if (lightSensor < 0) {
        lightSensor = 0;
    } else if (lightSensor > 1023) {
        lightSensor = 1023;
    }

    // 各センサ値を正規化
    tempLevel = normalizeValue(tempSensor);
    lightLevel = normalizeValue(lightSensor);

    // 温度センサの状態を表示
    if (tempLevel <= 3) {
        printf("[温度] レベル%d → 温度が低いです\n", tempLevel);
    } else if (tempLevel <= 6) {
        printf("[温度] レベル%d → 温度は適切です\n", tempLevel);
    } else {
        printf("[温度] レベル%d → 温度が高いです\n", tempLevel);
    }

    // 照度センサの状態を表示
    if (lightLevel <= 2) {
        printf("[照度] レベル%d → 照度が非常に低い → LED ON\n", lightLevel);
    } else if (lightLevel <= 6) {
        printf("[照度] レベル%d → 照度は標準です\n", lightLevel);
    } else {
        printf("[照度] レベル%d → 照度が明るい → LED OFF\n", lightLevel);
    }

    return 0;
}

// 正規化関数
int normalizeValue(int raw) {
    int Raw = 0;
    Raw = (int)(raw / SCALE_FACTOR); // 小数点以下切り捨て
    return Raw;
}