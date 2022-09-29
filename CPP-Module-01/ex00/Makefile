NAME	= BraiiiiiiinnnzzzZ
SRCS	= main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OBJSDIR	= objs
OBJS	= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
LIBS	=
RM		= rm -f

$(OBJSDIR)/%.o:	%.cpp
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all: $(NAME)

$(OBJS): | $(OBJSDIR)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	$(RM) $(OBJS)
	rm -rf $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
