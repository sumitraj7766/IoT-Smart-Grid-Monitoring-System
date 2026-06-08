#define BLYNK_TEMPLATE_ID "TMPL3GrD30vII"
#define BLYNK_TEMPLATE_NAME "Smart Grid Monitoring"
#define BLYNK_AUTH_TOKEN "M1tnVdqIPYmlnIF7Ww3lGe3_i-iiOOnf"

#include <WiFi.h>
#include <WebServer.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

char pass[] = "";

WebServer server(80);
BlynkTimer timer;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define VOLTAGE_PIN 34
#define CURRENT_PIN 35
#define FREQ_PIN 32
#define PHOTO_PIN 33
#define BUTTON_PIN 25

#define RELAY_PIN 26
#define BUZZER_PIN 27
#define GREEN_LED 14
#define RED_LED 12

float voltage = 0, current = 0, frequency = 0, temperature = 0;
int lightValue = 0;
String status = "NORMAL";

void readSensors() {
  int voltageRaw = analogRead(VOLTAGE_PIN);
  int currentRaw = analogRead(CURRENT_PIN);
  int freqRaw = analogRead(FREQ_PIN);
  lightValue = analogRead(PHOTO_PIN);

  voltage = map(voltageRaw, 0, 4095, 180, 260);
  current = map(currentRaw, 0, 4095, 0, 20);
  frequency = map(freqRaw, 0, 4095, 45, 55);
  temperature = dht.readTemperature();

  if (isnan(temperature)) temperature = 0;

  bool fault = false;
  status = "NORMAL";

  if (voltage > 245) {
    status = "OVERVOLTAGE";
    fault = true;
  } else if (voltage < 200) {
    status = "UNDERVOLTAGE";
    fault = true;
  } else if (current > 15) {
    status = "OVERLOAD";
    fault = true;
  } else if (frequency > 51) {
    status = "FREQUENCY FAULT";
    fault = true;
  } else if (temperature > 45) {
    status = "HIGH TEMPERATURE";
    fault = true;
  } else if (digitalRead(BUTTON_PIN) == LOW) {
    status = "EMERGENCY";
    fault = true;
  }

  digitalWrite(RED_LED, fault ? HIGH : LOW);
  digitalWrite(GREEN_LED, fault ? LOW : HIGH);
  digitalWrite(BUZZER_PIN, fault ? HIGH : LOW);
  digitalWrite(RELAY_PIN, fault ? LOW : HIGH);
}

void sendToBlynk() {
  readSensors();

  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, frequency);
  Blynk.virtualWrite(V3, temperature);
  Blynk.virtualWrite(V4, lightValue);
  Blynk.virtualWrite(V5, status);
}

void updateOLED() {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print("V:");
  display.print(voltage, 1);
  display.print(" I:");
  display.print(current, 1);

  display.setCursor(0, 12);
  display.print("F:");
  display.print(frequency, 1);
  display.print(" T:");
  display.print(temperature, 1);

  display.setCursor(0, 26);
  display.print("Light:");
  display.print(lightValue);

  display.setCursor(0, 40);
  display.print("Status:");

  display.setCursor(0, 52);
  display.print(status);

  display.display();
}

void printSerial() {
  Serial.println("-------------------------");
  Serial.print("Voltage: ");
  Serial.print(voltage, 1);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current, 1);
  Serial.println(" A");

  Serial.print("Frequency: ");
  Serial.print(frequency, 1);
  Serial.println(" Hz");

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.print("Light: ");
  Serial.println(lightValue);

  Serial.print("Status: ");
  Serial.println(status);
}

void handleRoot() {
  readSensors();

  String color = (status == "NORMAL") ? "#22c55e" : "#ef4444";

  String html = "";
  html += "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<meta http-equiv='refresh' content='2'>";
  html += "<title>Smart Grid Dashboard</title>";
  html += "<style>";
  html += "body{font-family:Arial;background:#0f172a;color:white;text-align:center;margin:0;padding:20px;}";
  html += "h1{color:#38bdf8;}";
  html += ".grid{display:flex;flex-wrap:wrap;justify-content:center;gap:15px;}";
  html += ".card{background:#1e293b;padding:20px;border-radius:15px;width:260px;box-shadow:0 0 10px #000;}";
  html += ".value{font-size:32px;color:#38bdf8;font-weight:bold;}";
  html += ".status{font-size:28px;font-weight:bold;color:" + color + ";}";
  html += "</style></head><body>";

  html += "<h1>IoT Smart Grid Monitoring</h1>";
  html += "<div class='grid'>";
  html += "<div class='card'><h2>Voltage</h2><div class='value'>" + String(voltage, 1) + " V</div></div>";
  html += "<div class='card'><h2>Current</h2><div class='value'>" + String(current, 1) + " A</div></div>";
  html += "<div class='card'><h2>Frequency</h2><div class='value'>" + String(frequency, 1) + " Hz</div></div>";
  html += "<div class='card'><h2>Temperature</h2><div class='value'>" + String(temperature, 1) + " C</div></div>";
  html += "<div class='card'><h2>Light</h2><div class='value'>" + String(lightValue) + "</div></div>";
  html += "<div class='card'><h2>Status</h2><div class='status'>" + status + "</div></div>";
  html += "</div>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  dht.begin();

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Smart Grid Starting");
  display.display();

  WiFi.mode(WIFI_STA);
  WiFi.begin("Wokwi-GUEST", "");

  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("Web Dashboard: http://");
  Serial.println(WiFi.localIP());

  Blynk.config(BLYNK_AUTH_TOKEN);

  if (Blynk.connect(10000)) {
    Serial.println("Blynk Connected");
  } else {
    Serial.println("Blynk Failed");
  }

  server.on("/", handleRoot);
  server.begin();

  timer.setInterval(2000L, sendToBlynk);

  Serial.println("Smart Grid System Started");
}

void loop() {
  if (Blynk.connected()) {
    Blynk.run();
  }

  timer.run();
  server.handleClient();

  readSensors();
  updateOLED();
  printSerial();

  delay(1000);
}