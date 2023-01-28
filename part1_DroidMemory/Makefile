G++			=	g++
##############################################
BIN_PATH	=	./bin
SRC_PATH	=	./src
TST_PATH	=	./tests
INC_PATH	=	./include

NAME		=	DroidMemory
TEST_NAME 	= 	test_$(NAME)
##############################################

INCFLAGS	+=	-I $(INC_PATH)

CPPFLAGS	+= -Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z


SRCS		=	$(SRC_PATH)/Droid.cpp \
				$(SRC_PATH)/DroidMemory.cpp \
				$(BIN_PATH)/main_DroidMemory.cpp

SRC_TEST	=	$(TST_PATH)/$(NAME)_test.cpp

OBJS		=	$(SRCS:.cpp=.o)

CLEAN		=	clean
FCLEAN		=	fclean


all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM			=	rm -rf

clean		:
				$(RM) $(OBJS)
				@$(MAKE) $(CLEAN) -C $(TST_PATH)

fclean		:	clean
				$(RM) $(NAME) $(TEST_NAME)
				@$(MAKE) $(FCLEAN) -C $(TST_PATH)

re			: 	fclean all

tests_run	:	fclean
				@$(MAKE) -C $(TST_PATH)
				$(TST_PATH)/$(TEST_NAME)

.PHONY		: 	all clean fclean re tests_run

# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct