#include "MotorCape.h"

MotorCape::MotorCape(void)
{
    addr = 0x08;        // The I2C address of the ADC
    sprintf(i2c_filename,"/dev/i2c-2");
    if ((i2c_file = open(i2c_filename,O_RDWR)) < 0) 
    {
        printf("Failed to open the bus.");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

    if (ioctl(i2c_file,I2C_SLAVE,addr) < 0) 
    {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }
}

MotorCape::~MotorCape(void)
{


}


void MotorCape::test(void)
{
    char i,j;
    char motorSpeed[4] = {50, 50, 50, 50};
    for(i =0; i< 10; i++)
    {
        setMotorSpeed(motorSpeed);
        for(j = 0; j < 4;j++)
        {
            *(motorSpeed +j) += 5;
        }
        usleep(500000);
    }

}

void MotorCape::setMotorSpeed(char *motorSpeed)
{

    char buf[5] = {0};
    float data;
    char channel;
    char index = 0,i;
    //char *ptr = (char*)ir_buf;

    *(buf + 0) = CMD;
    for(i =1;i<5;i++)
    {
        *(buf + i) = *(motorSpeed + i - 1);
    }
    //Using I2C Read
    if (write(i2c_file,buf,5) != 5) 
    {
        /* ERROR HANDLING: i2c transaction failed */
        printf("Failed to read from the i2c bus.\n");
        printf("\n\n");
    } else {
      //  for(index = 0; index < 20; index++){
      //      *(ptr + index) = *(buf + index);
      //  }
    }

}
