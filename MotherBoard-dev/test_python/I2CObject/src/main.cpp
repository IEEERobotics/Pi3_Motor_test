#include <iostream>
using namespace std;

#include "I2CObject.h"



int main ()
{
   char i2c_filename[40]; 
   int i2c_file;
   unsigned char addr = 0x08;
   sprintf(i2c_filename,"/dev/i2c-2");
   if ((i2c_file = open(i2c_filename,O_RDWR)) < 0)
   {
        printf("Failed to open bus");
        addr = -1;
        exit(1);

   }
    I2CObject motor1(&i2c_file,addr);
    I2CObject motor2(&i2c_file,addr+1);
    motor1.test();
    //motor2.test();
    //MotherBoard Cape;
    //Cape.test();
    cout << "Hello World!\n";
    cout << "I'm a C++ program\n";
}
