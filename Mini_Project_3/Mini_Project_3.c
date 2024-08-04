/*
 ============================================================================
 Name        : Mini_Project_3.c
 Author      : Amr Essam
 Description : Fan Control system
 Date        : 10/10/2022
 ============================================================================
 */

#include"lcd.h"

#include"DC_Motor.h"

#include"lm35_sensor.h"

#include"ADC.h"

/*Configuring the ADC as internal reference voltage 2.56 voltage
 * and prescaler F_CPU/8*/
ADC_ConfigType config={INTERNAL,F_CPU_8};


int main(void){
	/*Initializing LCD, ADC and DC_Motor Drivers*/
	LCD_init();

	ADC_init(&config);

	DcMotor_init();
	/*Display "Fan IS {either on or off} and the current temperature
	 * according to the LM35 Sensor"*/
	LCD_moveCursor(0,3);
	LCD_displayString("FAN IS ");

	LCD_moveCursor(1,3);
	LCD_displayString("Temp =     C");

	/*Variable of uint8 to store the temperature value*/
	uint8 temp_value=0;

	/*Infinite loop*/
	while (1)
	{
		/*Get the temperature value from the LM35 Sensor*/
		temp_value = LM35_getTemperature();

		if(temp_value<30)
		{
			/*As the temperature is less than 30 degree stop the motor*/
			DcMotor_rotate(STOP,0);

			/*display the current temperature according to LM35 sensor*/
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp_value);

			/*display space as if shifting from three digits to two digits*/
			LCD_displayCharacter(' ');

			/*Display the motor status as it is OFF*/
			LCD_moveCursor(0,11);
			LCD_displayString("OFF");
		}
		else if((temp_value>=30) && (temp_value<60))
		{
			/* Turn on the DC motor in CW direction and with its quarter power */
			DcMotor_rotate(CW,25);

			/*display the current temperature according to LM35 sensor*/
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp_value);
			LCD_displayCharacter(' ');
			/*Display the motor status as it is ON*/
			LCD_moveCursor(0,11);
			LCD_displayString("ON");

			/*display space as if shifting from three digits to two characters*/
			LCD_displayCharacter(' ');
		}
		else if((temp_value>=60) && (temp_value<90))
		{
			/* Turn on the DC motor in CW direction and with its half power */
			DcMotor_rotate(CW,50);

			/*display the current temperature according to LM35 sensor*/
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp_value);
			LCD_displayCharacter(' ');
			/*Display the motor status as it is ON*/
			LCD_moveCursor(0,11);
			LCD_displayString("ON");

			/*display space as if shifting from three digits to two characters*/
			LCD_displayCharacter(' ');
		}
		else if((temp_value>=90) && (temp_value<120))
		{
			/* Turn on the DC motor in CW direction and with its three-quarters power */
			DcMotor_rotate(CW,75);

			/*display the current temperature according to LM35 sensor*/
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp_value);
			LCD_displayCharacter(' ');
			/*Display the motor status as it is ON*/
			LCD_moveCursor(0,11);
			LCD_displayString("ON");

			/*display space as if shifting from three digits to two characters*/
			LCD_displayCharacter(' ');
		}
		else if(temp_value>=120)
		{
			/* Turn on the DC motor in CW direction and with its full power */
			DcMotor_rotate(CW,100);

			/*display the current temperature according to LM35 sensor*/
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp_value);

			/*Display the motor status as it is ON*/
			LCD_moveCursor(0,11);
			LCD_displayString("ON");

			/*display space as if shifting from three digits to two characters*/
			LCD_displayCharacter(' ');
		}

	}



	return 0;
}
