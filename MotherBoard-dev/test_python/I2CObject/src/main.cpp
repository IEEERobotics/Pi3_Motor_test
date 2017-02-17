
#include <iostream>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//#include "I2CObject.h"
#include "pwm-chip.h"



int main(int argc, char **argv)
{
   char i2c_filename[40]; 
   int i2c_file;
   unsigned char addr = 0x08;
   signed char buf[4],i;
   
  // printf("%d\n%d\n%d\n%d\n",atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
   
  //buf[0] = atoi(argv[1]);
  //buf[1] = atoi(argv[2]);
 // buf[2] = atoi(argv[3]);
 // buf[3] = atoi(argv[4]);

//for(i = 0 ; i < 4 ; i++)
//{
//	printf("Motor%d :%d\n",i, buf[i]);
//}

    //printf("bus open");
   sprintf(i2c_filename,"/dev/i2c-1");
   if ((i2c_file = open(i2c_filename,O_RDWR)) < 0)
   {
        printf("Failed to open bus");
        addr = -1;
        exit(1);

   }
    printf("bus open");
    PWM pwm_chip();
    //I2CObject pwm(&i2c_file,addr);
    //pwm.RegWrite(0xaa,4,buf);
    //I2CObject motor2(&i2c_file,addr+1);
    //motor1. RegWrite(0xaa,4,buf);
    //motor1.test();
    //motor2.test();
    //MotherBoard Cape;
    //Cape.test();
    cout << "Hello World!\n";
    cout << "I'm a C++ program\n";

return 0;
}
