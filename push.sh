#!/bin/sh
text="test"
if [ $# -eq 2 ]; then
	text= $1
fi
git config --global core.autocrlf true
git add .
git commit -m $text
git push origin master
