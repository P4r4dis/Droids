G++				=	g++
#############################################
TEST_SRC_PATH	=	./test_src
TEST_INC_PATH	=	./test_include
TEST_BIN_PATH	=	./test_bin

TEST_SRC		=	$(TEST_SRC_PATH)/test_Droid.cpp \
					$(TEST_SRC_PATH)/test_DroidMemory.cpp \
					$(TEST_SRC_PATH)/test_Carrier.cpp \
					$(TEST_SRC_PATH)/test_Supply.cpp \
					$(TEST_SRC_PATH)/test_Src.cpp

NAME			=	test_Supply
#############################################

INCFLAGS		+=	-I$(TEST_INC_PATH)
CRITFLAGS		+=	--coverage -lcriterion --verbose
CPPFLAGS		+=	-Wall -Wextra -Werror $(INCFLAGS) $(CRITFLAGS)


SRCS			=	$(TEST_BIN_PATH)/test_main_Supply.cpp \
					$(TEST_SRC)


OBJS			=	$(SRCS:.cpp=.o)
OBJS_GCDA		=	$(SRCS:.cpp=.gcda)
OBJS_GCNO		=	$(SRCS:.cpp=.gcno)


all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM				=	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO)
					$(RM) $(TEST_SRC_PATH)$(OBJS) $(TEST_SRC_PATH)$(OBJS_GCDA) $(TEST_SRC_PATH)$(OBJS_GCNO)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re