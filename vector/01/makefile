exe = run
obj = main.o vector.o
file = main.cpp

$(exe):$(obj)
	g++ -o $(exe) $(obj)
main.o:main.cpp
	g++ -c main.cpp
vector.o:vector.cpp vector.h
	g++ -c vector.cpp
clean:
	rm $(exe) $(obj)
