# COLORS #
#
GREEN 	= @echo "\033[0;32m"
BLUE 	= @echo "\033[0;34m" 
PURPLE 	= @echo "\033[0;35m"
CYAN 	= @echo "\033[0;36m"
RESET 	= "\033[1;0m"

# VARIABLES #
#
NAME 		= quickathon
CC 			= c++
INCLUDE 	= -std=c++98
CXXFLAGS 	= -Wall -Wextra -Werror

# PATHs #
#
SRC_PATH    	= srcs
SUBFILE1_PATH   = product
SUBFILE2_PATH   = files
SUBFILE3_PATH   = debug
SUBFILE4_PATH   = search
OBJ_PATH    	= objects
TEST_PATH		= test

# SOURCES #

SUBFILE1_SRC = product.cpp

SUBFILE2_SRC = files.cpp

SUBFILE3_SRC = debug.cpp

SUBFILE4_SRC = search.cpp

SRC =  	main.cpp \
		$(addprefix $(SUBFILE1_PATH)/, $(SUBFILE1_SRC)) \
		$(addprefix $(SUBFILE2_PATH)/, $(SUBFILE2_SRC)) \
		$(addprefix $(SUBFILE3_PATH)/, $(SUBFILE3_SRC)) \
		$(addprefix $(SUBFILE4_PATH)/, $(SUBFILE4_SRC))



# RULES #
all: $(NAME)

SRCS = $(addprefix $(SRC_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(SRC:%.cpp=%.o))



$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(addprefix $(OBJ_PATH)/, $(SUBFILE1_PATH))
	mkdir -p $(addprefix $(OBJ_PATH)/, $(SUBFILE2_PATH))
	mkdir -p $(addprefix $(OBJ_PATH)/, $(SUBFILE3_PATH))
	mkdir -p $(addprefix $(OBJ_PATH)/, $(SUBFILE4_PATH))


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH)
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
            
$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
#clear
	$(GREEN) Program asembled $(RESET)

##RULES
$(MAKE): make

clean:
	$(PURPLE) CLEANING OBJECTS $(RESET)
	rm -rf $(OBJ_PATH)
	
fclean: clean tclean
	$(PURPLE) CLEANING DIRECTORY AND EXEC $(RESET)
	rm -rf $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all

test:
	mkdir -p $(TEST_PATH)
	Ln -sf	$(PWD)/$(SRC_PATH)/$(SUBFILE1_PATH) $(PWD)/$(TEST_PATH)/
	@echo "int main(int argc, char **argv)" >> $(PWD)/$(TEST_PATH)/$(SUBFILE1_PATH)/main.cpp
	@echo "{" >> $(PWD)/$(TEST_PATH)/$(SUBFILE1_PATH)/main.cpp
	@echo "return (0);" >> $(PWD)/$(TEST_PATH)/$(SUBFILE1_PATH)/main.cpp
	@echo "}" >> $(PWD)/$(TEST_PATH)/$(SUBFILE1_PATH)/main.cpp

tclean:
	rm -rf $(TEST_PATH)

PHONY.: all clean fclean re
