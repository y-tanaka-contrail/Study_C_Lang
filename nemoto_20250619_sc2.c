#include <stdio.h>

int main(void) {


    int ADC_value;
    float V,mV,SOC;

    // ADCの値を標準入力から読み込む
    scanf("%d",&ADC_value);

    // ADCの値から電圧（V）を計算する
    V = ADC_value / 4095.0 * 3.3;

    // 電圧（V）から電圧（mV）を計算する
    mV=V*1000;
    
    //電圧（V）からバッテリー残量(SOC, %)を計算する
    SOC = (V - 3.0) / (4.2 - 3.0) * 100;
    if (SOC < 0){ 
        SOC = 0;
    }else if (SOC > 100){
        SOC = 100;
    }
    //電圧（mV）とバッテリー残量(%)を出力する    
    printf("Voltage: %.2f mV\nBattery: %.2f %%",mV,SOC);

    //バッテリー残量が問題の出力結果と違う(根本メモ)

    return 0;
}