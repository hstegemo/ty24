#include <avr/pgmspace.h>

const prog_char message1[] PROGMEM = "This is a short message";
const prog_char message2[] PROGMEM = "This is a little longer message";
const prog_char message3[] PROGMEM = "Test message 3";
const prog_char message4[] PROGMEM = "This is the last message in the test";

const char* const table[] PROGMEM = {message1, message2, message3, message4};

void setup() {
	Serial.begin(9600);
	char buffer[50];
	int size;
	for(int i = 0; i < 4; i++) {
		size = strlen_P((char *)pgm_read_word(&(table[i])));
		strcpy_P(buffer, (char *)pgm_read_word(&(table[i])));
		Serial.print("The size of the string is: ");
		Serial.print(size);
		Serial.print(": ");
		Serial.println(buffer);
	}
}

void loop() {
}

