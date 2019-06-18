#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

const unsigned int ENA = 12;
const unsigned int IN1 = 13;
const unsigned int IN2 = 14;
const unsigned int IN3 = 21;
const unsigned int IN4 = 22;
const unsigned int ENB = 23;

int main (void){
	char input = 's';

	wiringPiSetup();
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

	int speed = 50;
	softPwmCreate(ENA, 0, 100);
	softPwmCreate(ENB, 0, 100);
	
	while(input != 'q') {
		input = getchar();

		if(input == 'p'){
			if(speed < 100) speed += 10;
			printf("Setting speed to %d\n", speed);
		}

		if(input == 'o'){
			if(speed > 0) speed -= 10;
			printf("Setting speed to %d\n", speed);
		}

		if(input == 'z') {
			//back
			digitalWrite(IN1, HIGH);
			digitalWrite(IN2,  LOW);
			digitalWrite(IN3, HIGH);
			digitalWrite(IN4,  LOW);
			softPwmWrite(ENA, speed/2);
			softPwmWrite(ENB, speed/2);
			delay(10);
			softPwmWrite(ENA, speed);
			softPwmWrite(ENB, speed);
			delay(300);
		}

		if(input == 'w') {
			//forward
			digitalWrite(IN1,  LOW);
			digitalWrite(IN2, HIGH);
			digitalWrite(IN3,  LOW);
			digitalWrite(IN4, HIGH);
			softPwmWrite(ENA, speed/2);
			softPwmWrite(ENB, speed/2);
			delay(10);
			softPwmWrite(ENA, speed);
			softPwmWrite(ENB, speed);
			delay(300);
		}
			
		if(input == 'a') { 	
			//left
			digitalWrite(IN1, HIGH);
			digitalWrite(IN2,  LOW);
			digitalWrite(IN3,  LOW);
			digitalWrite(IN4, HIGH);
			softPwmWrite(ENA, speed/2);
			softPwmWrite(ENB, speed/2);
			delay(10);
			softPwmWrite(ENA, speed);
			softPwmWrite(ENB, speed);
			delay(30);
		}
	
		if(input == 'd') {
			//right
			digitalWrite(IN1,  LOW);
			digitalWrite(IN2, HIGH);
			digitalWrite(IN3, HIGH);
			digitalWrite(IN4,  LOW);
			softPwmWrite(ENA, speed/2);
			softPwmWrite(ENB, speed/2);
			delay(10);
			softPwmWrite(ENA, speed);
			softPwmWrite(ENB, speed);
			delay(30);
		}

		//stop
		softPwmWrite(ENA, 0);
		softPwmWrite(ENA, 0);
		digitalWrite(IN1,  LOW);
		digitalWrite(IN2,  LOW);
		digitalWrite(IN3,  LOW);
		digitalWrite(IN4,  LOW);
	}
	return 0;
}
