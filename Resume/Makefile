CCFLAGS=--std=gnu++98 -pedantic -Wall -Werror -ggdb3
resume: resume_main.o
	g++ -o resume $(CCFLAGS) resume_main.o

%.o: %.cpp resume.h outputColor.h
	g++ -c $(CCFLAGS) $<

clean:
	rm -f *.o  *~ resume

