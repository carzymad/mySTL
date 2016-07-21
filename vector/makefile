exe = run
obj = test.o vector.o
file = test.cpp

$(exe):$(obj)
	g++ -o $(exe) $(obj)
test.o:test.cpp
	g++ -c test.cpp
vector.o:vector.cpp vector.h
	g++ -c vector.cpp
clean:
	rm $(exe) $(obj)
