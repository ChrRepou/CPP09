# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 21:46:26 by crepou            #+#    #+#              #
#    Updated: 2023/12/07 21:47:59 by crepou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS  = -g -Wall -Wextra -Werror -std=c++98

TARGET = btc
SRCDIR = src
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

GREEN = \033[0;32m
NC = \033[0m
TICK = \xe2\x9c\x94
PURPLE = \033[0;35m
PURPLE_DARK = \033[1;35m
BLUE = \033[0;34m

all: exec

exec: $(TARGET)
	@echo ""
	@echo "${BLUE}Compilation completed!"
	@echo ""
	@echo "                           ${PURPLE_DARK}.oMc"
	@echo "${PURPLE}                        ${PURPLE_DARK}.MM${PURPLE}MM${PURPLE_DARK}MP"
	@echo "${PURPLE}                      ${PURPLE_DARK}.MM${PURPLE}888${PURPLE_DARK}MM"
	@echo "${PURPLE_DARK}....                ${PURPLE_DARK}.MM${PURPLE}88888${PURPLE_DARK}MP"
	@echo "${PURPLE_DARK}MM${PURPLE}MMM${PURPLE_DARK}MMMb.         ${PURPLE_DARK}d8${PURPLE}MM8tt8${PURPLE_DARK}MM"
	@echo "${PURPLE_DARK} MM${PURPLE}88888MM${PURPLE_DARK}MMc ${PURPLE}\`:' ${PURPLE_DARK}dM${PURPLE}ME8ttt8${PURPLE_DARK}MM"
	@echo "${PURPLE_DARK}  MM${PURPLE}88tt888E${PURPLE_DARK}MMc${PURPLE}:${PURPLE_DARK}dM${PURPLE}M8E88tt88${PURPLE_DARK}MP"
	@echo "${PURPLE_DARK}   MM${PURPLE}8ttt888EEM8MMEEE8E888${PURPLE_DARK}MC"
	@echo "${PURPLE_DARK}   \`MM${PURPLE}EE${BLUE}CHRISTINA${PURPLE}88${BLUE}REPOU${PURPLE}888${PURPLE_DARK}Mb"
	@echo "${PURPLE_DARK}    \"MM${PURPLE}88888tEM8\"MME88ttt88${PURPLE_DARK}MM"
	@echo "${PURPLE_DARK}     dM${PURPLE}88ttt8E${PURPLE_DARK}M8\"MMM${PURPLE}888ttt8${PURPLE_DARK}MM"
	@echo "${PURPLE_DARK}     MM${PURPLE}8ttt88${PURPLE_DARK}MM\" \" \"MM${PURPLE}NICK${PURPLE_DARK}MM"
	@echo "${PURPLE_DARK}     3M${PURPLE}88888${PURPLE_DARK}MM\"     \"MMMP\""
	@echo "${PURPLE_DARK}      \"MNICKM\""
	@echo ""

$(TARGET): $(OBJECTS)
	@echo "${BLUE}Compiling...${GREEN}${TICK}${NC}"
	@$(CC) $(CFLAGS) -o $@ $^ 

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/BitcoinExchange.hpp | $(OBJDIR)
	@echo "${BLUE}Compiling $@...${GREEN}${TICK}${NC}"
	@$(CC) $(CFLAGS) -c -o $@ $< 

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(TARGET) $(OBJECTS)
	$(RM) -r $(OBJDIR)

fclean: clean

re: fclean all

.PHONY: all exec clean fclean re