#include "pwm-chip.h"

#define PWM_CHAN_COUNT                  8
#define PCA9685_I2C_BUS                 1
#define PCA9685_I2C_ADDR                0x40
#define PCA9685_I2C_MODE1               0x00
#define PCA9685_I2C_MODE2               0x01
#define PCA9685_I2C_PWM_CH_1            0x06
#define PCA9685_I2C_BASE_ADDRESS        B1000000



PWM::PWM (){

   char i2c_filename[40]; 
   unsigned char addr = 0x08;
   signed char buf[4],i;
   
   sprintf(i2c_filename,"/dev/i2c-1");
   if ((i2c_file = open(i2c_filename,O_RDWR)) < 0)
   {
        printf("Failed to open bus");
        addr = -1;
        exit(1);

   }
   printf("bus open");
   pca_9685 = new I2CObject(&i2c_file,PCA9685_I2C_ADDR);
   buf[0] = 0x01;
   pac_9685.RegWrite(PCA9685_I2C_MODE1,1,buf);
   bool isOnline;
   if(pca_9685.RegRead
   


}

PWM::~PWM (void){




}

void PWM::set_freq(unsigned char ch, unsigned char freq_hz){





}

unsigned int PWM::get_freq(unsigned char ch){



}

void PWM::enable_ch(unsigned char ch){



}

void PWM::disable_ch(unsigned char ch){


}

void PWM::write(unsigned char ch){




}

unsigned int PWM::read(unsigned char ch){




}

void PWM::read(unsigned int * period_us, unsigned char len){



}

void PWM::update(void){



}
