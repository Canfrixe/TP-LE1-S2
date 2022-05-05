c=gcc
op=-Wall -Wextra

tpBiblio : clean es.o livre.o biblio.o tpBiblio.c
	$(c) $(op) es.o livre.o biblio.o tpBiblio.c -o exe

es.o : es.c
	$(c) $(op) -c es.c

livre.o : livre.c
	$(c) $(op) -c livre.c

biblio.o : biblio.c
	$(c) $(op) -c biblio.c
es.o : es.h
livre.o : livre.h
biblio.o : biblio.h
clean :
	-rm *.o exe
