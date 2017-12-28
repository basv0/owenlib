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
#include <string.h>

void rev(char* srs, char* dst, int L)
{
    dst[L]=0;
    for(int j=0; j<L; j++)dst[L-j-1]=srs[j];
}

bool isalpha(char b)
{
    char c = (char) b;
    return ('A'<=c)&&(c<='Z');
}

bool isdigit(char b)
{
    char c = (char) b;
    return ('0'<=c)&&(c<='9');
}

char toupp(char c)
{
    if((c>='a')&&(c<='z')) c-=32;
    return c;
}

char* toUpperCase(char* srs, char* dst)
{
    char *ps, *ds;
    ps = srs;
    ds = dst;
    while(*ps)
    {
        *ds=*ps;
        if((*ds >= 'a')&&(*ds <= 'z')) *ds-=32;
        ps++;
        ds++;
    }
    return dst;
}

int hash(char Byte, int nbit, int CRC)
{
    for (int i = 0; i < nbit; i++, Byte <<= 1)
    {
        if ( ( ( Byte ^ (char)(CRC >> 8) ) & 0x80) != 0 )
        {
            CRC <<= 1;
            CRC ^= 0x8F57;
        }
        else
        {
            CRC <<= 1;
        }
        CRC &= 0xFFFF;
    }
    return CRC;
}

int hash_buffer(char s[], int length, int CRC)
{
    int counter = 0;
    while (counter < length)
    {
        CRC = hash(s[counter], 8, CRC);
        counter++;
    }
    return CRC;
}

int hashs(char* Command0)
{
    char Command[8];
    toUpperCase(Command0, Command);
    if(strlen(Command) <=0) return 0;

    /*        String Command = Command0.toUpperCase();
    	    if (Command.length()<=0) return 0;*/

    char par[] = { 78, 78, 78, 78, 0, 0 };  // 6
    char parname[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 9

    strncpy((char*)parname, Command, 8);

    int strln = strlen((char*)parname);
    /*        for (strlen=0; (strlen<8) && (strlen < Command.length()); strlen++) {
                parname[strlen]=(char) Command.charAt(strlen);
            }*/

    // strupr(parname); // +++

    for (int i=0, j=0; (i<strln) && (j<=4); i++)
    {
        if ((parname[i]=='.')&&(i>0)) par[j-1]++;
        else if (parname[i]==' ') par[j++]=78;
        else if (parname[i]=='_') par[j++]=74;
        else if (parname[i]=='-') par[j++]=72;
        else if (isalpha(parname[i])) par[j++]=(char) (2*(parname[i]-((char) 'A')+(char) 10));
        else if (isdigit(parname[i])) par[j++]=(char) (2*(parname[i]-((char) '0')));
    }

    return
        hash((char) (par[3] << 1), 7,
             hash((char) (par[2] << 1), 7,
                  hash((char) (par[1] << 1), 7,
                       hash((char) (par[0] << 1), 7, 0))));
}

char* encode_buffer(char in_buffer[], int length, char out_buffer[])
{
    // int length = in_buffer.length;
//        char[] out_buffer = new char[length*2+2];
    out_buffer[0]=(char) '#';       // the first
    out_buffer[length*2+1] = 0xD;   // the last
    out_buffer[length*2+2] = 0x0;
    int temp;
    int counter = 0;

    while (counter < length)
    {
        temp = (in_buffer[counter] & 0xF0) >> 4;
        switch (temp)
        {
        case 0:
            out_buffer[counter*2+1] = 'G';
            break;
        case 1:
            out_buffer[counter*2+1] = 'H';
            break;
        case 2:
            out_buffer[counter*2+1] = 'I';
            break;
        case 3:
            out_buffer[counter*2+1] = 'J';
            break;
        case 4:
            out_buffer[counter*2+1] = 'K';
            break;
        case 5:
            out_buffer[counter*2+1] = 'L';
            break;
        case 6:
            out_buffer[counter*2+1] = 'M';
            break;
        case 7:
            out_buffer[counter*2+1] = 'N';
            break;
        case 8:
            out_buffer[counter*2+1] = 'O';
            break;
        case 9:
            out_buffer[counter*2+1] = 'P';
            break;
        case 10:
            out_buffer[counter*2+1] = 'Q';
            break;
        case 11:
            out_buffer[counter*2+1] = 'R';
            break;
        case 12:
            out_buffer[counter*2+1] = 'S';
            break;
        case 13:
            out_buffer[counter*2+1] = 'T';
            break;
        case 14:
            out_buffer[counter*2+1] = 'U';
            break;
        case 15:
            out_buffer[counter*2+1] = 'V';
            break;
        }
        temp = in_buffer[counter] & 0x0F;
        switch (temp)
        {
        case 0:
            out_buffer[counter*2+2] = 'G';
            break;
        case 1:
            out_buffer[counter*2+2] = 'H';
            break;
        case 2:
            out_buffer[counter*2+2] = 'I';
            break;
        case 3:
            out_buffer[counter*2+2] = 'J';
            break;
        case 4:
            out_buffer[counter*2+2] = 'K';
            break;
        case 5:
            out_buffer[counter*2+2] = 'L';
            break;
        case 6:
            out_buffer[counter*2+2] = 'M';
            break;
        case 7:
            out_buffer[counter*2+2] = 'N';
            break;
        case 8:
            out_buffer[counter*2+2] = 'O';
            break;
        case 9:
            out_buffer[counter*2+2] = 'P';
            break;
        case 10:
            out_buffer[counter*2+2] = 'Q';
            break;
        case 11:
            out_buffer[counter*2+2] = 'R';
            break;
        case 12:
            out_buffer[counter*2+2] = 'S';
            break;
        case 13:
            out_buffer[counter*2+2] = 'T';
            break;
        case 14:
            out_buffer[counter*2+2] = 'U';
            break;
        case 15:
            out_buffer[counter*2+2] = 'V';
            break;
        }

        counter++;
    }

    return out_buffer;
}


char* decode_buffer(char in_buffer[], char out_buffer[])
{
    if (in_buffer[0]!=(char)'#')
    {
        out_buffer[0]=0;
        return out_buffer;
    }
    int length=strlen((char*)in_buffer);
    if (length<=0)
    {
        out_buffer[0]=0;
        return out_buffer;
    }

    int size = (length+1)/2;

    char temp;
    int counter = 0;
    while (counter < length)
    {
        temp = (char) in_buffer[counter+1];

        switch (temp)
        {
        case 'G':
            out_buffer[counter/2] = 0x00;
            break;
        case 'H':
            out_buffer[counter/2] = 0x10;
            break;
        case 'I':
            out_buffer[counter/2] = 0x20;
            break;
        case 'J':
            out_buffer[counter/2] = 0x30;
            break;
        case 'K':
            out_buffer[counter/2] = 0x40;
            break;
        case 'L':
            out_buffer[counter/2] = 0x50;
            break;
        case 'M':
            out_buffer[counter/2] = 0x60;
            break;
        case 'N':
            out_buffer[counter/2] = 0x70;
            break;
        case 'O':
            out_buffer[counter/2] = (char) 0x80;
            break;
        case 'P':
            out_buffer[counter/2] = (char) 0x90;
            break;
        case 'Q':
            out_buffer[counter/2] = (char) 0xA0;
            break;
        case 'R':
            out_buffer[counter/2] = (char) 0xB0;
            break;
        case 'S':
            out_buffer[counter/2] = (char) 0xC0;
            break;
        case 'T':
            out_buffer[counter/2] = (char) 0xD0;
            break;
        case 'U':
            out_buffer[counter/2] = (char) 0xE0;
            break;
        case 'V':
            out_buffer[counter/2] = (char) 0xF0;
            break;
        }
        counter++;
        if (counter == length) break;

        temp = (char) in_buffer[counter+1];

        switch (temp)
        {
        case 'G':
            out_buffer[counter/2] |= 0;
            break;
        case 'H':
            out_buffer[counter/2] |= 1;
            break;
        case 'I':
            out_buffer[counter/2] |= 2;
            break;
        case 'J':
            out_buffer[counter/2] |= 3;
            break;
        case 'K':
            out_buffer[counter/2] |= 4;
            break;
        case 'L':
            out_buffer[counter/2] |= 5;
            break;
        case 'M':
            out_buffer[counter/2] |= 6;
            break;
        case 'N':
            out_buffer[counter/2] |= 7;
            break;
        case 'O':
            out_buffer[counter/2] |= 8;
            break;
        case 'P':
            out_buffer[counter/2] |= 9;
            break;
        case 'Q':
            out_buffer[counter/2] |= 10;
            break;
        case 'R':
            out_buffer[counter/2] |= 11;
            break;
        case 'S':
            out_buffer[counter/2] |= 12;
            break;
        case 'T':
            out_buffer[counter/2] |= 13;
            break;
        case 'U':
            out_buffer[counter/2] |= 14;
            break;
        case 'V':
            out_buffer[counter/2] |= 15;
            break;
        }
        counter++;
    }
    out_buffer[size]=0;
    return out_buffer;
}
