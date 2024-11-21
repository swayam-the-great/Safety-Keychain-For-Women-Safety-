// Pin where the button is connected
const int buttonPin = 2;
// Variable to store the button state
int buttonState = 0;

// Phone number and message content
String phoneNumber = "+918085983815"; 
String message = "Hello, this is a test message from Arduino!";
String callNumber = "+9180858983815"; // Call number

void setup() {
  // Set the button pin as input with internal pull-up
  pinMode(buttonPin, INPUT_PULLUP); // Use INPUT_PULLUP to avoid using an external pull-down resistor
  
  // Initialize serial communication for debugging and A9G communication
  Serial.begin(9600);

  // Small delay to allow the A9G module to start up
  delay(5000); // Adjust if needed to ensure the A9G is ready
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (LOW because of INPUT_PULLUP)
  if (buttonState == LOW) {
    // Print to Serial Monitor that the button is pressed
    Serial.println("Button Pressed!");
    
    // Call the function to send an SMS
    sendSMS(phoneNumber, message);
    
    // Delay between sending SMS and making a call
    delay(3000); // Wait for 3 seconds before making the call
    
    // Call the function to make a call
    makeCall();
    
    // Delay to prevent multiple triggering while the button is held
    delay(1000);
  }
}

// Function to send SMS
void sendSMS(String phone, String msg) {
  Serial.println("Sending SMS...");

  // Set the SMS mode to text
  Serial.println("AT+CMGF=1");
  delay(1000); // Wait for the command to process
  
  // Set the recipient phone number
  Serial.print("AT+CMGS=\"");
  Serial.print(phone);
  Serial.println("\"");
  delay(1000); // Wait for the command to process
  
  // Send the SMS content
  Serial.print(msg);
  delay(1000); // Wait for the message to be prepared
  
  // Send Ctrl+Z to mark the end of the message
  Serial.write(26); // ASCII code for Ctrl+Z
  delay(1000); // Wait for the message to be sent
  
  Serial.println("Message sent!");
}

// Function to make a call
void makeCall() {
  Serial.println("ATD+918085983815");
   // The semicolon is important to indicate a call
  delay(1000); // Wait for the command to process
  
  
}