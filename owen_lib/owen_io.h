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

// tip
// 0 - конец работы
// 1 - чтение read
// 2 - чтение set.P
// 3 - чтение SP.LU
// 4 - чтение dev, ver  и т.д.
// 5 - запись SP.LU
// 6 - чтение PV для ТРМ202
// 7 - чтение SP для ТРМ202
// 8 - запись SP для ТРМ202
// 9 - запись r.oe для MVA8
// 10 - запись init для MVA8
// 11 - запись для MVA8 по протоколу DCON
// 12 - запись периода ШИМ
// 13 - запись вида управления 0/1 уставка/мощность
// 14 - запись скважности ШИМ для прямого управления мощностью

#ifndef _OWENIO_H
#define _OWENIO_H
#include <termios.h>

//	если ОК, то возвращает 0
//	если не дождался ответа, то 1
//	если не совпадает CRC, то -1
//	другое число - это длина ответа, большая макс.длины

int read_data(int df, int adr, int sns, float* val, int Ntry); //1
int read_str(int df, int adr, char* nam, char* res, int Ntry);
int read_ust(int df, int adr, int chn, float* val, int Ntry); //2
int read_val(int df, int adr, int idx, float* val, int Ntry); //3
int write_val(int df, int adr, int idx, float val, int Ntry); //5
int read_pv(int df, int adr, int idx, float *val, int Ntry); //6
int read_sp(int df, int adr, int idx, float *val, int Ntry); //7
int write_sp(int df, int adr, int idx, float val, int Ntry); //8
int write_oe(int df, int adr, int idx, float val, int Ntry); //9
int write_ini(int df, int adr, int idx, float val, int Ntry); //10
int write_dcon(int df, int adr, int idx, float val, int Ntry); //11
int write_shim(int df, int adr, int idx, float val, int Ntry); //12
int write_mosch(int df, int adr, int idx, float val, int Ntry); //13
int write_skv(int df, int adr, int idx, float val, int Ntry); //14

int open_port(const char* port_name, speed_t speed);
int close_port(int fd);
int port_set_speed(int fd, speed_t speed);

#endif

/*#include <termios.h>
        speed_t
            B0
            B50
            B75
            B110
            B134
            B150
            B200
            B300
            B600
            B1200
            B1800
            B2400
            B4800
            B9600
            B19200
            B38400
            B57600
            B115200
            B230400
*/
