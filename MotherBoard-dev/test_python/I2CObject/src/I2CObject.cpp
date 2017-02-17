#include "I2CObject.h"


I2CObject::I2CObject (int *i2c_file,unsigned char address)
{
    i2c_obj = i2c_file;
    addr = address;
}

I2CObject::~I2CObject (void)
{

}

void I2CObject::test(void)
{
    signed char array[50] = "hello from the beaglebone",i;
    unsigned int size = 4;
    char cmd = 0xaa;
    //size = sprintf((char*)array,"Hi from the beaglebone\n");
    
    for(i =0;i<4;i++)
    {
	array[i] = 100;
    }	
   RegWrite(cmd,size,array);
   printf("Set motors to %d\n",array[0]); 	    

//RegRead(cmd,50,array);


}

void I2CObject::RegWrite(char cmd, unsigned int size,signed char *array) 
{
#if 0
    char buf[size + 1];
    unsigned char i;

    if(ioctl(*i2c_obj,I2C_SLAVE,addr) < 0)
    {
        printf("Failed to acquire bus access and/of talk to slave.\n");
        exit(1);
    }
    *(buf + 0) = cmd;
    for(i = 0; i < size;i++)
    {
        *(buf + i + 1) = *(array + i);
    }
    if(write(*i2c_obj,buf,size+1) != (size+1))
    {
        printf("Failed to write to i2c object\n");
    }
#else
    unsigned char buf[size + 1],i;
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[1];
    *buf = cmd;
    for(i = 0; i < size;i++)
    {
        *(buf + i + 1) = *(array + i);
    }

    messages[0].addr  = addr;
    messages[0].flags = 0;
    messages[0].len   = size+1;
    messages[0].buf   =  (__u8*) buf;

    /* The first byte indicates which register we'll write */

    /* 
    *      * The second byte indicates the value to write.  Note that for many
    *           * devices, we can write multiple, sequential registers at once by
    *                * simply making outbuf bigger.
    *                     */

    /* Transfer the i2c packets to the kernel and verify it worked */
    packets.msgs  = messages;
    packets.nmsgs = 1;
    if(ioctl(*i2c_obj, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
    }


#endif
}

void I2CObject::RegRead(char cmd, unsigned int size, char *array)
{
#if 0
    struct i2c_rdwr_ioctl_data msgs;
    struct i2c_msg write_msg;
    struct i2c_msg read_msg;
    write_msg.addr = addr;
    write_msg.len = 1;
    write_msg.buf = &cmd;
    struct i2c_msg msg[2];
    msg[0].addr = addr;
    msg[1].addr = addr;
    msg[0].len = 1;
    msg[1].len = size;
    msg[0].buf = &cmd;
    msg[1].buf = array;
    msg[0].flags = 0;
    msg[1].flags = I2C_M_RD;
    msgs.msgs = msg;
    msgs.nmsgs = 2;


    if(ioctl(*i2c_obj, I2C_RDWR, &msgs) < 0)
    {
        printf("help\n");
    
    }
#else
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];

    /*
    *      * In order to read a register, we first do a "dummy write" by writing
    *           * 0 bytes to the register we want to read from.  This is similar to
    *                * the packet in set_i2c_register, except it's 1 byte rather than 2.
    *                     */
    messages[0].addr  = addr;
    messages[0].flags = 0;
    messages[0].len   = 1;
    messages[0].buf   = (__u8*) &cmd;

    /* The data will get returned in this structure */
    messages[1].addr  = addr;
    messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
    messages[1].len   = size;
    messages[1].buf   = (__u8*) array;

    /* Send the request to the kernel and get the result back */
    packets.msgs      = messages;
    packets.nmsgs     = 2;
    if(ioctl(*i2c_obj, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
    }
#endif
}
