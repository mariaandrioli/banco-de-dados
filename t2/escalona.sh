#!/bin/sh
make
if [ $? -eq 0 ] ; then
  ./escalona < testes/teste.in
  ./escalona < testes/teste1.in
  ./escalona < testes/teste2.in
else 
  echo "failed to compile"
fi
make purge
