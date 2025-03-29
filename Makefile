CC = g++
CFLAGS = -Wall -Iinclude
TESTS = test.cpp app.cpp calc.cpp
APP = app
TEST_EXECUTABLE = test_runner

all: $(APP)

$(APP): app.o calc.o
	$(CC) -o $(APP) app.o calc.o

test: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TESTS)
	$(CC) -o $(TEST_EXECUTABLE) $(TESTS)

run_tests: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

clean:
	rm -f $(APP) $(TEST_EXECUTABLE) *.o

app.o: app.cpp
	$(CC) $(CFLAGS) -c app.cpp

calc.o: calc.cpp
	$(CC) $(CFLAGS) -c calc.cpp

test_runner: run_tests
	@echo "Tests completed successfully."

build: run_tests all
