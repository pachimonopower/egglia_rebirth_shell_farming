#include <SwitchControlLibrary.h>

// SCLを使いやすくするための自作ユーティリティ

// ボタン押下
void pushButton(int buttonType) {
  SwitchControlLibrary().pressButton(buttonType);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseButton(buttonType);
  SwitchControlLibrary().sendReport();
  delay(100);
}

// ボタン長押し
void holdButton(int buttonType, int milliSeconds) {
  SwitchControlLibrary().pressButton(buttonType);
  SwitchControlLibrary().sendReport();
  delay(milliSeconds);
  SwitchControlLibrary().releaseButton(buttonType);
  SwitchControlLibrary().sendReport();
  delay(100);
}

// ハット押下
void pushHat(int hatType) {
  SwitchControlLibrary().pressHatButton(hatType);
  SwitchControlLibrary().sendReport();
  delay(100);
  SwitchControlLibrary().releaseHatButton(hatType);
  SwitchControlLibrary().sendReport();
  delay(100);
}

// 長時間対応のdelay (精度悪なことに注意)
void delaySeconds(int seconds) {
  for (int i = 0; i < seconds; i++) {
    delay(1000);
  }
}
