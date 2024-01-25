from pathlib import Path
from pathlib import WindowsPath
from pathlib import PosixPath

# 寻找工作路径和家路径
print(Path.cwd())
print(Path.home())


# 查询文件的属性
p = Path('pathTest.py')
print(p.stat().st_size)
print(p.stat().st_mtime)
print(p.stat().st_mode)


# 更改文件模式和权限
p.chmod(0o777) # 设置文件为所有用户都有完整权限
p.stat().st_mode # 注意不同平台对权限的理解可能不太一样，这点需要用户自己把控


# 查找文件/目录是否存在
print(Path('.').exists())
print(Path('pathTest.py').exists())
print(Path('/etc').exists())
print(Path('nonexistentfile').exists())

# 转化包含波浪号的家目录
# (1)创建包含波浪号的路径
user_home_path = Path("~/documents")
# (2)使用 expanduser() 方法扩展波浪号表示的用户主目录
expanded_path = user_home_path.expanduser()
# (3)输出扩展后的路径
print(expanded_path)


# 返回匹配指定模式的文件路径表
pattern = Path(r"C:\Users\Limou_p350ml9\Desktop\Test")
matched_files = pattern.glob("*.txt")
for file_path in matched_files:
    print(file_path)
# glob() 方法通过匹配指定目录下所有以 .txt 结尾的文件，返回一个生成器。
# 通过迭代生成器，我们可以获取匹配到的每个文件的路径并进行处理。
    
# 返回文件所属组
p = Path('pathTest.py')
# print(p.group()) # 本系统不支持，抛出了 NotImplementedError 异常
# 因为 Windows 不是基于 Unix 的系统，没有像 Unix/Linux 那样的组的概念


# 检查路径是否指向目录或路径
p = Path('pathTest.py')
print(p.is_dir())
print(p.is_file())


# 获取当前目录下的所有子目录和子文件
p = Path(r"C:\Users\Limou_p350ml9\Desktop\Test")
for child in p.iterdir(): 
    print(child)


# 创建/删除 一个 新目录/新文件
# 创建一个路径对象
path = Path('C:/Users/Limou_p350ml9/Desktop/Test/NewFolder')
# 创建目录
path.mkdir()
# 删除目录
path.rmdir() # 目录必须为空，要递归删除目录及其内容，可以使用 shutil.rmtree()，该方法是 shutil 模块的，貌似 pathlib 没有直接提供类似的方法
# 创建文件
file_path = Path(r"C:/Users/Limou_p350ml9/Desktop/Test/new_file.txt")
# 创建文件
file_path.touch()
# 删除文件
file_path.unlink()

# 读取/写入文件
p = Path(r"C:\Users\Limou_p350ml9\Desktop\Test\test_1.txt")
p.write_text('Text file contents') # 以字节写入可用 write_bytes()
print(p.read_text()) # 以字节读取可用 read_bytes（）

# 重命名文件
p = Path('foo')
p.open('w').write('some text')

target = Path('bar')
p.rename(target)

target.open().read()
target.unlink() # 删除该文件

# 返回绝对路径
p = Path('pathTest.py')
print(p.absolute())
p = Path('.')
print(p.resolve())
p = Path('..')
print(p.resolve())

# 判断是否指向相同的文件
p = Path('pathTest.py')
q = Path('test_1.txt')
print(p.samefile(q))


