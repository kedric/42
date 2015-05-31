from Var import Var
import defaultString
import Config

class Fnc(Var, object):
    """docstring for function"""
    def __init__(self, name, Type='', inLine=False, private=False, allInHpp=False,inReturn='', NameSpace='', body='',args=[]):
        super(Fnc, self).__init__(name, Type=type)
        self.inLine = inLine
        self.private = private
        self.Type = Type
        self.args = args
        self.inReturn = inReturn
        self.NameSpace = NameSpace
        self.body = body
        self.allInHpp=allInHpp
        if allInHpp:
            self.inLine = True

    # j ajoute largs avec 2 champs (name,type)
    def addArgs(self, name, type): self.args.insert(len(self.args), {'name': name, 'type': type})
    # j ajoute la chaine de caracther dans le return{inReturn}
    def setInReturn(self, str): self.inReturn = '' if self.Type == 'void' else ' (' + str + ')'
    # add le namestpace {NameSpace}::{Name} SANS LES ::
    def setNameSpace(self, NameSpace): self.NameSpace = NameSpace
    # set le boulean qui controlle si c en une seul ligne
    def setInLine(self, to): self.inLine = True if self.allInHpp == True else to

    def getStringCpp(self, tabSpace=4):
        """get a string of fonction in format C++ (tabSpace)-> 'Cpp' \n"""
        return self._getCpp(tabSpace=tabSpace, printNameSpace=True)
    # formate les arguments
    def _argsToStr(self):
        str = ''
        for i in self.args:
            if str == '':
                str += i['type'] + ' ' + i['name']
            else:
                str += ', ' + i['type'] + ' ' + i['name']
        return str
    #fomate le code en cpp
    def _getCpp(self, printNameSpace=False, tabSpace=4):
        default = ''
        tnSpace = self.getTabOrSpace(tabSpace)
        if self.inLine:
            if self.NameSpace and printNameSpace:
                default = defaultString.all['DefaultMethodeCppInline']
            else:
                default = defaultString.all['DefaultfncCppInline']
        else:
            if self.NameSpace and printNameSpace:
                default = defaultString.all['DefaultMethodeCpp']
            else:
                default = defaultString.all['DefaultfncCpp']
        return default.format(Type=self.Type,
                                  inReturn=self.inReturn,
                                  Name=self.name,
                                  args=self._argsToStr(),
                                  body=self.body,
                                  Private=self._getPrivateStr(),
                                  NameSpace=self.NameSpace,
                                  TNSPACE=tnSpace,
                                  sep='{', sepinv='}')



    def _getHpp(self, printNameSpace=False, tabSpace=4):
        default = ''
        tnSpace = self.getTabOrSpace(tabSpace)
        if self.allInHpp:
            return self._getCpp(printNameSpace)
        else:
            if self.NameSpace and printNameSpace:
                default = defaultString.all['DefaultMethodeHpp']
            else:
                default = defaultString.all['DefaultfncHpp']
        return default.format(Type=self.Type,
                                  inReturn=self.inReturn,
                                  Name=self.name,
                                  args=self._argsToStr(),
                                  body=self.body,
                                  Private=self._getPrivateStr(),
                                  NameSpace=self.NameSpace,
                                  TNSPACE=tnSpace,
                                  sep='{', sepinv='}')