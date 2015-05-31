from Var import Var
from Fnc import Fnc
from NSpace import NSpace
import defaultString
import Config

class File(object):
    """docstring for File"""
    def __init__(self, name, FileExt='.class', hpp=True,cpp=True, nameSpace=[], fnc=[], var=[]):
        super(File, self).__init__()
        self.name = name
        self.FileExt = FileExt
        self.hpp = hpp
        self.cpp = cpp
        self.nameSpace = nameSpace
        self.fnc = fnc
        self.var = var

    def newNameSpace(self, name, Type='class'):
        self.addNameSpace(NSpace(name, Type))

    def addNameSpace(self,nameSpace):
        self.nameSpace.insert(len(self.nameSpace), nameSpace)

    def newVar(self, name, Type):
        self.addVar(Var(name, Type))

    def addVar(self, var):
        self.var.insert(len(self.var), var)

    def newFnc(self, name, Type, args=[], body='', inReturn=''):
        self.addFnc(Fnc(name, Type, args=args, body=body, inReturn=inReturn))

    def addFnc(self, fnc):
        self.fnc.insert(len(self.fnc), fnc)

    def newFncNS(self, NameSpace,name, Type, args=[], body='', InReturn=''):
        ns = self.searchNS(NameSpace)
        if ns:
            ns.newFnc(name, Type, args, body, InReturn)
            return True
        else:
            return False

    def newVarNS(self, NameSpace,name, Type, private=True, Get=True, Set=True):
        ns = self.searchNS(NameSpace)
        if ns:
            ns.newVar(name, Type, private, Get, Set)
            return True
        else:
            return False

    def newNameSpaceNS(self, NameSpace,name, Type):
        ns = self.searchNS(NameSpace)
        if ns:
            ns.newNameSpace(name, Type)
            return True
        else:
            return False

    def searchNS(self, NameSpace):
        ret = False
        for i in self.nameSpace:
            if i.name is NameSpace:
                ret = i
        return ret

    def getHpp(self, header=''):
        if header:
            str = header
        else:
            str = ''
        str += "#ifndef " + self.getFilename('hpp').upper().replace('.', '_') + "\n"
        str += "# define " + self.getFilename('hpp').upper().replace('.', '_') + "\n\n"
        for i in self.var:
            str += i.getStringHpp()

        for i in self.nameSpace:
            str += i.getHpp()

        for i in self.fnc:
            str += i.getStringHpp()
        str += "\n#endif"
        return str

    def getCpp(self, header=''):
        if header:
            str = header
        else:
            str = ''
        str += '#include "' + self.getFilename('hpp') + '"\n'
        for i in self.nameSpace:
            str += i.getCpp()
        return str

    def getFilename(self, ext):
        filename = self.name + self.FileExt + '.' + ext
        return filename

    def _writeFile(self, ext, string):
        filename = self.getFilename(ext)
        file = open(filename, 'w+')
        file.write(string)
        file.close
        return string

    def write(self, header='', ext=''):
        hpp = cpp = ''
        if not ext or ext == 'cpp':
            cpp = self._writeFile('cpp', self.getCpp(header))
        if not ext or ext == 'hpp':
            hpp = self._writeFile('hpp', self.getHpp(header))
        return cpp, hpp

