.PHONY:clean
main:sharestack.c
	gcc $^ -o $@
clean:
	rm -f main
