from name_function import get_formatted_name

def test_first_last_name():
    """能否正确调用函数"""
    formatted_name = get_formatted_name('janis', 'joplin')
    assert formatted_name == 'Janis Joplin'

def test_first_middle_last_name():
    """能否正确调用函数"""
    formatted_name = get_formatted_name('janis', 'joplin', 'mozart')
    assert formatted_name == 'Janis Mozart Joplin'