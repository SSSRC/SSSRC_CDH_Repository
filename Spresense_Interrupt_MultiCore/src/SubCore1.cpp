#include <Arduino.h> // Arduinoの基本関数を使うために必要
#include <MP.h>      // マルチコアライブラリ

// --- ピンの定義 ---
#define SUBCORE_PIN PIN_D16  // サブコアが制御するピン (D16)

// このファイルがワーカーとして呼ばれたときに実行されるエントリーポイント
extern "C" int main(int argc, char *argv[]) {
  
  // サブコアが使うピンを出力モードに設定
  pinMode(SUBCORE_PIN, OUTPUT);
  digitalWrite(SUBCORE_PIN, LOW);

  // 5秒待つ
  sleep(1);
  
  // D02ピンの電圧をLOWからHIGHに変える
  digitalWrite(SUBCORE_PIN, HIGH);

  return 0; // 処理を終了
}

