SRCS = $(wildcard *.py)

all: run

run: $(SRCS)
	python $(SRCS) input.json

test:
	python $(SRCS) '[1,2,3]'       # 6
	python $(SRCS) '{"a":2,"b":4}' # 6
	python $(SRCS) '[[[3]]]'       # 3
	python $(SRCS) '{"a":{"b":4},"c":-1}' # 3
	python $(SRCS) '{"a":[-1,1]}'  # 0
	python $(SRCS) '[-1,{"a":1}]'  # 0
	python $(SRCS) '[]'            # 0
	python $(SRCS) '{}'            # 0
	python $(SRCS) '[1,{"c":"red","b":2},3]' # 4
	python $(SRCS) '{"d":"red","e":[1,2,3,4],"f":5}' # 0
	python $(SRCS) '[1,"red",5]'   # 0
