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
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "owen_hash.h"
#include "port_io.h"

#define prep \
	*val=-1.0;\
        chsh = hashs(cmd);\
        ssy[0]=(char)(addr);\
        ssy[1]=(char)(0x10 | 0x00);\
        ssy[2]=(char)(chsh >> 8);\
        ssy[3]=(char)(chsh & 0xFF);\
        CRC=0;\
        CRC = hash_buffer(ssy,4,0);\
        ssy[4]=(char)(CRC >> 8);\
        ssy[5]=(char)(CRC & 0xFF);\
        encode_buffer(ssy,6,ssx);\
	int cnt=0;\
	int res=1;\
	while(res){\
		res=qry_n_ans(df, ssx, ans);\
		if(cnt++ >= Ntry) return res;\
	}\
        int blen=(strlen((char*)ans)-2)/2;\
        decode_buffer(ans,ssy);\
	if(!ssy[0]) return -4; \
        int data_size = ssy[1] & 0x0F;\
        unsigned short CRCSumma2;\
        char *px= (char*)&CRCSumma2;\
        px[0]=ssy[data_size+5];\
        px[1]=ssy[data_size+4];\
        int CRCSumma3 = hash_buffer(ssy, blen-2, 0);\
	if(CRCSumma3 - CRCSumma2) return -1;

#define gotcha\
	float rez;\
	char* rs = (char*)&rez;\
	 for(int i=4; i>0; i--){\
		*rs=ssy[3+i];\
		rs++;\
	}\
	*val=rez;
int write_val(int df, int adr, int idx, float val, int Ntry)
{
    int addr = adr;
    char cmd[] = "SP.LU";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;

    int iust = int(val*10.0+0.5);

    L=5;
    nam[0]=0x10;
    nam[1]=(char)(iust >> 8);
    nam[2]=(char)iust;
    nam[3]=0;
    nam[4]=idx;               // индекс

    chsh = hashs(cmd);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x00 | (L & 0x0F); //запись
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);

    int cnt=0;
    int res=1;
    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }

    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    return 0;
}

int read_val(int df, int adr, int idx, float* val, int Ntry)
{
    int addr = adr;
    char cmd[] = "SP.LU";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    L=2;
    nam[0]=0;
    nam[1]=idx;

    *val=-1.0;
    chsh = hashs(cmd);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x10 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    int s=(ssy[4] & 0x80);
    int d= (ssy[4]>>4) & 0x0F;
    int sz=data_size-2-1;
    int m = (ssy[4] & 0x0F);
    if(sz>7) return -3;
    for(int k=0; k<sz; k++)
    {
        m = m << 8;
        m += (unsigned char)ssy[k+4+1];
    }
    float rs=m;
    for(int j=0; j<d; j++) rs /=10.0;
    if(s) rs *=-1.0;
    *val=rs;
    return 0;
}

int read_data(int df, int adr, int sns, float* val, int Ntry)
{
    int addr = adr+sns;
    char cmd[] = "READ";
    char ans[80];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;

    prep

    gotcha

    return 0;
}

int read_ust(int df, int adr, int chn, float* val, int Ntry)
{
    int addr = adr+chn;
    char cmd[] = "set.P";
    char ans[80];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;

    prep

    gotcha
    return 0;
}

int read_pv(int df, int adr, int idx, float* val, int Ntry)
{
    int addr = adr;
    char cmd[] = "PV  ";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    L=0;

    *val=-1.0;
    chsh = hashs(cmd);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x10 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;



    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    float rez;
    ssy[7]=0;
    char* rs = (char*)&rez;
    for(int i=4; i>0; i--)
    {
        *rs=ssy[3+i];
        rs++;
    }
    *val=rez;
    return 0;
}

int read_sp(int df, int adr, int idx, float* val, int Ntry)
{
    int addr = adr;
    char cmd[] = "SP  ";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    L=2;
    nam[0]=0;
    nam[1]=idx;

    *val=-1.0;
    chsh = hashs(cmd);
//fprintf(stderr,"chsh %s %d\n",cmd,chsh);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x10 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
//fprintf(stderr,"CRC %s %d\n",ssy,CRC);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
//fprintf(stderr,"encode %s %s\n",ssy,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
//fprintf(stderr,"try %d %d\n",res,cnt);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;
//fprintf(stderr,"answer %s %d\n",ans,blen);

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;
//fprintf(stderr,"decode %s %s %d\n",ans,ssy,data_size);


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);
//fprintf(stderr,"CRC %d %d\n",CRCSumma2,CRCSumma3);

    if(CRCSumma3 - CRCSumma2) return -1;

    float rez;
    ssy[7]=0;
    char* rs = (char*)&rez;
    for(int i=4; i>0; i--)
    {
        *rs=ssy[3+i];
        rs++;
    }
    *val=rez;
//fprintf(stderr,"val %f\n",res);
    return 0;
}

int write_sp(int df, int adr, int idx, float val, int Ntry)
{
    int addr = adr;
    char cmd[] = "SP  ";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    L=5;
    char* ptx;
    ptx = (char*)&val;
    nam[0]=ptx[3];
    nam[1]=ptx[2];
    nam[2]=ptx[1];
    nam[3]=0;
    nam[4]=idx;

    chsh = hashs(cmd);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x00 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    return 0;
}

int write_oe(int df, int adr, int idx, float val, int Ntry)
{
    int addr = adr;
    char cmd[] = "R.OE ";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    char* ptx;
    ptx = (char*)&val;

    L=3;
    nam[0]=ptx[3];
    nam[1]=ptx[2];
    nam[2]=ptx[1];

    chsh = hashs(cmd);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x00 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    return 0;
}

int write_ini(int df, int adr, int idx, float val, int Ntry)
{
    int addr = adr;
    char cmd[] = "INIT";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    char* ptx;
    ptx = (char*)&val;

    L=0;

    chsh = hashs(cmd);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x00 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    return 0;
}

int write_dcon(int df, int adr, int idx, float val, int Ntry)
{
    int i,k;
//        char c;
    unsigned char cc;
    unsigned CRC;
    char ssx[24], ssy[8];
    strcpy(ssx,"#");
    sprintf(ssy,"%02X",adr);
    strcat(ssx,ssy);
    sprintf(ssy,"%X",idx);
    strcat(ssx,ssy);
    sprintf(ssy,"%5.1f",val);
    strcat(ssx,ssy);
    cc=0;
    CRC=0;
    i=strlen(ssx);
    for(k=0; k<i; k++) CRC+=ssx[k];
    cc = CRC % 256;
    sprintf(ssy,"%X",cc);
    ssx[i]=ssy[0];
    ssx[i+1]=ssy[1];
    ssx[i+2]='\r';
    ssx[i+3]=0;
    int res = 0;
    int cnt = 0;
    while(res)
    {
        res=snd_str(df, ssx);
        if(cnt++ >= Ntry) return res;
    }
    snd_str(df, ssx);
    return res;
}

int write_shim(int df, int adr, int idx, float val, int Ntry)
{
    int addr = adr;
    char cmd[] = "tHP ";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    char* ptx;

    short vl=(short)val;

    ptx = (char*)&vl;

    L=3;
    nam[0]=ptx[0];
    nam[1]=0;
    nam[2]=idx;

    chsh = hashs(cmd);

    ssy[0]=(char)(addr);
    ssy[1]=(char)0x00 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    return 0;
}

int write_mosch(int df, int adr, int idx, float val, int Ntry)
{
    int addr = adr;
    char cmd[] = "P.-SP";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;
    char* ptx;

    short vl=(short)val;

    ptx = (char*)&vl;

    L=3;
    nam[0]=ptx[0];
    nam[1]=0;
    nam[2]=idx;

    chsh = hashs(cmd);

    ssy[0]=(char)(addr);
    ssy[1]=(char)0x00 | (L & 0x0F);
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);
    int cnt=0;
    int res=1;

    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }


    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    return 0;
}

int write_skv(int df, int adr, int idx, float val, int Ntry)
{
    int addr = adr;
    char cmd[] = "SP.LU";
    int L;
    char ans[80];
    char nam[16];
    char ssx[80];
    char ssy[80];
    unsigned CRC;
    int chsh;

    int iust = int(val*100.0+0.5);

    L=5;
    nam[0]=0x20;
    nam[1]=(char)(iust >> 8);
    nam[2]=(char)iust;
    nam[3]=0;
    nam[4]=idx;               // индекс

    chsh = hashs(cmd);
    ssy[0]=(char)(addr);
    ssy[1]=(char)0x00 | (L & 0x0F); //запись
    ssy[2]=(char)(chsh >> 8);
    ssy[3]=(char)(chsh & 0xFF);
    for(int i=0; i<L; i++) ssy[4+i]=nam[i];
    CRC=0;
    CRC = hash_buffer(ssy,4+L,0);
    ssy[4+L]=(char)(CRC >> 8);
    ssy[5+L]=(char)(CRC & 0xFF);

    encode_buffer(ssy,6+L,ssx);

    int cnt=0;
    int res=1;
    while(res)
    {
        res=qry_n_ans(df, ssx, ans);
        if(cnt++ >= Ntry) return res;
    }

    int blen=(strlen((char*)ans)-2)/2;

    decode_buffer(ans,ssy);
    if(!ssy[0]) return -4;
    int data_size = ssy[1] & 0x0F;


    unsigned short CRCSumma2;
    char *px= (char*)&CRCSumma2;
    px[0]=ssy[data_size+5];
    px[1]=ssy[data_size+4];

    int CRCSumma3 = hash_buffer(ssy, blen-2, 0);

    if(CRCSumma3 - CRCSumma2) return -1;

    return 0;
}
