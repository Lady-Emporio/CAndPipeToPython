import json
import sys
command="sizeTable"
if len(sys.argv)==2:
	command=sys.argv[1]
f=open("style.json")
text=f.read()
parsed_string = json.loads(text)
print(parsed_string[command])