CXX=g++ -Wall -g
EXE=main.o enigma.o plugboard.o reflector.o rotor.o  helper.o

enigma: $(EXE)
	$(CXX) $(EXE) -o enigma

%.o: %.cpp enigma.h helper.h
	$(CXX) -c $<

main.o: plugboard.h reflector.h rotor.h errors.h
enigma.o: plugboard.h reflector.h rotor.h

.PHONY: clean
clean:
	rm -f enigma *.o
