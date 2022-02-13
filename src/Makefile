#.DEFAULT_GOAL := generate

.PHONY: all generate clean

CC = g++

CCFLAGS=-g -std=c++17 -Wall

INC = -Ieaton_reader/intf -Ieaton_reader/impl -Iconnector_impl -Idatasrc_impl

SRC = connector_impl/RS232_Connector.cpp connector_impl/RS485_Connector.cpp datasrc_impl/RS232_Dev_Impl_A.cpp datasrc_impl/RS232_Dev_Impl_B.cpp datasrc_impl/RS485_Dev_Impl_A.cpp eaton_reader/impl/DataProcessor.cpp eaton_reader/impl/ReaderAlgo.cpp

all: generate

generate:
	@echo "Generating.."
	${CC} ${CCFLAGS} ${INC} main.cpp ${SRC} -o dataReader.exe
clean:
	@echo "Cleaning up.."
	rm *.exe
hello: hello.c
	${CC} hello.c -o hello
