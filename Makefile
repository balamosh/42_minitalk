SERVER		= server
CLIENT		= client
NAME		= $(SERVER) $(CLIENT)

SRCS_DIR	= srcs/
HEAD_DIR	= includes/
BUILD_DIR	= build/

LIBFT_SRCS_FILES	= libft/atoi.c				\
					  libft/malloc.c			\
					  libft/memcpy.c			\
					  libft/print_error.c		\
					  libft/print_name_pid.c	\
					  libft/putchar_fd.c		\
					  libft/putnbr_fd.c			\
					  libft/putstr_cd_fd.c		\
					  libft/putstr_fd.c			\
					  libft/string.c

SERVER_SRCS_FILES	= server/server.c			\
					  server/reciever.c

CLIENT_SRCS_FILES	= client/client.c			\
			  		  client/reciever.c			\
					  client/sender.c

SERVER_SRCS_FILES	:= $(SERVER_SRCS_FILES) $(LIBFT_SRCS_FILES)
CLIENT_SRCS_FILES	:= $(CLIENT_SRCS_FILES) $(LIBFT_SRCS_FILES)

SERVER_SRCS = $(addprefix $(SRCS_DIR), $(SERVER_SRCS_FILES))
CLIENT_SRCS = $(addprefix $(SRCS_DIR), $(CLIENT_SRCS_FILES))
SERVER_OBJS	= $(addprefix $(BUILD_DIR), $(SERVER_SRCS_FILES:.c=.o))
CLIENT_OBJS	= $(addprefix $(BUILD_DIR), $(CLIENT_SRCS_FILES:.c=.o))
SERVER_DEPS = $(SERVER_OBJS:.o=.d)
CLIENT_DEPS = $(CLIENT_OBJS:.o=.d)
DEPS		= $(SERVER_OBJS:.o=.d) $(CLIENT_OBJS:.o=.d)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(SERVER): $(SERVER_OBJS)
	$(CC) $^ -o $@

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $^ -o $@

ifeq ($(MAKECMDGOALS),)
-include $(DEPS)
endif
ifeq ($(MAKECMDGOALS), $(SERVER))
-include $(SERVER_DEPS)
endif
ifeq ($(MAKECMDGOALS), $(CLIENT))
-include $(CLIENT_DEPS)
endif

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
