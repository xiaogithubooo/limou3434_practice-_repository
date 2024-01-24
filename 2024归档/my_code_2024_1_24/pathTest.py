import os
from pathlib import PurePath
from pathlib import PureWindowsPath
from pathlib import PurePosixPath

print("当前工作目录为:", os.getcwd())
print(PurePath( 'FatherDir', 'SonDir', 'setup.py'))
print(PureWindowsPath( 'FatherDir', 'SonDir', 'setup.py'))
print(PurePosixPath( 'FatherDir', 'SonDir', 'setup.py'))
