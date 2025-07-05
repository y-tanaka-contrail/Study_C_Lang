#include <stdio.h>

// センサ値を0～9に正規化する関数
int normalizeValue(int raw) {
    int level = (int)( raw/102.4 ); 
    return level > 9 ? 9 : level;
    // 小数点以下切り捨ての整数に（暗黙の型変換）
}

int main() {
    int tempSensor, lightSensor;

    // 入力
    printf("温度センサ値を入力してください: ");
    scanf("%d", &tempSensor);

    printf("照度センサ値を入力してください: ");
    scanf("%d", &lightSensor);

    // 正規化
    int tempLevel = normalizeValue(tempSensor);
    int lightLevel = normalizeValue(lightSensor);

    // 温度レベルの出力
    printf("[温度] レベル%d → ", tempLevel);
    if (tempLevel <= 3) {
        printf("温度が低いです\n");
    } else if (tempLevel <= 6) {
        printf("温度は適切です\n");
    } else {
        printf("温度が高いです\n");
    }

    // 照度レベルの出力
    printf("[照度] レベル%d → ", lightLevel);
    if (lightLevel <= 2) {
        printf("照度が非常に低い → LED ON\n");
    } else if (lightLevel <= 6) {
        printf("照度は標準です\n");
    } else {
        printf("照度が明るい → LED OFF\n");
    }

    return 0;
}