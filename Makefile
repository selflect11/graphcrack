CC = g++
IPATH = include/
CC_FLAGS = -Wall -std=c++11 -I $(IPATH) $(FLAGS)
LD_FLAGS = -Wall

TEST_FILES = $(wildcard test/*.cpp)
TEST_OBJS = $(addprefix test/obj/,$(notdir $(TEST_FILES:.cpp=.o)))
TEST_EXECS = $(addprefix test/bin/,$(basename $(notdir $(TEST_FILES))))

LIB_FILES = $(wildcard src/lib/*.cpp)
LIB_OBJS = $(addprefix obj/lib/,$(notdir $(LIB_FILES:.cpp=.o)))

EXECS_SRC = $(wildcard src/*.cpp)
EXECS = $(addprefix bin/,$(basename $(notdir $(EXECS_SRC))))

all: test $(EXECS)

# Executables

bin/%: obj/%.o $(LIB_OBJS)
	$(CC) $(LD_FLAGS) -o $@ $< $(LIB_OBJS)

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

# Lib

obj/lib/%.o: src/lib/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

# Tests

test/bin/%: test/obj/%.o $(LIB_OBJS)
	$(CC) $(LD_FLAGS) -o $@ $< $(LIB_OBJS)

test/obj/%.o: test/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

test: $(TEST_EXECS)
	$(foreach test,$(TEST_EXECS),$(test);)
.PHONY: test

# Utility

clean:
	rm $(TEST_OBJS) $(LIB_OBJS) $(TEST_EXECS)
