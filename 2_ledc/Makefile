objs := start.o main.o

ledc.bin: $(objs)
	arm-linux-gnueabihf-ld -Timx6ull.lds $^ -o ledc.elf
	arm-linux-gnueabihf-objcopy -O binary -S -g ledc.elf $@
	arm-linux-gnueabihf-objdump -D ledc.elf > ledc.dis

%.o:%.S
	arm-linux-gnueabihf-gcc -Wall -nostdlib  -c -o $@ $<
	
%.o:%.c
	arm-linux-gnueabihf-gcc -Wall -nostdlib  -c -o $@ $<

clean:
	rm -rf *.o led.bin ledc.elf ledc.dis