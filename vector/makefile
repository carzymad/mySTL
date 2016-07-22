exe = run
obj = main.o
file = main.cpp

$(exe):$(obj)
	g++ -o $(exe) $(obj)
$(obj):$(file)
	g++ -c $(file)
clean:
	rm $(exe) $(obj)
