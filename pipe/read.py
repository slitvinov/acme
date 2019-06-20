#!/usr/bin/env python2

import code

def e(s):
	co = code.compile_command(s, "<stdin>", "eval")
	if co:
		i.runcode(co)

i = code.InteractiveInterpreter()
e("x = ")

