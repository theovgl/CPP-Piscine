NAME	= Indentifier
SRCS	= main.cpp Base.cpp A.cpp B.cpp C.cpp typeFunctions.cpp
OBJSDIR	= objs
OBJS	= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
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
