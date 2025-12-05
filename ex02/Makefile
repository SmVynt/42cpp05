# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 12:51:50 by psmolin           #+#    #+#              #
#    Updated: 2025/12/05 18:46:24 by psmolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = \
		main.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Bureaucrat.cpp
HEADERS = \
		AForm.hpp \
		PresidentialPardonForm.hpp \
		RobotomyRequestForm.hpp \
		ShrubberyCreationForm.hpp \
		Bureaucrat.hpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
