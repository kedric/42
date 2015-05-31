# Function / Methode
import re
all = {
'DefaultMethodeCpp' : """
{Private}{Type}{TNSPACE}{NameSpace}::{Name}({args}) {sep}
	{body}
	return{inReturn};
{Private}{sepinv};
""",
'DefaultfncCpp' : """
{Private}{Type}{TNSPACE}{Name}({args}) {sep}
	{body}
	return{inReturn};
{sepinv};
""",
'DefaultMethodeCppInline' : "{Private}{Type}{TNSPACE}{NameSpace}::{Name}({args}) {sep} {body} return{inReturn}; {sepinv}\n",
'DefaultfncCppInline' : "{Private}{Type}{TNSPACE}{Name}({args}) {sep} {body} return{inReturn}; {sepinv}\n",

'DefaultfncHpp': "{Private}{Type}{TNSPACE}{Name}({args});\n",

'DefaultMethodeHpp': "{Private}{Type}{TNSPACE}{NameSpace}::{Name}({args});\n",

'DefaultAttribueHppNS': "{Private}{Type}{TNSPACE}{NameSpace}::{Name};\n",

'DefaultAttribueHpp': "{Private}{Type}{TNSPACE}{Name};\n"

}

REGEXP_FNC = re.compile("([a-zA-Z0-9:_]+)[&*\t ]+([a-zA-Z0-9:_]+)\(([a-zA-Z0-9_:, &*]+)?\)\s*{")
REGEXP_FNC2 = re.compile("([a-zA-Z0-9:_]+)[&*\t ]+([a-zA-Z0-9:_]+)\(\)\s?{")
