TARGET = number

all:$(TARGET)

number:number.cpp
	g++ -Wall -o $@ $<

clean:
	rm -rf $(TARGET)

