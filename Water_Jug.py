from collections import deque

def Water_Jug(c1, c2, t):

    q = deque([(0,0,'Intial')])
    visited = set()

    while q:

        for a in q:
            print(" {},".format(a), end='')

        print(" \n -- Poped --  ")

        state = q.popleft()
        a,b,c = state

        if state[0] == t or state[1] == t:
            return state

        if state in visited:
            continue

        visited.add(state)

        # Operations
        ''' Rule 1 : Fill Jug1 
            Rule 2 : Full Jug2
            Rule 3 : Transfer Jug1 to Jug2
            Rule 4 : Transfer Jug2 to Jug1
            Rule 5 : Empty Jug1
            Rule 6 : Empty Jug2'''
        
        if(a==0):
            temp = (c1,b,'R1')
            q.append(temp)

        if(b==0):
            temp = (a,c2,'R2')
            q.append(temp)

        if(b != c2 and a!=0):
            temp = (a-min(a,c2-b), b+min(a,c2-b),'R3')
            q.append(temp)

        if(a != c1 and b!=0):
            temp = (a+min(b,c1-a), b-max(b,c2-b),'R4')
            q.append(temp)

        if(a!=0):
            temp = (0,b,'R5')
            q.append(temp)

        if(b!=0):
            temp = (a,0,'R6')
            q.append(temp)
        
    return None

def main():

    c1 = int(input('Enter the Capacity of Jug1 : '))
    c2 = int(input("Enter the Capacity of Jug2 : "))
    t = int(input("Enter the target Value : "))

    result = Water_Jug(c1,c2,t)

    if(result != None):
        print("Water can be measured && Solution is {}".format(result))
    else:
        print("No Solution Exists")

if __name__ == '__main__':
    main()






        
        