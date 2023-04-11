x = int(input())

for i in range(1, x + 1):
    if i == 1 or i == 2 * x:
        print("*" * x + " " * (2 * (x - 1) - 1) + "*" * x)
    elif i != x:
        print(" " * (i - 1) + "*" + " " * (x - 2) + "*" + " " * (2 * (x - i) - 1) + "*" + " " * (x - 2) + "*")
    else:
        print(" " * (i - 1) + "*" + " " * (x - 2) + "*" + " " * (2 * (x - i) - 1) + " " * (x - 2) + "*")

for i in range(x, 0, -1):
    if i == 1 or i == 2 * x:
        print("*" * x + " " * (2 * (x - 1) - 1) + "*" * x)
    elif i != x:
        print(" " * (i - 1) + "*" + " " * (x - 2) + "*" + " " * (2 * (x - i) - 1) + "*" + " " * (x - 2) + "*")