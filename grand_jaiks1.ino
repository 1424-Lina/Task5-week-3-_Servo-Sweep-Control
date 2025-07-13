#include <Servo.h>

// إنشاء ثلاث كائنات للسيرفو
Servo servo1;
Servo servo2;
Servo servo3;

unsigned long startTime;
bool sweepDone = false;

void setup() {
  // ربط السيرفوهات مع منافذ PWM
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);

  startTime = millis();  // بدء التوقيت
}

void loop() {
  if (!sweepDone) {
    // تنفيذ حركة sweep لمدة ثانيتين
    for (int pos = 0; pos <= 180; pos += 1) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      delay(10);
      if (millis() - startTime > 2000) {
        sweepDone = true;
        break;
      }
    }

    for (int pos = 180; pos >= 0; pos -= 1) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      delay(10);
      if (millis() - startTime > 2000) {
        sweepDone = true;
        break;
      }
    }
  } else {
    // تثبيت السيرفوهات على 90 درجة
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
  }
}