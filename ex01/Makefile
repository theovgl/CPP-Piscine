NAME	= RPN
SRCS	= main.cpp RPN.cpp
OBJSDIR	= objs
OBJS	= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
CC		= c++
CFLAGS	= -Wall -Wextra -std=c++98
LIBS	=
INCL	= -I includes/
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
