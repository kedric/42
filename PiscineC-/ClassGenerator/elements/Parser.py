import ParserCpp

class Parse(object):
	"""Read Cpp/Hpp (cpp, hpp) -> cpp, hpp, MakeFile"""
	def __init__(self, cpp='', hpp=''):
		super(Parse, self).__init__()
		self.hpp = hpp
		if cpp:
			self.cpp = cpp
			ParserCpp.ParseCpp(cpp)