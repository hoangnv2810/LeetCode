import math
def judgeSquareSum(c: int) -> bool:
    for a in range(int(math.sqrt(c))+1):
        b = math.sqrt(c-a*a)
        if b == int(b):
            return True
    return False

def main():
    print("Input: ")
    c = int(input())
    if judgeSquareSum(c) == True:
        print("Yes")
    else:
        print("No")
        
if __name__ == "__main__":
    main()