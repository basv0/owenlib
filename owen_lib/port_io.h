/***************************************************************************
 *   Copyright (C) 2015 by basv0                                           *
 *   basv0@.mail.ru                                                        *
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

#ifndef _PORTIO_H
#define _PORTIO_H

const int AMOUNT_TO_READ = 56;
//const int TIME_TO_WAIT = 175000;
//enum  SPD {S19200=19200, S9600=9600, S4800=4800, S2400=2400, S1200=1200, S0=0};

//enum  PORT {COM1=1, COM2=2, COM3=3, COM4=4};
/*
struct port_descr{
   PORT num;
   short base;
   int fd;
   char nam[16];
   SPD spd;
};
*/
int qry_n_ans(int fd, char* qry, char* ans);
int snd_str(int fd, char* qry);
/*
int assign_port(int n, port_descr pd);
int init_ports(int np);
void get_ports(port_descr** pd, int* Nm);
*/
#endif
