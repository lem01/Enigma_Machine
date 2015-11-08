CXX=g++ -Wall -g

enigma: main.o enigma.o
	$(CXX) main.o enigma.o -o enigma

%.o: %.cpp enigma.h
	$(CXX) -c $<

.PHONY: clean
clean:
	rm -f enigma *.o
