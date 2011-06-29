#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Heady Putter v0.1
#
# DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
#                     Version 2, December 2004
#
#  Copyright (C) 2008 ubitux
#  Everyone is permitted to copy and distribute verbatim or modified
#  copies of this license document, and changing it is allowed as long
#  as the name is changed.
#
#             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
#    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
#
#   0. You just DO WHAT THE FUCK YOU WANT TO.
#
#

import fnmatch, os, sys
import datetime as dt

PROJECT = 'Lemipc'
AUTHORS = 'lepage_b'
MAILS = '<lepage_b@epitech.net>'
END = dt.datetime.now()
BEGIN = END - dt.timedelta(days=3, weeks=2, hours=1, minutes=3, seconds=23)
#BEGIN = dt.datetime(year=2008, month=1, day=1, hour=23, minute=4, second=42)

F_END = END.strftime('%a %b %d %H:%M:%S %Y')
F_BEGIN = BEGIN.strftime('%a %b %d %H:%M:%S %Y')
FILES = \
{
    '*.[ch]':   ['/*', '**', '*/'],
    'Makefile': ['##', '##', '##']
}

COLORS = \
{
    'black':    '\033[0;30m',
    'red':      '\033[0;31m',
    'green':    '\033[0;32m',
    'brown':    '\033[0;33m',
    'blue':     '\033[0;34m',
    'purple':   '\033[0;35m',
    'cyan':     '\033[0;36m',
    'gray':     '\033[1;30m',
    'yellow':   '\033[1;33m',
    'white':    '\033[1;37m',
    'lgray':    '\033[0;37m',
    'lblue':    '\033[1;34m',
    'lgreen':   '\033[1;32m',
    'lcyan':    '\033[1;36m',
    'lred':     '\033[1;31m',
    'lpurple':  '\033[1;35m',
    'def':      '\033[0m'
}

class SourceFile:

    def __init__(self, dir, name, match):
        self.dir = dir
        self.name = name
        self.comments = FILES[match]
        self.has_header = False

    def put_header(self):
        c = self.comments
        header = ''
        header += "%s\n" % c[0]
        header += "%s %s for %s in %s\n" % (c[1], self.name, PROJECT, self.dir)
        header += "%s \n" % c[1]
        header += "%s Made by %s\n" % (c[1], AUTHORS)
        header += "%s Login   %s\n" % (c[1], MAILS)
        header += "%s \n" % c[1]
        header += "%s Started on  %s %s\n" % (c[1], F_BEGIN, AUTHORS)
        header += "%s Last update %s %s\n" % (c[1], F_END, AUTHORS)
        header += "%s\n\n" % c[2]
        content = self.content_without_header
        if self.has_header:
            self.debug('lred', 'has already a header -> overrided')
        else:
            self.debug('lgreen', 'header added')
        fd = open(self.path, 'w')
        fd.write(header + ''.join(content))
        fd.close()

    def debug(self, color, message):
        output = '%s %s>>>%s %s'
        print(output % (self.path, COLORS[color], COLORS['def'], message))

    @property
    def path(self):
        return os.path.join(self.dir, self.name)

    @property
    def content_without_header(self):
        fd = open(self.path, 'r')
        content = fd.readlines()
        fd.close()
        emptylines = 0
        for (num, line) in enumerate(content):
            goto_next = False
            if line.strip() == '':
                emptylines += 1
                continue
            for com in self.comments:
                if line.startswith(com):
                    self.has_header = True
                    goto_next = True
                    break
            if not goto_next:
                break
        if emptylines > 1:
            self.debug('lpurple', 'Remove %d empty line(s)' % (emptylines - 1))
        return content[num:]

def find_files(dir_name):
    for (dir, dirs, files) in os.walk(dir_name):
        for file in files:
            for search in FILES:
                if fnmatch.fnmatch(file, search):
                    yield (dir, file, search)
                    break

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage:\t%s <directory>' % sys.argv[0])
    else:
        for (dir, filename, match) in find_files(sys.argv[1]):
            file = SourceFile(dir, filename, match)
            file.put_header()
