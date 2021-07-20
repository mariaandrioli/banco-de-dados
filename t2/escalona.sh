#!/bin/sh
make
./escalona < testes/teste.in
./escalona < testes/teste1.in
./escalona < testes/teste2.in
make purge