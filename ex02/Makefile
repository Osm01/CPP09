
NAME = PmergeMe

CPPFILES = main.cpp PmergeMe.cpp
CPPCOMPI = c++ -std=c++98 -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

$(NAME) : $(CPPFILES)
	$(CPPCOMPI) $(CPPFILES) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all

.PHONY : re fclean clean all