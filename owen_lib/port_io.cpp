/***************************************************************************
 *   Copyright (C) 2007 by basil   *
 *   root@kdev   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <sys/io.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <fcntl.h>   /* File control definitions */
#include <sys/stat.h>
#include <sys/types.h>
#include "port_io.h"

int N=0;

/*static port_descr ports[4]={{COM1,0x3f8,-1,"/dev/ttyS0",S0},
                           {COM2,0x2f8,-1,"/dev/ttyS1",S0},
                           {COM3,0xc000,-1,"/dev/ttyS2",S0},
                           {COM4,0xc400,-1,"/dev/ttyS3",S0}};*/
/*
port_descr *ports;

void get_ports(port_descr** pd, int* Nm){
    *pd=ports;
    *Nm=N;
}

int init_ports(int np){
    if(np>0){
        N=np;
        ports = new port_descr[N];
        return !ports;
    }
    return 1;
}

int assign_port(int n, port_descr pd){
    char er[80];
    if(n>=N) return 1;
    ports[n]=pd;
    ports[n].fd = open(ports[n].nam, O_RDWR | O_NOCTTY | O_NDELAY);
    if(ports[n].fd == -1){
        strcpy(er,"open_port: Unable to open ");
        strcat(er,ports[n].nam);
        perror(er);
        fprintf(stderr,"%d\n",n);
        return 1;
    }
    fcntl(ports[n].fd, F_SETFL, 0);
    termios options;
    tcgetattr(ports[n].fd, &options);
    switch(ports[n].spd){
         case S19200:
            cfsetispeed(&options, B19200);
         break;
         case S9600:
            cfsetispeed(&options, B9600);
         break;
         case S4800:
            cfsetispeed(&options, B4800);
         break;
         case S2400:
            cfsetispeed(&options, B2400);
         break;
         case S1200:
            cfsetispeed(&options, B1200);
         break;
         case S0:
            cfsetispeed(&options, B9600);
         break;
    }

    options.c_cflag &= ~CSIZE;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CS8;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_cflag |= (CLOCAL | CREAD);

    options.c_cc[VMIN]=0;
    options.c_cc[VTIME]=1; //задержка при чтении 1/10 сек
    tcsetattr(ports[n].fd, TCSANOW, &options);

    return 0;
}
*/

int open_port(const char* port_name, speed_t speed){
    int fd;
    fd = open(port_name, O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd==-1) return fd;
    fcntl(fd, F_SETFL, 0);
    termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, speed);
    options.c_cflag &= ~CSIZE;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CS8;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_cflag |= (CLOCAL | CREAD);

    options.c_cc[VMIN]=0;
    options.c_cc[VTIME]=1; //задержка при чтении 1/10 сек
    tcsetattr(fd, TCSANOW, &options);
    return fd;
}

int close_port(int fd)
{
    return close(fd);   
}

int port_set_speed(int fd, speed_t speed)
{
    termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, speed);
    tcsetattr(fd, TCSANOW, &options);
    return 0;
}

int snd_str(int fd, char* qry)
{
    int Lq=strlen(qry);
    char ans[24];

    write(fd,qry,Lq);

    char c='q';
    int k=0;
    int m;
    do
    {
        m=read(fd,&c,1);
        if(m==0) return -10;
        ans[k++]=c;
    }
    while((c!=0x0D)&&(c!=0x0A)&&(k<=AMOUNT_TO_READ));
    ans[k]=0;
    if(k>AMOUNT_TO_READ)
    {
        return -1*k;
    }
    return 0;
}

int qry_n_ans(int fd, char* qry, char* ans)
{
//	если ОК, то возвращает 0
//	если не дождался ответа, то 1
//	другое число - это длина ответа, большая макс.длины
    int Lq=strlen(qry);

    write(fd,qry,Lq);

    char c='q';
    int k=0;
    int m;
    do
    {
        m=read(fd,&c,1);
        if(m==0) return -10;
        ans[k++]=c;
    }
    while((c!=0x0D)&&(c!=0x0A)&&(k<=AMOUNT_TO_READ));
    ans[k]=0;
    if(k>AMOUNT_TO_READ)
    {
        return -1*k;
    }
    return 0;
}
