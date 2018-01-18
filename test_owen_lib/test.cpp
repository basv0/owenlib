#include <stdio.h>
#include </usr/local/include/owen/owen_io.h>

int main(){
    float val;
    char nam[]="/dev/ttyS0";
    int fd=open_port(nam, B9600);
    int r=read_data(fd,16,0,&val,3);
    printf("port %d res %d\n",fd,r);
    char nam1[]="/dev/ttyS4";
    int fd1=open_port(nam1, B9600);
    int r1=read_data(fd,16,0,&val,3);
    printf("port %d res %d\n",fd1,r1);
    return 0;
}
