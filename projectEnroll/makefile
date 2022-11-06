#Makefile para o trabalho

PROG = main
INPUT = inputFile.txt
OUTPUT = outputFile.txt

CFLAGS = -Wall

default :
	@echo ""
	gcc $(CFLAGS) $(PROG).c -o $(PROG)
	@echo ""
	@echo "-----------------------------------"
	@echo "Teste:"
	./$(PROG) <$(INPUT) >$(OUTPUT)
	cat $(OUTPUT)
