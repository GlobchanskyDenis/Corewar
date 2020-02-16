.name     "Unabomber"
.comment  "bomb on you"

protector:
	zjmp %-20		## 3 bytes
	ld %0, r9		## 7 bytes
alive:
	sti r1, %7, r9	## 6 bytes
	live %0			## 5 bytes
fork_loop:
	fork %:attack	## 3 bytes
	zjmp %:alive	## 3 bytes
attack:
	sti r9, %2021, r9		## 6 bytes
	sti r9, %2021, r9		## 6 bytes
	sti r9, %2021, r9		## 6 bytes
	sti r9, %1320, r9		## 6 bytes
	sti r9, %1314, r9		## 6 bytes
	sti r9, %1308, r9		## 6 bytes
	sti r9, %2667, r9		## 6 bytes
	sti r9, %2661, r9		## 6 bytes
	sti r9, %2655, r9		## 6 bytes
	sti r9, %943, r9		## 6 bytes
	sti r9, %937, r9		## 6 bytes
	sti r9, %931, r9		## 6 bytes
	sti r9, %2973, r9		## 6 bytes
	sti r9, %2967, r9		## 6 bytes
	sti r9, %2961, r9		## 6 bytes
