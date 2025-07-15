#include <stdio.h>

int main(void) {
    int ADC_value;        // ADCの読み取り値（0〜4095）
    double voltage;       // 電圧[V]
    double mV;            // 電圧[mV]
    double SOC;           // バッテリー残量[%]

    // 標準入力からADC値を読み込む
    printf("ADC値を入力してください (0〜4095): ");
    scanf("%d", &ADC_value);

    // 電圧(V)の計算：ADC値を電圧に変換（0?3.3V）
    voltage = ADC_value / 4095.0 * 3.3;

    // 電圧(mV)に変換（ボルトからミリボルトへ）
    mV = voltage * 1000;

    // バッテリー残量（SOC: State of Charge）の計算
    SOC = (voltage - 3.0) / (4.2 - 3.0) * 100;

    // 範囲外の値をクリップ（0~100%に収める）
    if (SOC < 0) SOC = 0;
    if (SOC > 100) SOC = 100;

    // 小数点以下2桁でフォーマットして出力
    printf("Voltage: %.2f mV\n", mV);
    printf("Battery: %.2f %%\n", SOC);

    return 0;
}