#ifndef OUTER_INTERRUPT_H
#define  OUTER_INTERRUPT_H
// 割り込み発生を通知するためのフラグ
volatile bool interrupt_fired = false;

// ----------------------------------------------------
// メインコアで実行される割り込みハンドラ (ISR)
// ----------------------------------------------------
void main_core_isr() {
  interrupt_fired = true;
}


#endif //OUTER_INTERRUPT_H
