#include <stdio.h>

//Determining initial values for variables used to display system peripherals state
char ret1='\0';
int speed=50;
float Actual_temp=35;
char AC_STATE=0;
float Engine_Actual=120;
char Engine_Temp_State=0;

//Function Prototypes
void ask(void);
void SystemState(char c);
void EngineOn(void);
void SetTrafficLightColor(void);
void AC(void);
void EngineControl(void);
void display(void);
void check(void);

int main(void){
	//to display required messages in its required time of display
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//function called to ask the user to choose from the main menu
	ask();


	/*when the user enters a value which is not equal to a or b or c
	the program will keep asking the user to enter a valid input,
	if it was a or b, corresponding statements will be executed
	if it was c then system will quit and nothing will happen*/

	while((ret1=='b' || ret1=='a') && ret1!='c'){
		//Turn off the engine
		//whie loop is chosen to remain in this loop until the value of ret1 is changed
		while(ret1=='b'){
			ask();
		}

		//Turn on the engine
		//whie loop is chosen to remain in this loop until the value of ret1 is changed
		while(ret1=='a'){
			EngineOn();//displays sensors set menu to choose from
		}
	}
}

//Function Definitions

void ask(void){

	char input;
	printf("a. Turn on the vehicle engine\nb. Turn off the vehicle engine\nc. Quit the system\n\n");
	scanf(" %c",&input);
	while(input!='a' && input!='b' && input!='c'){
		printf("INVALID INPUT!\nPlease Enter a Valid Input:\n\n");
		scanf(" %c",&input);
		}

	SystemState(input);

	ret1=input;
}

void SystemState(char c){
	if(c=='a'){
		printf("System State: Turn on the vehicle engine\n\n");
	}
	else if(c=='b'){
		printf("System State: Turn off the vehicle engine\n\n");
	}
	else if(c=='c'){
		printf("System State: Quit the system\n\n");
	}

}

void EngineOn(void){
	char input2;
	printf("a. Turn off the engine\nb. Set the traffic light color.\nc. Set the room temperature (Temperature Sensor)\nd. Set the engine temperature (Engine Temperature Sensor)\n\n");
	scanf(" %c",&input2);

	while(input2!='a' && input2!='b' && input2!='c' && input2!='d'){
		printf("INVALID INPUT!\nPlease Enter a Valid Input:\n\n");
		scanf(" %c",&input2);
	}

	if(input2=='a'){
		ret1='b';
	}
	else if(input2=='b'){
		SetTrafficLightColor();
		check(); //to check for requirement 7.d
		display(); //displaying current vehicle state
	}
	else if(input2=='c'){
		AC();
		check(); //to check for requirement 7.d
		display(); //displaying current vehicle state
	}
	else if(input2=='d'){
		EngineControl();
		check(); //to check for requirement 7.d
		display(); //displaying current vehicle state
	}

}
void SetTrafficLightColor(void){
	char Color;
	printf("Enter Traffic Light Color:\n");
	scanf(" %c",&Color);
	while(Color!='G' && Color!='O' && Color!='R' && Color!='g' && Color!='o' && Color!='r'){
		printf("INVALID INPUT!\nPlease Enter a Valid Input:\n\n");
		scanf(" %c",&Color);
		}
	if(Color=='G' || Color=='g'){
		speed=100;
	}
	else if(Color=='O' || Color=='o'){
		speed=30;
	}
	else if(Color=='R' || Color=='r'){
		speed=0;
	}
}


void AC(void){

	printf("Enter Actual Room Temp:\n");
	scanf(" %f",&Actual_temp);
	if(Actual_temp<10){
		AC_STATE=1;
		Actual_temp=20;
	}
	else if(Actual_temp>30){
		AC_STATE=1;
		Actual_temp=20;
	}
	else{
		AC_STATE=0;
	}
}
void EngineControl(void){

	printf("Enter Actual Engine Temp:\n");
	scanf(" %f",&Engine_Actual);

	if(Engine_Actual<100){
	Engine_Temp_State=1;
	Engine_Actual=125;
	}
	else if(Engine_Actual>150){
		Engine_Temp_State=1;
		Engine_Actual=125;
	}
	else{
		Engine_Temp_State=0;
	}

}
void display(void){
	printf("\nEngine is ON\n");
	if(AC_STATE==1){
		printf("AC is ON\n");
	}
	else{
		printf("AC is OFF\n");
	}

	printf("Vehicle Speed: %d Km/hr\n",speed);
	printf("Room Temperature: %f C\n",Actual_temp);

	if(Engine_Temp_State==1){
		printf("Engine Temp Controller is ON\n");
	}
	else{
		printf("Engine Temp Controller is OFF\n");
	}
	printf("Engine Temperature: %f\n\n",Engine_Actual);
}
void check(void){
	if(speed==30){
		AC_STATE=1;
		Actual_temp=((Actual_temp*5)/4)+1;
		Engine_Actual=((Engine_Actual*5)/4)+1;
		Engine_Temp_State=1;
	}
}
