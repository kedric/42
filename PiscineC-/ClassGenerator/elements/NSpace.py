from Var import Var
from Fnc import Fnc
import defaultString
import Config

class NSpace(Var):
    """docstring for NameSpace"""
    def __init__(self, name, type, nameSpace='', fnc=[], variables=[], subNameSpace=[]):
        super(NSpace, self).__init__(name,type, NameSpace=nameSpace)
        self.fnc = fnc
        self.variables = variables
        self.subNameSpace = subNameSpace
        self.modified = True
        if type is 'class':
            self.newFnc(name='~' + name, Type=' ', args=[{'name': ' ', 'type': ' void'}])
            self.newFnc(name=name, Type=' ', args=[{'name': ' ', 'type': ' void'}])
            self.newFnc(name=name, Type=' ', args=[{'name': 'in', 'type': name +'&' }], body="*this = in;", allInHpp=True)
            self.newFnc(name="operator=", Type=name + '&' , args=[{'name': 'rhs', 'type': name +'&' }], body="// this->* = in;")
            # self.newFnc(name="operator<<", Type=name + '&' , args=[{'name': 'rhs', 'type': name +'&' }], body="// this->* = in;")

    def newFnc(self, name, Type, args=[], body='', InReturn='', allInHpp=False):
        self.modified = True
        self.addFnc(Fnc(name=name,Type=Type, args=args, body=body, inReturn=InReturn, NameSpace=self.name, allInHpp=allInHpp))
        return

    def newVar(self, name, Type, private=True, Get=True, Set=True):
        self.modified = True
        self.addVar(Var(name , Type, NameSpace=self.name,private=private))
        self.addGetSet( name, Type, Set, Get)
        return

    def newNameSpace(self, name, Type='class'):
        self.modified = True
        self.addNameSpace(NSpace(name, Type))

    def addNameSpace(self,nameSpace):
        self.modified = True
        self.subNameSpace.insert(len(self.subNameSpace), nameSpace)

    def addVar(self, variables):
        self.modified = True
        self.variables.insert(len(self.variables),variables)

    def addFnc(self, fnc):
        self.modified = True
        self.fnc.insert(len(self.fnc),fnc)
        return

    def addGetSet(self, name, Type, set=True, get=True):
        self.modified = True
        if get:
            self.addFnc(Fnc(name= 'get_' + name, Type=Type, NameSpace=self.name, inReturn=" this->_" + name, allInHpp=True))
        if set:
            self.addFnc(Fnc(name= 'set_' + name, Type='void', NameSpace=self.name, args=[{'name': 'in', 'type': Type}], body="this->_" + name + " = in;",allInHpp=True))
        return

    def _getfncHpp(self, private):
        str=''
        for i in self.fnc:
            if i.private == private:
                str += i.getStringHpp()
        return str

    def _getVarHpp(self, private):
        str=''
        for i in self.variables:
            if i.private == private:
                str += i.getStringHpp()
        return str

    def _getNameSpaceHpp(self):
        str =''
        i = 0
        while (i < len(self.subNameSpace)):
            str += self.subNameSpace[i].getHpp()
            i += 1
        return str

    def getHpp(self,header=''):
        str= self.Type + ' '+ self.name +" {\n"
        str += "\tprivate:\n"
        # str += self._getNameSpaceHpp()
        str += self._getfncHpp(True)
        str += self._getVarHpp(True)
        str += "\tpublic:\n"
        str += self._getfncHpp(False)
        str += self._getVarHpp(False)
        str += "};\n"
        self.hpp = str
        self.modified = False
        return str

    def getCpp(self):
        str = ''
        for i in self.fnc:
            if i.allInHpp == False:
                str += i.getStringCpp()
        self.str = str
        self.modified = False
        return str

