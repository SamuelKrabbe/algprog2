#Makefile para o trabalho

PROG = main
ENTRA = entrada.txt
SAI = saida.txt

CFLAGS = -pedantic -Wall 

default :
	@echo ""
	gcc $(PROG).c $(CFLAGS) -o $(PROG) 
	@echo ""
	@echo "-----------------------------------"
	@echo "Teste:"
	./$(PROG) < $(ENTRA) > $(SAI)
	cat $(SAI)
