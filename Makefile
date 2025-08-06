CC := gcc 

LIB_PREFIX := lib
SRC_PREFIX := system
TEST_PREFIX := .test
BIN_PREFIX := bin
BIN_TEST_PREFIX := bin/.test
OBJ_PREFIX := bin/obj

libmemory_management.so:
	${CC} -c ${SRC_PREFIX}/memory_management/memory_management.c -o ${OBJ_PREFIX}/memory_management.o -fPIC
	${CC} -o ${LIB_PREFIX}/libmemory_management.so -I ${SRC_PREFIX}/memory_management/ -shared ${OBJ_PREFIX}/memory_management.o 
libconfig_reader.so:
	${CC} -c ${SRC_PREFIX}/config-reader/config-reader.c -o ${OBJ_PREFIX}/config-reader.o -fPIC 
	${CC} -o ${LIB_PREFIX}/libconfig_reader.so -I ${SRC_PREFIX}/config-reader/ -shared ${OBJ_PREFIX}/config-reader.o 

build-test-memory_management:
	${CC} ${TEST_PREFIX}/memory_management/test_memory_management.c -L ${LIB_PREFIX} -lmemory_management -I ${SRC_PREFIX}/memory_management/ -Wl,-rpath=${LIB_PREFIX} -o ${BIN_TEST_PREFIX}/test_memory_management -g
 

clean-obj:
	rm ${BIN_PREFIX}/obj/*
