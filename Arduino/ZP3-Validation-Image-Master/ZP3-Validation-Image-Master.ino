#include <SPI.h>
String sendMessage = "Test Passed";
String receivedMessage;

void setup() {
  // put your setup code here, to run once:

  // Setup USB UART for debug messages
  Serial.begin(115200);

  // Setup the UART pins
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);

  // Setup the GPIO pins
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  // Run the first set of tests
  Test_One();

  // Run the second set of tests
  Test_Two();

}

void loop() {
  // put your main code here, to run repeatedly:
}

void Test_One() {

  // UART TESTS //
  // ZP3 - LPUART1
  // Transmit the string sendMessage
  Serial1.print(sendMessage);
  // While there is text written in the serial monitor, read and append to receivedMesssage
  while(Serial1.available() > 0) {
    char receivedChar = Serial1.read();
    receivedMessage += receivedChar;
  }
  // If the recieved messsage is the same as the sent, then ZP3 has successfully echo'd the message
  if(receivedMessage.equals(sendMessage))
    Serial.println("[OK] LPUART1 echo");
  else {
    Serial.println("[ERR] LPUART1 values not equal");
  }
  // Reset receivedMessage variable for next test
  receivedMessage = "";
  
  // ZP3 - USART1
  Serial2.print(sendMessage);
  while(Serial2.available() > 0) {
    char receivedChar = Serial2.read();
    receivedMessage += receivedChar;
  }
  if(receivedMessage.equals(sendMessage))
    Serial.println("[OK] USART1 echo");
  else {
    Serial.println("[ERR] USART1 values not equal");
  }
  receivedMessage = "";

  // ZP3 - USART2
  Serial3.print(sendMessage);
  while(Serial3.available() > 0) {
    char receivedChar = Serial3.read();
    receivedMessage += receivedChar;
  }
  if(receivedMessage.equals(sendMessage))
    Serial.println("[OK] USART2 echo");
  else {
    Serial.println("[ERR] USART2 values not equal");
  }
  receivedMessage = "";

  // GPIO TESTS //
  // GPIO_1
  if(!digitalRead(0)) Serial.println("[OK] GPIO_1 is LOW");
  else {
    Serial.println("[ERR] GPIO_1 is not LOW");
  }
  // GPIO_2
  if(!digitalRead(1)) Serial.println("[OK] GPIO_2 is LOW");
  else {
    Serial.println("[ERR] GPIO_2 is not LOW");
  }
  // GPIO_3
  digitalWrite(2,0);
  

}

void Test_Two() {

  // UART TESTS //
  // ZP3 - USART3
  Serial1.print(sendMessage);
  while(Serial1.available() > 0) {
    char receivedChar = Serial1.read();
    receivedMessage += receivedChar;
  }
  if(receivedMessage.equals(sendMessage))
    Serial.println("[OK] USART3 echo");
  else {
    Serial.println("[ERR] USART3 values not equal");
  }
  receivedMessage = "";

  // ZP3 - UART4
  Serial2.print(sendMessage);
  while(Serial2.available() > 0) {
    char receivedChar = Serial2.read();
    receivedMessage += receivedChar;
  }
  if(receivedMessage.equals(sendMessage))
    Serial.println("[OK] UART4 echo");
  else {
    Serial.println("[ERR] UART4 values not equal");
  }
  receivedMessage = "";

}