    
def play():
    #read user input
    user_input = input("Do you want to play? (yes/no): ")
    
    if user_input == "yes":
        print("Let's play!")
    else:
        print("Bye!")

def greeting():   
    #read name from user
    name = input("Enter your name: ")
    
    if name == "Salva":
        print("Hello, Salva!")
        play()
    else:
        print(f"{name}? Who are you? get the fuck out of here!")

def main():
    greeting()
    return 0

main()