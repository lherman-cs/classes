comment(`Name        : Lukas Herman')
comment(`Course      : CPSC2310-001')
comment(`Assignment  : HW-1')
comment(`Due Date    : September 6, 2017')
comment(`Description : Determine if N is a perfect integer or not')

word(N, 8128)
word(i, 0)
word(one, 1)
word(sum, 0)
word(result, 0)

label(start)
	load(N)
	store(i)	comment(`i = N')

label(loop)
	load(i)		
	sub(one)
	store(i)	comment(`i--')
	
	ble0(loop_end)	comment(`for i from N - 1 to 1')
	
	load(N)
	div(i)
	mul(i)	
	sub(N)		
	beq0(accumulate) comment(`This is a trick to check if it's divisible by i')
	
	
	ba(loop)	comment(`Loop over')


label(accumulate)
	load(sum)
	add(i)
	store(sum)	comment(`sum += i')
	
	ba(loop)	comment(`Go back to the loop')

label(loop_end)
	load(sum)
	sub(N)
	bne0(done)	comment(`if sum - N != 0, then jump to done')

label(true)
	load(one)
	store(result)	comment(`result = 1')

label(done)
	print(result)	comment(`1 = perfect. 0 = not perfect')
	halt

end(start)
