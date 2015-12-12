run:
	python day12.py input.json

test:
	python day12.py '[1,2,3]'       # 6
	python day12.py '{"a":2,"b":4}' # 6
	python day12.py '[[[3]]]'       # 3
	python day12.py '{"a":{"b":4},"c":-1}' # 3
	python day12.py '{"a":[-1,1]}'  # 0
	python day12.py '[-1,{"a":1}]'  # 0
	python day12.py '[]'            # 0
	python day12.py '{}'            # 0
	python day12.py '[1,{"c":"red","b":2},3]' # 4
	python day12.py '{"d":"red","e":[1,2,3,4],"f":5}' # 0
	python day12.py '[1,"red",5]'   # 0

clean:
	$(RM) day11
