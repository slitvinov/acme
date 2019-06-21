#!/usr/bin/env python3

import subprocess

c = subprocess.run('echo $HOME', shell = True)
#print(c)

