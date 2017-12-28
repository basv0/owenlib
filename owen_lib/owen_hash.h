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
#ifndef _OWENHASH_H
#define _OWENHASH_H

void rev(char* srs, char* dst, int L);
int hash_buffer(char s[], int length, int CRC);
int hashs(char* Command0);
char* encode_buffer(char in_buffer[], int length, char out_buffer[]);
char* decode_buffer(char in_buffer[], char out_buffer[]);

#endif
