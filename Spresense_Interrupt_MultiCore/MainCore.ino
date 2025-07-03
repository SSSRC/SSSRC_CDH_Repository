#include <MP.h>
#include "Outer_Interrupt.h"

//マクロ設定
#define MAINCORE_INTERRUPT_INPUT_PIN PIN_23
// ----------------------------------------------------
// メインコアの初期設定
// ----------------------------------------------------
void setup() {
  Serial.begin(115200);
  pinMode(LED0_PIN, OUTPUT);
  digitalWrite(LED0_PIN, LOW);

  // 割り込みピンを設定
  pinMode(MAINCORE_INTERRUPT_PIN, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(MAINCORE_INTERRUPT_INPUT_PIN), main_core_isr, RISING);

  // --- マルチコアの開始 ---
  MP.begin();
  // srcフォルダにあるサブコアコードを、コア1にロードして実行開始
  MP.load(1, "SubCore1"); 
  MP.load(2, "SubCore2");

  Serial.println("Main core: Setup finished. Waiting for interrupt...");
}

// ----------------------------------------------------
// メインコアのメインループ
// ----------------------------------------------------
void loop() {
  if (interrupt_fired) {
    interrupt_fired = false;
    Serial.println("Main core: Interrupt received! Turning on LED0.");
    for(i=0;i<=5;i++){
      digitalWrite(LED0_PIN, HIGH);
      delay(500);
      digitalWrite(LED0_PIN, LOW);
    };
  };
}


