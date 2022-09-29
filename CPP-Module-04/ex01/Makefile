NAME	= Animal
SRCS	= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
OBJSDIR	= objs
OBJS	= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
CPP		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
LIBS	=
INCL	= -I includes/
RM		= rm -f

$(OBJSDIR)/%.o:	%.cpp Makefile
	$(CPP) $(CPPFLAGS) $(INCL) -MMD -c $< -o $@

all: $(NAME)

$(OBJS): | $(OBJSDIR)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) $^ $(LIBS) -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
