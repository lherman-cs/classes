comment(`Name       : Lukas Herman')
comment(`Course     : CPSC-2311-001')
comment(`Assignment : Lab-1')
comment(`Description: Counting from 1 to 10. Then, print the sum')

word(zero, 0)
word(sum, 0)
word(i, 0)
word(one, 1)
word(ten, 10)

label(start)
	load(one)	
	store(i)	comment(`i = 1')

label(loop)
	load(i)
	sub(ten)	
	bgt0(done)	comment(`if i - 10 > 0, goto done')

	load(sum)	
	add(i)
	store(sum)	comment(`Increment sum by i')

	load(i)
	add(one)
	store(i)	comment(`Increment i by 1')

	ba(loop)	comment(`Loop over')

label(done)
	print(sum)	comment(`Print the sum of the loop')
	halt

end(start)
