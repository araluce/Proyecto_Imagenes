HOMEDIR = .
SRC = $(HOMEDIR)/src
INC = $(HOMEDIR)/include
BIN = $(HOMEDIR)/bin
OBJ = $(HOMEDIR)/obj
DOC = $(HOMEDIR)/doc
LIB = $(HOMEDIR)/lib

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: mrproper negativo desplazar ocultar revelar permutar generar documentacion
# ************ Generación de documentación ******************
documentacion:
	doxygen $(DOC)/doxys/Doxyfile


# ************* Generación de directorios *******************
directorios:
	@ echo Creando directorios...
	@-mkdir $(HOMEDIR)/src
	@-mkdir $(HOMEDIR)/include
	@-mkdir $(HOMEDIR)/bin
	@-mkdir $(HOMEDIR)/obj
	@-mkdir $(HOMEDIR)/lib

# ************ Generar ejecutable negativo ************
negativo : $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o $(OBJ)/negativo.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/negativo $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o $(OBJ)/negativo.o
# ************ Generar ejecutable desplazar ************
desplazar : $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o $(OBJ)/desplazar.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/desplazar $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o $(OBJ)/desplazar.o
# ************ Generar ejecutable ocultar ************
ocultar : $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/ocultar.o $(OBJ)/transformar.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/ocultar $(OBJ)/imagen.o $(OBJ)/ocultar.o $(OBJ)/imagenES.o $(OBJ)/transformar.o
# ************ Generar ejecutable revelar ************
revelar : $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/revelar.o $(OBJ)/transformar.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/revelar $(OBJ)/imagen.o $(OBJ)/revelar.o $(OBJ)/imagenES.o $(OBJ)/transformar.o
# ************ Generar ejecutable permutar ************
permutar : $(OBJ)/imagenES.o $(OBJ)/permutar.o $(OBJ)/permutacion.o $(OBJ)/imagen.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/permutacion $(OBJ)/imagenES.o $(OBJ)/permutar.o $(OBJ)/permutacion.o $(OBJ)/imagen.o
# ****** Generar ejecutable fichero_aleatorio *********
generar : $(OBJ)/imagenES.o $(OBJ)/generar.o $(OBJ)/func_generar.o $(OBJ)/imagen.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/generar $(OBJ)/imagenES.o $(OBJ)/generar.o $(OBJ)/func_generar.o $(OBJ)/imagen.o
# ************ Compilación de módulos ************
$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp $(INC)/transformar.h $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o
$(OBJ)/revelar.o : $(SRC)/revelar.cpp $(INC)/transformar.h $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o
$(OBJ)/negativo.o : $(SRC)/negativo.cpp $(INC)/imagen.h $(INC)/transformar.h
	$(CXX) $(CPPFLAGS) $(SRC)/negativo.cpp -o $(OBJ)/negativo.o
$(OBJ)/desplazar.o : $(SRC)/desplazar.cpp $(INC)/imagen.h $(INC)/transformar.h
	$(CXX) $(CPPFLAGS) $(SRC)/desplazar.cpp -o $(OBJ)/desplazar.o
$(OBJ)/permutar.o : $(SRC)/permutar.cpp $(INC)/permutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/permutar.cpp -o $(OBJ)/permutar.o
$(OBJ)/generar.o : $(SRC)/generar.cpp $(INC)/permutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/generar.cpp -o $(OBJ)/generar.o
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
$(OBJ)/transformar.o : $(SRC)/transformar.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/transformar.cpp -o $(OBJ)/transformar.o
$(OBJ)/permutacion.o : $(SRC)/permutacion.cpp $(INC)/permutacion.h $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/permutacion.cpp -o $(OBJ)/permutacion.o
$(OBJ)/func_generar.o : $(SRC)/func_generar.cpp $ $(INC)/func_generar.h
	$(CXX) $(CPPFLAGS) $(SRC)/func_generar.cpp -o $(OBJ)/func_generar.o
	
# ************ Librerias ************

$(LIB)/libimagen.a :$(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/transformar.o $(OBJ)/ocultar.o $(OBJ)/revelar.o $(OBJ)/permutacion.o $(OBJ)/permutar.o $(OBJ)/generar.o
	ar -rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/transformar.o $(OBJ)/ocultar.o $(OBJ)/revelar.o $(OBJ)/permutacion.o $(OBJ)/permutar.o $(OBJ)/generar.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
