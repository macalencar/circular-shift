all:
	$(info Compilando...)
	gcc -o shift ise-tp2.c
	$(info Para usar execute: ./shift)
clean:
	$(info Excluindo binario...)
	rm -rf shift

