SERVER		= server
CLIENT		= client
NAME		= $(SERVER) $(CLIENT)

SRCS_DIR	= srcs/
HEAD_DIR	= includes/
BUILD_DIR	= build/

LIBFT_SRCS	= libft/atoi.c			\
			  libft/memcpy.c		\
			  libft/print_error.c	\
			  libft/putchar_fd.c	\
			  libft/putstr_fd.c		\
			  libft/string.c

SERVER_SRCS	= server/server.c		\
			  server/reciever.c

CLIENT_SRCS	= client/client.c

#SRCS_FILES	= $(SERVER_SRCS)
SERVER_SRCS	:= $(SERVER_SRCS) $(LIBFT_SRCS)
CLIENT_SRCS	:= $(CLIENT_SRCS) $(LIBFT_SRCS)

OBJS_FILES	= $(SRCS_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		= $(addprefix $(BUILD_DIR), $(OBJS_FILES))
DEPS		= $(OBJS:.o=.d)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

link: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

#$(SERVER): $(OBJS)
#	$(CC) $(OBJS) -o $(SERVER)

$(SERVER):
	make SRCS_FILES='$(SERVER_SRCS)' NAME='$(SERVER)' link

$(CLIENT):
	make SRCS_FILES='$(CLIENT_SRCS)' NAME='$(CLIENT)' link

-include $(DEPS)

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c $(BUILD_DIR)%.d
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -I $(HEAD_DIR) -o $@ -c $<

$(BUILD_DIR)%.d: $(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -I $(HEAD_DIR) -o $(@:.d=.o) -c $<

clean: 
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all link clean fclean re
