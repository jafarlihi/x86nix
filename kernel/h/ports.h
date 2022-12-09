#ifndef PORTS_H
#define PORTS_H

unsigned short inports(unsigned short _port);
void outports(unsigned short _port, unsigned short _data);
unsigned int inportl(unsigned short _port);
void outportl(unsigned short _port, unsigned int _data);
unsigned char inportb(unsigned short _port);
void outportb(unsigned short _port, unsigned char _data);
void outportsm(unsigned short port, unsigned char *data, unsigned long size);
void inportsm(unsigned short port, unsigned char *data, unsigned long size);

#endif

