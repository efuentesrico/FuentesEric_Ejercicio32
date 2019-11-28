  
all: wave.png wave.dat a.out

wave.png: wave.dat graph.py
	python3 graph.py

wave.dat: a.out
	./a.out

a.out: wave.cpp
	c++ wave.cpp
	
clean:
	rm a.out wave.dat wave.png