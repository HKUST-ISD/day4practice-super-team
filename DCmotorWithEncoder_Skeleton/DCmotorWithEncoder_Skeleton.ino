/*Change all the ? in the code and add code in ??? to Control the speed of rotation.*/

#define IN1   5  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2   6   // Replace the ? with the GPIO pin you selected to connect IN2
#define A  16 // Replace the ? with the GPIO pin you selected to connect encoder A
#define B  15 // Replace the ? with the GPIO pin you selected to connect encoder B
#define PWM 7  // Replace the ? with the GPIO pin you selected to output PWM

// encoder output value
int A_data=0;
int B_data=0;

String command;

void setup() {
  /*setup baud and pin mode */
  // 初始化串口（波特率115200，兼容Serial Monitor和Serial Plotter）
  Serial.begin(115200);
  // 初始化L298N方向控制引脚为输出模式
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // 初始化PWM调速引脚为输出模式
  pinMode(PWM, OUTPUT);
  // 初始化编码器A/B相引脚为输入模式
  pinMode(A, INPUT);
  pinMode(B, INPUT);

  /*Set rotation direction as forward rotation (CCW)*/
  digitalWrite(IN1, HIGH);  // CCW要求IN1=HIGH
  digitalWrite(IN2, LOW);   // CCW要求IN2=LOW

}

void loop() {
    // send the duty cycle of PWM to control the speed of DC motor
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
        if (command == "0") {
        // output PWM signals with 0% duty cycle (0/255)
        analogWrite(PWM, 0);  
        } 
        else if (command == "25") {
        // output PWM signals with 25% duty cycle (25*255/100≈64)
        analogWrite(PWM, 64);   
        }
        else if (command == "50") {
        // output PWM signals with 50% duty cycle (50*255/100=128)
        analogWrite(PWM, 128);   
        }
        else if (command == "75") {
        // output PWM signals with 75% duty cycle (75*255/100≈191)
        analogWrite(PWM, 191);   
        }
        else if (command == "100") {
        // output PWM signals with 100% duty cycle (255/255)
        analogWrite(PWM, 255);   
        }
    }
    // Read values of A and B
    A_data = digitalRead(A);  // 读取编码器A相引脚状态（0/1）
    B_data = digitalRead(B);  // 读取编码器B相引脚状态（0/1）
    // Plot A B in Serial Plotter
    Serial.print("A:");
    Serial.print(A_data);
    Serial.print(",");
    Serial.print("B:");
    Serial.print(B_data);
    Serial.println("\t"); 
    
    // 增加短暂延时，避免数据刷屏过快（可选，优化体验）
    delay(10);
}