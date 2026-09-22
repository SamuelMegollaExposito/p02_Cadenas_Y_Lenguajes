CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

OBJS = simbolo.o alfabeto.o cadena.o lenguaje.o p02_strings.o

p02_strings: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o p02_strings
