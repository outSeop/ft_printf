#!/bin/sh
text="test"
if [ $# -eq 2 ]; then
	text= $1
fi
git add .
git commit -m $text
git push origin master
