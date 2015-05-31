import defaultString
import Config

class Var(object):
    """docstring for function"""
    def __init__(self, name, Type='int', private=False, NameSpace='', useSpace=False, const=False):
        super(Var, self).__init__()
        self.name = name
        self.private = private
        self.Type = Type
        self.NameSpace = NameSpace
        self.tabSize = Config.tab_size
        self.useSpace = useSpace
        self.const = const

    def lenSpace(self, tabAligne):
        length = tabAligne * self.tabSize
        length = length - len(self.Type)
        if self.const == True:
            length = length - 5
        if self.useSpace == False:
            length = length / self.tabSize
            if length % self.tabSize :
                    length = length + 1
        return length

    def getTabOrSpace(self, tabAligne=4):
        c = ' '
        ret = ''
        length = self.lenSpace(tabAligne)
        # tabAligne
        if self.useSpace == False:
            c = '\t'
        while length:
            ret += c
            length = length - 1
        return ret

    def _getPrivateStr(self):
        if self.private:
            return ''
        else:
            return ''

    def _getCpp(self):
        return ''

    def getStringCpp(self):
        if not self.allInHpp:
            return _getCpp()

    def _getHpp(self, printNameSpace=False ,tabSpace=4):
        tnSpace = self.getTabOrSpace(tabSpace)
        default = defaultString.all['DefaultAttribueHpp']
        return default.format(Type=self.Type,
                                  Name='_' + self.name,
                                  NameSpace=self.NameSpace,
                                  TNSPACE=tnSpace,
                                  Private=self._getPrivateStr())

    def getStringHpp(self, printNameSpace=False, tabSpace=4):
        return self._getHpp(printNameSpace,tabSpace=tabSpace)