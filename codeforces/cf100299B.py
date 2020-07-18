
t = int(input())
while(t):
    t -= 1
    sounds = []
    sounds = input().split()
   
    while(True):
        aux = str(input())
        if(aux == "what does the fox say?"):
            break;
        else:
            a, b, c = aux.split()
            while(c in sounds):
                sounds.remove(c)
    first = True
    for i in sounds:
        if (not first):
            print(" ", end='')
        print(i, end='')
        first = False

    print("\n")
