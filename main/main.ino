#include <SwitchControlLibrary.h>

// コントローラ認識まで
void setup() {

  // 初期化
  SwitchControlLibrary();

  // 起動 A連打
  for (int i = 0; i < 10; i++) {
    pushButton(Button::A);
    delay(100);
  }
}

// マクロ本体
void loop() {

  // テスト とりあえずAを押すだけ
  //while (true) {
  //  pushButton(Button::A);
  //  delay(500);
  //}

  // フィールドに入る (A)5回
  for (int i = 0; i < 5; i++) {
    pushButton(Button::A);
    delay(1000);
  }

  // フィールド開始待ち
  delay(10000);

  // 行動開始
  int MAX_TURN = 7;
  for (int i = 1; i <= MAX_TURN; i++) {
    // サイコロ振る (A)
    pushButton(Button::A);
    delay(2000);
  
    // 上に進む (↑)
    //pushButton(HatButton::UP); // ハット押すとYボタンと認識されるのだが？
    //SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::MIN);
    //delay(100);
    //SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
    SwitchControlLibrary().moveHat(Hat::UP);
    SwitchControlLibrary().sendReport();
    delay(200);
    SwitchControlLibrary().moveHat(Hat::NEUTRAL);
    SwitchControlLibrary().sendReport();
    delay(800);

    // 行動確定 (A)3回
    pushButton(Button::A);
    delay(500);
    pushButton(Button::A);
    delay(500);
    pushButton(Button::A);
    delay(500);
    
    // 最終ターン
    if (i == MAX_TURN) {
      // CLEAR
      delay(500);
      pushButton(Button::A);
      delay(2000);
    }

    // 4ターン目は木が切れるモーション待ち
    if (i == 4) {
      delay(4000);
    }

    // ターン終了待ち
    delay(2000);
  }

  // Push A Button
  pushButton(Button::A);
  delay(1000);
  pushButton(Button::A);
  delay(4000);
  pushButton(Button::A);
  delay(500);

  // フィールド選択画面待ち
  delay(10000);
}
