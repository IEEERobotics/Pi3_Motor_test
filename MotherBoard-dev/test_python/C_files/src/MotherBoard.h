#include "glib.h"
#include <glib/gprintf.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#define CMD 0xAA

class MotherBoard
{

    private:
        int i2c_file;
        char i2c_filename[40];
        const gchar *i2c_buffer;
	int addr;

    public:
	MotherBoard (void);
	~MotherBoard (void);
	void test(void);
	void setMotorSpeed(char *motorSpeed);
	
};
