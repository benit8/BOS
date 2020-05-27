##
## BOS, 2020
## Kernel Makefile
##

CC	=	../Toolchain/local/bin/i386-elf-gcc
CXX	=	../Toolchain/local/bin/i386-elf-g++

CFLAGS	=	-O2 -g \
		-ffreestanding \
		-Wall -Wextra
CXXFLAGS=	$(CFLAGS) \
		-fno-exceptions \
		-fno-rtti
LDFLAGS	=	-nostdlib \
		-lgcc

NAME	=	kernel.elf
S_SRCS	=	start.s
CXX_SRCS=	kernel.cpp \
		TTY.cpp
OBJS	=	$(S_SRCS:.s=.o) \
		$(CXX_SRCS:.cpp=.o)

################################################################################

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) -T linker.ld -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.s.o:
	$(CC) -c $< -o $@ $(CFLAGS)
.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)
.cpp.o:
	$(CXX) -c $< -o $@ $(CXXFLAGS)

d:
	@echo "CC: $(CC)"
	@echo "CXX: $(CXX)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "CXXFLAGS: $(CXXFLAGS)"
	@echo "LDFLAGS: $(LDFLAGS)"
	@echo "OBJS: $(OBJS)"

.PHONY: all $(NAME) clean fclean re .s.o .c.o d