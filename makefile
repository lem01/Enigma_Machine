CXX=g++ -Wall -g

enigma: main.o helper.o
	$(CXX) main.o helper.o -o enigma

%.o: %.cpp helper.h
	$(CXX) -c $<

main.o: errors.h

.PHONY: clean
clean:
	rm -f enigma *.o
