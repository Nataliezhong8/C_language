objects = ex2_sumnum.o 

sumnum : $(objects)
		dcc -o sumnum $(objects)

ex2_sumnum.o : ex2_sumnum.c 

.PHONY : clean
clean :
		-rm sumnum $(objects)