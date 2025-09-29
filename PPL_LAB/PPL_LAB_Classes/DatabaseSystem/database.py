# database=[]
# def add(item):
#     # database.append(item)
#     # print(f"New added Name in Database : {item}")
#     database.append(item)
#     return f"Name '{database['name']}' added successfully."

# def remove(item):
#     database.remove(item)
#     print(f"New added Name in Database : {item}")

# def search(name):
#     for name in database:
#         if name['name'].lower() == name.lower():
#             return name
#     return None


# def view(item):
#     return item in database
# database.py

database = []

def Add(item):
    database.append(item)
    return f"Name '{item['name']}' added successfully."

def Remove(name):
    for student in database:
        if student['name'].lower() == name.lower():
            database.remove(student)
            return f"Name '{name}' removed successfully."
    return f"Name '{name}' not found."

def Search(name):
    for student in database:
        if student['name'].lower() == name.lower():
            return student
    return None

def View():
    return database

