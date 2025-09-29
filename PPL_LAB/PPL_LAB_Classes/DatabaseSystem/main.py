# from utils import Add,Search,View,Remove
# def main():
#     while True:
#         print("Its Database Managemnet System")
#         print("Below Choices To Add,Search,View,Remove of names in Database\n")

#         case=int(input("Enter Your choice {1,2,3,4 :- Add,Search,View,Remove}"))
#         if(case=='1'):
#             Add("str")
#         elif(case=='2'):
#             name=input("Enter what do u want to search")
#             Search(name)
#         elif(case=='3'):
#             view=input("Enter what do u want to view in database")
#         elif(case=='4'):
#             Remove=input("What do u want to remove from database")
#         else:
#             print("So u dont want to do any operations")
# if __name__ == "__main__":
#     main()
from utils import Add, Search, View, Remove

def main():
    while True:
        print("Its Database Managemnet System")
        print("Below Choices To Add, Search, View, Remove of names in Database\n")

        case = int(input("Enter Your choice {1,2,3,4} :- Add, Search, View, Remove: "))

        if case == 1:
            name = input("Enter the name to add: ")
            age = input("Enter the age: ")
            print(Add({"name": name, "age": age}))
        elif case == 2:
            name = input("Enter what do you want to search: ")
            result = Search(name)
            if result:
                print(f"Found: Name: {result['name']}, Age: {result['age']}")
            else:
                print("Student not found.")
        elif case == 3:
            students = View()
            if not students:
                print("No students in database.")
            else:
                for i, s in enumerate(students, 1):
                    print(f"{i}. Name: {s['name']}, Age: {s['age']}")
        elif case == 4:
            name = input("Enter what do you want to remove from database: ")
            print(Remove(name))
        else:
            print("So you don't want to do any operations")
            break

if __name__ == "__main__":
    main()
