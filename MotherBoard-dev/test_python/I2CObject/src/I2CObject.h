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

#define CMD 0xAA

class I2CObject
{

    private:
        int *i2c_obj;
        const gchar *i2c_buffer;
	unsigned char addr;

    public:
	I2CObject (int *i2c_file,unsigned char address);
	~I2CObject (void);
	void test(void);
	void RegWrite(unsigned char cmd, unsigned int size, unsigned char *array);
        void RegRead(unsigned char cmd, unsigned int size, unsigned char *array);
	
};
