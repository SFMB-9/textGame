def replyBot(WordList):

    if WordList[0] == "Hello":
        return "Hi"
    else:
        return "I don't understand"
    

def textInterpreter(text):
    wordList = text.split()
    return wordList

def main():
    prompt = input("> ")
    replyBot(textInterpreter(prompt))
    return 0

main()