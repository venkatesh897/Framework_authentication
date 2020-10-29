
// C program to generate random numbers 
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 
#include<string.h>
  
int get_random_number();
int main(int argc, char  *argv[])
{ 
  int random_number = get_random_number();
  char command[200];
  int otp;
  char mobile_number[11];
  if(argv[1] == NULL)
  {
    printf("Enter mobile number: ");
    scanf("%s", mobile_number);
  }
  else
  {
  strcpy(mobile_number, argv[1]);
  }
  sprintf(command, "wget \"http://psms.goforsms.com/API/sms.php?username=srushtiimages&password=tecnics&from=WEBSMS&to=%s&msg=%d is your one time password.&type=1&dnd_check=0%22\" -q", mobile_number, random_number);
  system(command);
  printf("OTP has been sent to your registered mobile number.\n");
  printf("Enter your OTP: ");
  scanf("%d", &otp);
  if(random_number == otp)
  {
    sprintf(command, "framework.exe");
    system(command);
  }
  else
  {
    printf("Access not granted.\n");
  }
  return 0; 
} 

int get_random_number()
{
  srand(time(0)); 
  int random_number = rand();
  return random_number;
}