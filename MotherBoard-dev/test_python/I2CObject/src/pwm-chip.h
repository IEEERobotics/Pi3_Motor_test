
#include "glib.h"
#include <glib/gprintf.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include "I2CObject.h"

#define CMD 0xAA

class PWM
{

    private:
        int i2c_file;
        unsigned char address;
        I2CObject *pca_9685;
    public:
	PWM ();
	~PWM (void);
        void set_freq(unsigned char ch, unsigned char freq_hz);
        unsigned int get_freq(unsigned char ch);
        void enable_ch(unsigned char ch);
        void disable_ch(unsigned char ch);
        void write(unsigned char ch);
        unsigned int read(unsigned char ch);
        void read(unsigned int * period_us, unsigned char len);
	void update(void);
	
};
