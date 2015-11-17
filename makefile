CXX=g++ -Wall -g
EXE=main.o enigma.o helper.o

enigma: $(EXE)
	$(CXX) $(EXE) -o enigma

%.o: %.cpp helper.h
	$(CXX) -c $<

main.o: enigma.h errors.h
enigma.o: enigma.h

.PHONY: clean
clean:
	rm -f enigma *.o
