comment(`Name        : Lukas Herman')
comment(`Course      : CPSC2310-001')
comment(`Assignment  : HW-1')
comment(`Due Date    : September 6, 2017')
comment(`Description : Determine if N is a perfect integer or not')

word(N, {N})
word(i, 1)
word(one, 1)
word(sum, 1)
word(result, 0)

label(start)
	load(N)
	sub(one)
	ble0(done)	comment(`if N <= 1, then go to done')

label(loop)
	load(i)		
	add(one)
	store(i)	comment(`i++')
	
	mul(i)
	sub(N)
	bgt0(loop_end)	comment(`while i * i <= N. Else, go to loop_end')
	
	load(N)
	div(i)
	mul(i)	
	sub(N)		
	bne0(loop)	comment(`Accumulate if it's divisible by i.')

	load(N)
	div(i)
	add(i)
	add(sum)
	store(sum)	comment(`sum += N / i + i')
	
	ba(loop)	comment(`Loop over')

label(loop_end)
	load(sum)
	sub(N)
	bne0(done)	comment(`if sum != N, then jump to done')

label(true)
	load(one)
	store(result)	comment(`result = 1')

label(done)
	print(result)	comment(`1 = perfect. 0 = not perfect')
	halt

end(start)
