from database import Add as db_Add
from database import Remove as db_Remove
from database import Search as db_Search
from database import View as db_View

def Add(item):
    return db_Add(item)

def Remove(name):
    return db_Remove(name)

def Search(name):
    return db_Search(name)

def View():
    return db_View()
