CPP = g++
TARGET = contactos

all: .all-post

.all-post: TablaHash.o Arbol.o NodoArbol.o Grupo.o Field.o Menu.o Consola.o Dato.o Graficador.o Exportador.o Reportes.o main.o
	$(CPP) TablaHash.o Arbol.o NodoArbol.o Grupo.o Field.o Menu.o Consola.o Dato.o Graficador.o Exportador.o Reportes.o main.o -o $(TARGET)

TablaHash.o: TablaHash.cpp TablaHash.h
	$(CPP) -c TablaHash.cpp

Arbol.o: Arbol.cpp Arbol.h
	$(CPP) -c Arbol.cpp

NodoArbol.o: NodoArbol.cpp NodoArbol.h
	$(CPP) -c NodoArbol.cpp

Grupo.o : Grupo.cpp Grupo.h
	$(CPP) -c Grupo.cpp

Field.o: Field.cpp Field.h
	$(CPP) -c Field.cpp

Menu.o: Menu.cpp Menu.h
	$(CPP) -c Menu.cpp

Consola.o: Consola.cpp Consola.h
	$(CPP) -c Consola.cpp

Dato.o: Dato.cpp Dato.h
	$(CPP) -c Dato.cpp

Graficador.o: Graficador.cpp Graficador.h
	$(CPP) -c Graficador.cpp

Exportador.o: Exportador.cpp Exportador.h
	$(CPP) -c Exportador.cpp

Reportes.o: Reportes.cpp Reportes.h
	$(CPP) -c Reportes.cpp

main.o:
	$(CPP) -c main.cpp

clean:
	rm -f *.o $(TARGET)