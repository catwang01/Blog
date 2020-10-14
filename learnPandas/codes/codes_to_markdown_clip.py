#! /anaconda3/bin/python

import sys
import os
ipynbname = sys.argv[1]
# ipynbname = "pandas-readcsv-chunk.ipynb"
markdownname = ipynbname.split('.')[0] + '.md'

cmds = [
    "notedown {ipynbname} --to markdown --strip > {markdownname} && mv {markdownname} ..".format(ipynbname=ipynbname, markdownname=markdownname),
    "git add {ipynbname} ../{markdownname}".format(ipynbname=ipynbname, markdownname=markdownname),
    'git commit -m "add {} with codes"'.format(markdownname),
    "cat ../{markdownname} | pbcopy".format(markdownname=markdownname),
]

for cmd in cmds:
    try:
        os.system(cmd)
    except:
        print(cmd)
    

