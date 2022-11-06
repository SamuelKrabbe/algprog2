#Makefile para o trabalho

PROG = main
ENTRA = inputFile.txt
SAI = outputFile.txt

CFLAGS = -Wall

default :
	@echo ""
	gcc $(CFLAGS) $(PROG).c -o $(PROG)
	@echo ""
	@echo "-----------------------------------"
	@echo "Teste:"
	./$(PROG) <$(ENTRA) >$(SAI)
	cat $(SAI)
