import re
import defaultString

class ParseCpp(object):
	"""Parse cpp return Makefile et hpp (cpp)-> hpp, Makefile"""
	def __init__(self, cpp):
		super(ParseCpp, self).__init__()
		self.cpp = cpp
		self.fnc = self.getFnc()

	def getBody(self, str, count):
		if count == 0:
			return '\n', count
		for letter in str:
			if letter == '{':
				count = count + 1
			elif letter == '}':
				count = count - 1
				if count == 0:
					return 0
		return count


	def getFnc(self):
		fnc = []
		inFnc = False
		body = ''
		count = 0
		for line in self.cpp:
			if count:
				count = self.getBody(line, count)
				body += line
				if count == 0:
					tmp['body'] = body
					fnc.insert(len(fnc), tmp)
			if defaultString.REGEXP_FNC.match(line):
				body = ''
				tmp = {'def':line.replace('{', '').replace('\n', '').replace('\t', ' ').replace('  ', ' ')}
				count = 1
		for i in fnc:
			print i['def']
		return fnc

