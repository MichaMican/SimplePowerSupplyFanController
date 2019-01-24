
#define THERMISTORPIN 0
#define BUZZERPIN 7
#define FANPIN 10

#define ALARMTHRESHOLD 45.0

#define R1 10000.0
#define C1 1.009249522e-03
#define C2 2.378405444e-04
#define C3 2.019202697e-07


float R2;
float T;
long startTime;
int pwmSteering = 0;

void setup() 
{
	pinMode(BUZZERPIN, OUTPUT);
	pinMode(FANPIN, OUTPUT);
	startTime = millis();
	Serial.begin(9600);
}

void loop() 
{
	R2 = R1 * (1023.0 / (float)analogRead(THERMISTORPIN) - 1.0);
	T = (1.0 / (C1 + C2*log(R2) + C3*log(R2)*log(R2)*log(R2)))- 273.15;

	Serial.print("Temperature: "); 
	Serial.print(T);
	Serial.println(" C");   

	if(T > ALARMTHRESHOLD)
	{
		beep();
	}
	else
	{
		digitalWrite(BUZZERPIN, LOW);
	}

	steerFan(T);
}

void beep()
{
	if((millis()-startTime) % 1000 < 500)
	{
		digitalWrite(BUZZERPIN, HIGH);
	}
	else
	{
		digitalWrite(BUZZERPIN, LOW);
	}
	
}

void steerFan(float temperature)
{
	pwmSteering = (int)(u(temperature - 25)*((165/10) * (temperature - 25)  + 90));
	if(pwmSteering > 255)
	{
		pwmSteering = 255;
	}
	analogWrite(FANPIN, pwmSteering);
	Serial.print("Steuerwert: ");
	Serial.println(pwmSteering);
}

float u(float x)
{
	if(x >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
