const int green_led = 9;  // setting pin 9 to green led  
const int yellow_led = 10; // setting pin 10 to yellow led
const int red_led = 11;  // setting pin 11 to red led

String main_string = "Please! choose the color to light up ";
String color_string = "The colors are 'green', 'yellow', 'red' ";
String clear_command = "Type 'All' to turn on all the led or Type 'clear' to turn off all the led";
String get_color;

void setup() {
  Serial.begin(9600);
  
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  Serial.println(main_string);
  Serial.println(color_string);
  Serial.println(clear_command);
}

void loop() {
  while (Serial.available() == 0) {
    // wait for user input
  }
  get_color = Serial.readString();
  get_color.trim(); // remove any leading/trailing whitespace
  get_color.toLowerCase();
  Serial.println(get_color);

  // turn off all LEDs initially
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);

  if (get_color == "green") {
    digitalWrite(green_led, HIGH);
  } else if (get_color == "yellow") {
    digitalWrite(yellow_led, HIGH);
  } else if (get_color == "red") {
    digitalWrite(red_led, HIGH);
  } else if (get_color == "all") {
    digitalWrite(green_led, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, HIGH);
  }else if (get_color == "clear") {
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, LOW);
  } else {
    Serial.println("Invalid color! Please choose 'green', 'yellow', or 'red'.");
  }
}