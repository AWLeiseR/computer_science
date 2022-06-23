#!/bin/bash
gcc -c agenda_xdr.c
gcc -c agenda_clnt.c
gcc -c client.c
gcc -c agenda_svc.c
gcc -c server.c
gcc client.o agenda_clnt.o agenda_xdr.o agenda.h -o client
gcc server.o agenda_svc.o agenda_xdr.o agenda.h -o server